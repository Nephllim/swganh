#include <api/components/container_component_interface.h>
#include <api/container_permissions_interface.h>
#include <anh/component/entity.h>

using namespace anh::api;
using namespace anh::api::components;

//Setup the Null Container
std::shared_ptr<NullContainerComponent> ContainerComponentInterface::NullComponent = std::make_shared<NullContainerComponent>();
std::shared_ptr<NullContainerPermission> NullContainerComponent::null_permissions = std::make_shared<NullContainerPermission>();