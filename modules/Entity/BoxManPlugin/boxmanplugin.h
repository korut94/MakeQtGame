#ifndef BOXMANPLUGIN_H
#define BOXMANPLUGIN_H

#include <QObject>

#include "core/entityinterface.h"
#include "core/entitybook.h"

namespace mqggame
{
namespace Entity
{
namespace BoxMan
{
class BoxManPlugin : public QObject, public mqg::libs::EntityInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID EntityInterface_iid)
  Q_INTERFACES(mqg::libs::EntityInterface)

public:
  void saveIn(mqg::Entity::EntityBook &book) const override;
};
} // namespace BoxMan
} // namespace Entity
} // namespace mqggame

#endif // BOXMANPLUGIN_H
