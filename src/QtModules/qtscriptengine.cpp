#include "qtscriptengine.h"

namespace mqg
{
namespace module
{
namespace Qt
{
void QtScriptEngine::buildScriptingEnvironment(
        IApplication *app,
        const Service::Services &services) {

}

void QtScriptEngine::start() {
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

void QtScriptEngine::stop() {}
} // namespace Qt
} // namespace module
} // namespace mqg
