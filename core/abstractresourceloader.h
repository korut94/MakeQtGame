#ifndef ABSTRACTRESOURCELOADER_H
#define ABSTRACTRESOURCELOADER_H

#include <QString>

namespace mqg
{
/**
 * @brief AbstractResourceLoader class is an abstraction for loader that
 * reaches the resources by their path rappresented as a string. The resource
 * just loaded will stored in a Store (the first template paramenter defines
 * it) leaving the ResourceLoader free from the effort of searching a common
 * structure where put the Loader's accepted resources type. About the Loader
 * (the second template parameter), it has to be intent like the algorithm to
 * fetch the resource, provide an its instantiation and throw an exception when
 * an errors has been arised. For this reason, the use of function object is
 * encouraged.
 */
template <typename Store, typename Loader>
class AbstractResourceLoader
{
public:
  /**
   * @brief The method shoud instantiates the resource specified by the Loader
   * and stores it into the Store.
   * @param The path where the resources can be find.
   * @return  Return true if the load is performed successfully,
   * false otherwise.
   */
  virtual bool load(const QString &resourcePath) = 0;
};
} // namespace mqg

#endif // ABSTRACTRESOURCELOADER_H
