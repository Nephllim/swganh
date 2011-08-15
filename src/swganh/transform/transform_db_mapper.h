/*
 This file is part of MMOServer. For more information, visit http://swganh.com
 
 Copyright (c) 2006 - 2011 The SWG:ANH Team

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
#ifndef MOD_ANH_TRANSFORM_TRANFORM_DB_MAPPER_H
#define MOD_ANH_TRANSFORM_TRANFORM_DB_MAPPER_H
#include <anh/component/attribute_mapper_interface.h>
#include "transform_component.h"

namespace anh { namespace database { class DatabaseManagerInterface; } }

namespace swganh {
namespace transform {

class TransformDBMapper : public anh::component::AttributeMapperInterface<TransformComponentInterface>
{
public:
    TransformDBMapper(std::shared_ptr<anh::database::DatabaseManagerInterface> db_manager);
    virtual void Persist(std::shared_ptr<TransformComponentInterface> ref_class);
    virtual void Populate(std::shared_ptr<TransformComponentInterface> component);
    virtual std::shared_ptr<TransformComponentInterface> query_result (uint64_t entity_id);
private:
    std::shared_ptr<anh::database::DatabaseManagerInterface> db_manager_;
};

} // transform
} // swganh

#endif //MOD_ANH_TRANSFORM_TRANFORM_DB_MAPPER_H