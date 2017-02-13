#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include "abstractresourceloader.h"

namespace mqg
{
/**
 * @brief ResourceLoader class realizes the abstract class
 * AbstractResourceLoader.
 */
template <typename Store, typename Loader>
class ResourceLoader : public AbstractResourceLoader<Store, Loader>
{
public:
  explicit ResourceLoader(Store &store, const Loader &loader = Loader());

  decltype(auto)  list()    const;
  bool            load(const QString &resourcePath) override;

private:
  const Loader  &m_load;
  Store         &m_store;
};

template <typename Store, typename Loader>
ResourceLoader<Store, Loader>::ResourceLoader(Store &store,
                                              const Loader &loader)
  : m_load(loader),
    m_store(store) {}

template <typename Store, typename Loader>
decltype(auto) ResourceLoader<Store, Loader>::list() const
{
  return m_store.list();
}

template <typename Store, typename Loader>
bool ResourceLoader<Store, Loader>::load(const QString &resourcePath)
{
  auto resource = m_load(resourcePath);

  if (resource == nullptr) {
    return false;
  } else {
    resource->saveIn(m_store);
    return true;
  }
}
} // namespace mqg

#endif // RESOURCELOADER_H
