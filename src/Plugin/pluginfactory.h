#ifndef PLUGINFACTORY_H
#define PLUGINFACTORY_H

namespace mqg
{
namespace Plugin
{
/*!
 * The PluginFactory class injects the interface to create an external class
 * declared inside a plugin.
 *
 * PluginFactory has three template parameters which driving the create method:
 * - InstanceType: the concrete type of the class to create
 * - Interface: the mqg's interface to return (e.g. IApplication or IService)
 * - Args: the list of arguments of the InstanceType constructor
 */
template <typename InstanceType,
          typename Interface,
          typename... Args>
class PluginFactory
{
public:
  /*!
   * Returns an instance of InstanceType class
   */
  static Interface* create(Args... arguments);
};

template <typename InstanceType, typename Interface, typename... Args>
Interface*
PluginFactory<InstanceType, Interface, Args...>::create(Args... arguments) {
  // TODO: check if ConcreteClass is a subclass of Interface
  return new InstanceType(arguments...);
}
} // namespace Plugin
} // namespace mqg

#endif // PLUGINFACTORY_H
