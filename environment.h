#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QJSEngine>

namespace mqg
{
namespace Core
{
//! The Environment class stores the properties declared by the user to rich
//! the script environment.
/*!
  The Environment class
 */
class Environment : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString prefix READ prefix WRITE setPrefix)

public:
  explicit Environment(QObject *parent = nullptr);

  const QString&  prefix() const;
  void            loadContext(QJSEngine *engine) const;
  void            setPrefix(const QString &prefix);

private:
  QString m_prefix;
};
} // namespace Core
} // namespace mqg

#endif // ENVIRONMENT_H
