#ifndef QTSCRIPTENGINE_H
#define QTSCRIPTENGINE_H

#include "Script/iscriptservice.h"

#include <QQmlApplicationEngine>

namespace mqg
{
namespace module
{
namespace Qt
{
/*!
 * \brief The QtScriptEngine class
 */
class QtScriptEngine : public Service::Script::IScriptService
{
private:
    QQmlApplicationEngine m_engine;

public:
    void buildScriptingEnvironment(IApplication *app,
                                   const Service::Services &services);
    void start();
    void stop();
};
} // namespace Qt
} // namespace module
} // namespace mqg

#endif // QTSCRIPTENGINE_H
