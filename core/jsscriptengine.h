#ifndef JSSCRIPTENGINE_H
#define JSSCRIPTENGINE_H

#include <QJSValue>
#include <QObject>

namespace mqg
{
namespace Core
{
class JSScriptEngine : public QObject
{
  Q_OBJECT

public:
  virtual ~JSScriptEngine() = default;

  Q_INVOKABLE virtual void addToEnvironment(const QJSValue &object) = 0;

public slots:
  virtual void evaluate(const QString &program) = 0;

signals:
  void error(const QJSValue &error);
  void success(const QJSValue &result);
};
} // namespace Core
} // namespace mqg

#endif // JSSCRIPTENGINE_H
