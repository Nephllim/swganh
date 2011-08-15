/*
---------------------------------------------------------------------------------------
This source file is part of SWG:ANH (Star Wars Galaxies - A New Hope - Server Emulator)

For more information, visit http://www.swganh.com

Copyright (c) 2006 - 2011 The SWG:ANH Team
---------------------------------------------------------------------------------------
Use of this source code is governed by the GPL v3 license that can be found
in the COPYING file or at http://www.gnu.org/licenses/gpl-3.0.html

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,a
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
---------------------------------------------------------------------------------------
*/
#ifndef SCRIPT_BINDINGS_TRANSFORM_COMPONENT_BINDING__H_
#define SCRIPT_BINDINGS_TRANSFORM_COMPONENT_BINDING__H_

#include <script_bindings/components/base_component_binding.h>
#include <api/components/transform_component_interface.h>
#include <mod_anh_transform/transform_component.h>

using namespace anh::api::components;
using namespace transform;
using namespace std;
std::shared_ptr<NullTransformComponent> TransformComponentInterface::NullComponent = std::shared_ptr<NullTransformComponent>(new NullTransformComponent());
namespace anh_python { namespace components {

void define_class_transform_component() {
    
    // overloads
    const EntityId      (TransformComponent::*get_parent_id)(void)              = &TransformComponent::parent_id; 
    void                (TransformComponent::*set_parent_id)(const EntityId)    = &TransformComponent::parent_id;
    const glm::vec3&    (TransformComponent::*get_pos)(void)                    = &TransformComponent::position;
    void                (TransformComponent::*set_pos)(const glm::vec3&)        = &TransformComponent::position;
    void (TransformComponent::*set_pos3)(const float, const float, const float) = &TransformComponent::position;
    const glm::quat&    (TransformComponent::*get_rot)(void)                    = &TransformComponent::rotation;
    void                (TransformComponent::*set_rot)(const glm::quat&)        = &TransformComponent::rotation;
    void (TransformComponent::*set_rot4)(const float, const float, const float, const float) = &TransformComponent::rotation;
    const float         (TransformComponent::*get_speed)(void)                  = &TransformComponent::speed;
    void                (TransformComponent::*set_speed)(const float)           = &TransformComponent::speed;
    
    // TODO: add way to get internal TransformComponent based on id
    class_<TransformComponent, boost::noncopyable>("TransformComponent",
        "A component controlling everything about an entities position in the world. \n"
        "@note: It is almost always prefered to get this object from an existing entity Id. "
        "Components use the EntityManager to get a shared_ptr reference to the existing TransformComponent "
        "which relates to the specific ID.",
        init<>())
        .def(init< const glm::vec3&, const glm::quat&, const float >())
        //.def("object_id", &TransformComponent::entity_id, return_value_policy<copy_const_reference>())
        .def("parent_id", get_parent_id)
        .def("parent_id", set_parent_id)
        .def("position", get_pos, return_internal_reference<>(),
        "Gets a L{glm::vec3} of the current position, @returns internal reference.")
        .def("position", set_pos)
        .def("position", set_pos3,
        "Sets position L{glm::vec3} by passing in 3 floats representing x,y,z coordinates of the entity")
        .def("rotation", get_rot, return_internal_reference<>(),
            "Gets a L{glm::quat} of the current entities rotation, @returns internal reference.")
        .def("rotation", set_rot)
        .def("rotation", set_rot4,
            "Sets entities rotation L{glm::quat} by passing in 4 floats representing w,x,y,z rotation of the entity")
        .def("speed", get_speed)
        .def("speed", set_speed)
        .def("rotate", &TransformComponent::rotate,
            "Changes the entities rotation by n-degrees, positive number rotates right, negative rotates left.")
        .def("rotate_left", &TransformComponent::rotate_left,
            "Changes the entities rotation to the left by n-degrees.")
        .def("rotate_right", &TransformComponent::rotate_right,
            "Changes the entities rotation to the right by n-degrees.")
        .def("face", &TransformComponent::face,
            "Makes the entity face the L{glm::vec3} object")
        .def("move", &TransformComponent::move,
            "Moves the entity in the direction of L{glm::quat}, by x meters")
        .def("move_forward", &TransformComponent::move_forward,
            "Moves the entity forward x meters")
        .def("move_back", &TransformComponent::move_back,
            "Moves the entity back x meters")
        .def("rotation_angle", &TransformComponent::rotation_angle,
            "Gets the current rotation object of the entity")
        .def("HandleMessage", &TransformComponent::HandleMessage)
        ;
}

} // components
} // anh_python
#endif // SCRIPT_BINDINGS_TRANSFORM_COMPONENT_BINDING__H_