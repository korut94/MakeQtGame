#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

namespace mqg
{
class BackEnd : public QObject
{
  Q_OBJECT

public:
  explicit BackEnd(QObject *parent = nullptr);

public slots:
  void evaluate(const QString &program);
};
} // namespace mqg

#endif // BACKEND_H
