/******************************************************************************
 * MakeQtGame
 * Copyright (C) 2017 Andrea Mantovani
 *
 * This file is part of MakeQtGame
 *
 * MakeQtGame is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MakeQtGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MakeQtGame. If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#include "application.h"
#include "jsengineadapterforqt.h"
#include "messageadapterforqt.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace mqg::Core;

static QObject* app_provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine);

  JSEngineAdapterForQt *script = new JSEngineAdapterForQt(scriptEngine);
  MessageAdapterForQt *message = new MessageAdapterForQt();

  message->installAsQtMessageHandler();

  Application::provide(script);
  Application::provide(message);

  return &Application::instance();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<Message>("Message");
    qmlRegisterSingletonType<Application>("mqg.Core.Application", 1,0,
                                          "App", app_provider);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
