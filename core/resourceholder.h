#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <QString>

namespace mqg
{
/**
 * @brief ResourceHolder class allow the instantiation of a resource reachable
 * by a string. The resource just loaded will stored in a Store (the first
 * template paramenter) leaving the ResourceHolder free from the
 * effort of searching a common structure where put the Loader's accepted
 * resources type. About the Loader (the second template parameter), it has to
 * be intent like the algorithm to fetch the resource, provides a way to
 * instantiate it in a second time and to throw an exception when an error has
 * been arised. For this reason, the use of function object is encouraged.
 */
template <typename Store, typename Loader>
class ResourceHolder
{
public:
  ResourceHolder();

  // To replace with method lookup where the returend type is the factory
  // keeped by the Store
  template <typename... Args>
  decltype(auto)  create(const QString &resource, Args... arguments);
  decltype(auto)  list() const;
  /**
   * @brief The method shoud instantiates the resource specified by the Loader
   * and stores it into the Store.
   * @param The path where the resources can be find.
   * @return  Return true if the load is performed successfully,
   * false otherwise.
   */
  bool            load(const QString &resourcePath);

private:
  const Loader  m_loader;
  Store         m_store;
};

template <typename Store, typename Loader>
ResourceHolder<Store, Loader>::ResourceHolder()
  : m_loader(),
    m_store() {}

template <typename Store, typename Loader>
template <typename... Args>
decltype(auto) ResourceHolder<Store, Loader>::create(const QString &resource,
                                                     Args... arguments)
{
  return m_store.create(resource, arguments...);
}

template <typename Store, typename Loader>
decltype(auto) ResourceHolder<Store, Loader>::list() const
{
  return m_store.list();
}

template <typename Store, typename Loader>
bool ResourceHolder<Store, Loader>::load(const QString &resourcePath)
{
  auto resource = m_loader.load(resourcePath);

  if (resource == nullptr) {
    return false;
  } else {
    resource->saveIn(m_store);
    return true;
  }
}
} // namespace mqg

#endif // RESOURCEHOLDER_H
