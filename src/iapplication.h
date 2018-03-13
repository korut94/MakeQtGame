#ifndef IAPPLICATION_H
#define IAPPLICATION_H

namespace mqg
{
/*!
 * The IApplication interface defines the basic behaviors of an application.
 *
 * The concrete implementation of the IApplication interface has to provide the
 * logic on how the user interacts with the application itself.
 *
 * This is to guarantee the flexibility required to reuse as much as possible
 * the utilities implemented around a product and enforce the same way of work
 * to design and build each of them. In the mqg context, this is translated in
 * make several services features and sharing them across the software
 * ecosystem which define different IApplication implementations depending on
 * the use case (maybe one for GUI tools, one for command line tools, etc.).
 */
class IApplication
{
public:
    virtual ~IApplication() {}
    /*!
     * Runs tha application passing the optional arguments by \p argc and \p
     * argv.
     *
     * The exec method doesn't return any status code at the end of the
     * execution, indeed insine the mqg's main the invokation to the exec
     * method is wrapped by a try-catch statement.
     *
     * In case you are using some libraries that imply the returning of an exit
     * code, invoke handleExitCode with the returned value.
     */
    virtual void exec(int argc, char **argv) = 0;
};
} // namespace mqg

#endif // IAPPLICATION_H
