#ifndef BASEPLUGINLOADER_H
#define BASEPLUGINLOADER_H

#include <QPluginLoader>

#include <assert.h>

namespace mqg
{
namespace libs
{
/**
 * @brief A basic function to load the plugins' interface defined in the
 * template parameter. No internal status it's provided therefore any
 * invocation involve in a reloaded of the interface.
 */
template <typename Interface>
struct BasePluginLoader
{
  Interface* load(const QString &path) const
  {
    QPluginLoader loader(path);
    QObject *plugin = loader.instance();

    // TODO: It's needed add some logger object to register the bad path and an
    // exception system.
    assert(plugin != nullptr);

    return qobject_cast<Interface*>(plugin);
  }
};
} // namespace libs
} // namespace mqg

#endif // BASEPLUGINLOADER_H
