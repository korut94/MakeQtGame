#ifndef EXPORTAPPLICATION_H
#define EXPORTAPPLICATION_H

#include "iapplication.h"
#include "pluginfactory.h"

namespace mqg
{
namespace Plugin
{
/*!
 * The ExportApplication class bundles several utility methods to simplify
 * the exportation of an application module.
 *
 * ExportApplication doesn't have own method but it is just an injector
 * of statical methods to make the own external class suitable for the MQG
 * system.
 */
template <typename ConcreteClass>
class ExportApplication
    : public IApplication,
      public PluginFactory<ConcreteClass, IApplication, int, char**>
{
public:
  /*!
   * Throws a ErrorStatusException if \p exitCode is different from 0.
   *
   * This function can be useful when your application implementation
   * implies the returning of a standard exit code.
   */
  static inline void safeReturn(int exitCode);
};

template <typename ConcreteClass>
void ExportApplication<ConcreteClass>::safeReturn(int exitCode) {
  (void) exitCode;
}
} // namespace Plugin
} // namespace mqg

#endif // EXPORTAPPLICATION_H
