#ifndef ISERVICE_H
#define ISERVICE_H

namespace mqg
{
namespace Service
{
/*!
 * The IService interface defines the basic behavior of a service.
 *
 * Basically any service has two steps: the initialization, where the service
 * can initialize the own resources, and the interruption, where the resources
 * can be relesead. This two steps are mapped onto the method start() and
 * stop() rispectively.
 *
 * Very important is that a service should be not care about updating its state
 * by itself: indeed, the service providing a suitable set of API will be
 * updated by the IApplication logic emitting signals that, invoking the
 * binded function, move forward the service's state.
 */
class IService
{
public:
    /*!
     * Implement this function to initialize the resources that provide your
     * service.
     *
     * The method start() is invoked during the start up of the application and
     * provides you a right place to initialize attributes of your concrete
     * service.
     *
     * It's crucial avoid any kind of logical computation here: the system
     * waits that any service is ready, so less time is spent during the start
     * up more reactive the application will be.
     */
    virtual void start() = 0;
    /*!
     * Implement this function to deallocate the resources of your service.
     *
     * The method stop() is invoked when the system requires the shut down of
     * a specific service (cause either for the application end or for an
     * error) and provides you a right place to close it cleanly.
     *
     * In any case stop() doesn't have to handle errors (both coming from the
     * service itself that outside) but just flush out all the potential
     * garbage that can be lead in a instability of the system.
     *
     * All the error management phase is encourage to be service specific by
     * ad hoc mechanisms.
     */
    virtual void stop() = 0;
};
} // namespace Service
} // namespace mqg

#endif // ISERVICE_H
