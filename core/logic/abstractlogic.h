#ifndef ABSTRACTLOGIC_H
#define ABSTRACTLOGIC_H

namespace mqg
{
namespace Logic
{
class AbstractLogic
{
public:
  virtual ~AbstractLogic() {}

  virtual AbstractLogic*  getNext() const = 0;
  virtual void            run()           = 0;

protected:
  void startContainer();
};
} // namespace Logic
} // namespace mqg

#endif // ABSTRACTLOGIC_H
