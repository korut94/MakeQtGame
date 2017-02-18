#ifndef EVALCONSOLEPLUGIN_H
#define EVALCONSOLEPLUGIN_H

#include "core/libs/containerinterface.h"

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
class EvalConsolePlugin : public QObject, public mqg::libs::ContainerInterface
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID ContainerInterface_iid)
  Q_INTERFACES(mqg::libs::ContainerInterface)

public:
    void saveIn(mqg::Logic::Container::ContainerBook &book) const override;
};
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

#endif // EVALCONSOLEPLUGIN_H
