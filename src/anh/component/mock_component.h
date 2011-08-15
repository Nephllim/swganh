/*
 This file is part of MMOServer. For more information, visit http://swganh.com
 
 Copyright (c) 2006 - 2010 The SWG:ANH Team

 MMOServer is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 MMOServer is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with MMOServer.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ANH_COMPONENT_MOCK_COMPONENT_H_
#define ANH_COMPONENT_MOCK_COMPONENT_H_

#include <gmock/gmock.h>
#include <anh/component/component_interface.h>
#include <anh/component/attribute_mapper_interface.h>

// Generate mock Component.

namespace anh {
namespace component {

class NullMockComponent;

class MockComponentInterface : public ComponentInterface {
public:
    static std::shared_ptr<NullMockComponent> NullComponent;
};

class NullMockComponent : public MockComponentInterface {
public:
    NullMockComponent() 
    : type_("NullMock")
    , interface_("Mock") { }

    virtual ~NullMockComponent() { }

    void Init(boost::property_tree::ptree& pt) { }
    void OnAttach() { }
    void OnDetach() { }
    void Update(const float deltaMilliseconds) { }
    void HandleMessage(const Message message) { }
    std::shared_ptr<Entity> entity(void) { return entity_.lock(); }
    void set_entity(std::shared_ptr<Entity> e) { }
    void set_dirty(bool dirty) { dirty_ = dirty; }
    bool dirty() { return dirty_; }
    std::shared_ptr<anh::component::AttributeMapperInterface<ComponentInterface>> attribute_mapper() { return attribute_mapper_; }
    void set_attribute_mapper(std::shared_ptr<anh::component::AttributeMapperInterface<ComponentInterface>> mapper) {}
    const ComponentType& component_type() { return type_; }
    const InterfaceType& interface_type() { return interface_; }

    ComponentType type_;
    InterfaceType interface_;
    std::weak_ptr<Entity> entity_;
    std::shared_ptr<anh::component::AttributeMapperInterface<ComponentInterface>> attribute_mapper_;
    bool dirty_;
};

class MockComponent : public MockComponentInterface {
public:
    MockComponent() 
    : type_("Anh.Mock")
    , interface_("Mock") { }

    virtual ~MockComponent() { }

    MOCK_METHOD1(Init, void (boost::property_tree::ptree& pt));
    MOCK_METHOD0(OnAttach, void ());
    MOCK_METHOD0(OnDetach, void ());
    MOCK_METHOD1(Update, void (const float deltaMilliseconds));
    MOCK_METHOD1(HandleMessage, void (const Message message));
    MOCK_METHOD0(entity, std::shared_ptr<Entity> ());
    MOCK_METHOD1(set_entity, void (std::shared_ptr<Entity> e));
    MOCK_METHOD1(set_dirty, void(bool dirty));
    MOCK_METHOD0(dirty, bool());
    MOCK_METHOD0(attribute_mapper, std::shared_ptr<anh::component::AttributeMapperInterface<ComponentInterface>>());
    MOCK_METHOD1(set_attribute_mapper, void(std::shared_ptr<anh::component::AttributeMapperInterface<ComponentInterface>> mapper));

    const ComponentType& component_type() { return type_; }
    const InterfaceType& interface_type() { return interface_; }

    ComponentType type_;
    InterfaceType interface_;
};
class MockAttributeMapper : public anh::component::AttributeMapperInterface<ComponentInterface> {
public:
    MOCK_METHOD1(Persist, void(std::shared_ptr<ComponentInterface> comp));
    MOCK_METHOD1(Populate, void(std::shared_ptr<ComponentInterface> comp));
    MOCK_METHOD1(query_result, std::shared_ptr<ComponentInterface>(uint64_t entity_id));
};

} // namespace component
} // namespace anh

#endif // ANH_COMPONENT_MOCK_COMPONENT_H_