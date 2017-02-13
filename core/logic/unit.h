#ifndef UNIT_H
#define UNIT_H

#include "abstractlogic.h"

namespace mqg
{
namespace Logic
{
class Unit : public AbstractLogic
{
public:
  Unit();

  void next(AbstractLogic *next);
  void run() override;

private:
  AbstractLogic* getNext() const override;

  AbstractLogic *m_next;
};
} // namespace Logic
} // namespace mqg

#endif // UNIT_H
