#ifndef ENGINE_H
#define ENGINE_H

#include <QJSValue>
#include <QObject>

namespace mqg
{
class Engine : public QObject
{
  Q_OBJECT

public:
  explicit Engine(QObject *parent = nullptr);

  Q_INVOKABLE void setGlobalObject(const QString &objectName,
                                   QObject *object) const;

public slots:
  void evaluate(const QString &program);

signals:
  void errorOccurred(const QJSValue &error);
};
} // namespace mqg

#endif // ENGINE_H
