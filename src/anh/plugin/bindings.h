
#ifndef ANH_PLUGIN_BINDINGS_H_
#define ANH_PLUGIN_BINDINGS_H_

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "anh/app/kernel_interface.h"

namespace anh {
namespace plugin {
    
struct ObjectParams {
    std::string name;
    std::shared_ptr<anh::app::KernelInterface> kernel;
};

typedef std::function<void * (ObjectParams*)> ObjectCreator;
typedef std::function<void (void *)> ObjectDestroyer;

struct ObjectRegistration {
    anh::app::Version version;
    ObjectCreator CreateObject;
    ObjectDestroyer DestroyObject;
};

typedef void (*ExitFunc)();
typedef ExitFunc (*InitFunc)(std::shared_ptr<anh::app::KernelInterface>, std::vector<std::string> args);

#ifdef WIN32
    #ifdef DLL_EXPORTS
        #define PLUGIN_API __declspec(dllexport)
    #else
        #define PLUGIN_API __declspec(dllimport)
    #endif
#else
    #define PLUGIN_API 
#endif

extern
#ifdef __cplusplus
    "C"
#endif
PLUGIN_API ExitFunc InitializePlugin(std::shared_ptr<anh::app::KernelInterface> binding, std::vector<std::string> args);

}}  // namespace anh::plugin

#endif  // ANH_PLUGIN_BINDINGS_H_
