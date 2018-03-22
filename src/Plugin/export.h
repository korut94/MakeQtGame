#ifndef EXPORT_H
#define EXPORT_H

#include "exportapplication.h"

#include <boost/dll/alias.hpp>

#ifndef MQG_EXPORT
#define MQG_EXPORT(name_class) BOOST_DLL_ALIAS(name_class::create, create)
#endif

#endif // EXPORT_H
