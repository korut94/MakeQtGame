#include "QtModules/qtguiapplication.h"
#include "QtModules/qtscriptengine.h"

#include <iostream>

int main (int argc, char **argv) {
    using namespace mqg::Service;
    using namespace mqg::module::Qt;

    mqg::IApplication *app = new QtGuiApplication(argc, argv);
    Script::IScriptService *script = new QtScriptEngine();

    script->start();

    app->exec(argc, argv);

    script->stop();

    delete app;
    delete script;

    return 0;
}
