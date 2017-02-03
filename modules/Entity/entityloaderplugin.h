#ifndef ENTITYLOADERPLUGIN_H
#define ENTITYLOADERPLUGIN_H

#include <QObject>

#include "core/entityinterface.h"

namespace mqggame
{
class EntityLoaderPlugin : public QObject,
                           public mqg::libs::EntityLoaderInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID EntityLoaderInterface_iid)
  Q_INTERFACES(mqg::libs::EntityLoaderInterface)

public:
  void load(mqg::Entity::IDispatcherEntity &dispatcher) const;
};
} // namespace mqggame

#endif // ENTITYLOADERPLUGIN_H
