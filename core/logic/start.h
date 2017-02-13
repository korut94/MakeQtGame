#ifndef START_H
#define START_H

#include "abstractlogic.h"
#include <QDebug>

namespace mqg
{
namespace Logic
{
void start(AbstractLogic *starter)
{
  AbstractLogic* &current = starter;

  while (current != nullptr) {
    current->run();
    current = current->getNext();
  }
}
} // namespace Logic
} // namespace mqg

#endif // START_H
