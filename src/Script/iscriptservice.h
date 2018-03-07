#ifndef ISCRIPTSERVICE_H
#define ISCRIPTSERVICE_H

#include "../iapplication.h"
#include "../Service/iservice.h"

namespace mqg
{

class Services;

namespace Service
{
namespace Script
{
/*!
 * The IScriptService interface defines the basic operations for a service
 * that provides the scripting layer.
 *
 * In mqg the role of the scripting services is create a layer on the top of
 * the C++ application to make each services able to comunicate with each
 * other.
 *
 * On the basic level, the services are isolated and no comunication is
 * done to avoid possible dangerous dependencies between them that should be
 * lead in a lack on the modularization. In fact the scripting layer has to act
 * as middleware to catch the user's commands and translate them in a sequence
 * of calls to the C++ APIs of the under layer so the services can be
 * coordinated in completely safe way.
 *
 * Moreover the scripting environment is a good place to define facilities not
 * already offered by the native services' interface.
*/
class IScriptService : public IService {
public:
    /*!
     * Builds the scripting environment providing an access to \p app and all
     * the services pointed by the collection \p services.
     *
     * The choice of the language and the way to integrate the different
     * services is completed left to the concrete implementation of the
     * IScriptService and mqg doesn't make any assumption.
     */
    virtual void buildScriptingEnvironment(IApplication *app,
                                           const Services &services) = 0;
};
} // namespace Script
} // namespace Service
} // namespace mqg

#endif // ISCRIPTSERVICE_H
