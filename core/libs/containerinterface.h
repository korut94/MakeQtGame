#ifndef CONTAINERINTERFACE_H
#define CONTAINERINTERFACE_H

#include "../logic/container/containerbook.h"

namespace mqg
{
namespace libs
{
class ContainerInterface
{
public:
  virtual void saveIn(Logic::Container::ContainerBook &book) const = 0;
};
} // namespace libs
} // namespace mqg

#define ContainerInterface_iid "mqg.libs.ContainerInterface"
Q_DECLARE_INTERFACE(mqg::libs::ContainerInterface, ContainerInterface_iid)

#endif // CONTAINERINTERFACE_H
