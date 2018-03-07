#ifndef IAPPLICATION_H
#define IAPPLICATION_H

namespace mqg
{
/*!
 * \brief The IApplication class
 */
class IApplication
{
public:
    virtual int exec() = 0;
};
} // namespace mqg

#endif // IAPPLICATION_H
