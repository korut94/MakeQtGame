#ifndef ISCRIPTSERVICE_H
#define ISCRIPTSERVICE_H

#include "../Service/iservice.h"

namespace mqg
{
namespace Service
{
namespace Script
{
class IScriptService : public IService {
public:
    virtual void buildScriptingEnvironment(const Services &services) = 0;
};
} // namespace Script
} // namespace Service
} // namespace mqg

#endif // ISCRIPTSERVICE_H
