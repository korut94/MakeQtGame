#include <assert.h>

#include "abstractlogic.h"

namespace mqg
{
namespace Logic
{
void AbstractLogic::startContainer()
{
  AbstractLogic* current = this;

  while (current != nullptr) {
    current->run();
    current = current->getNext();
  }
}
} // namespace Logic
} // namespace mqg
