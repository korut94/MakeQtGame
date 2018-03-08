#ifndef SERVICES_H
#define SERVICES_H

namespace mqg
{
namespace Service
{
namespace Script { class IScriptService; }
/*!
 * The Services struct is a simple collection of the providers for each mqg's
 * services.
 */
struct Services
{
    /*!
     * Pointer to the Scripting service provider.
     */
    const Script::IScriptService *script;
};
} // namespace Service
} // namespace mqg

#endif // SERVICES_H
