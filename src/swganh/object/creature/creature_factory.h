
#ifndef SWGANH_OBJECT_CREATURE_CREATURE_FACTORY_H_
#define SWGANH_OBJECT_CREATURE_CREATURE_FACTORY_H_

#include "swganh/object/object_factory.h"
#include <unordered_map>

namespace anh {
namespace database {
class DatabaseManagerInterface;
}} // anh::database

namespace swganh {
namespace object {
namespace creature {

    class Creature;
    class CreatureFactory : public swganh::object::ObjectFactory
    {
    public:
        CreatureFactory(const std::shared_ptr<anh::database::DatabaseManagerInterface>& db_manager);

        void LoadTemplates();

        bool HasTemplate(const std::string& template_name);

        void PersistObject(const std::shared_ptr<swganh::object::Object>& object);

        void DeleteObjectFromStorage(const std::shared_ptr<swganh::object::Object>& object);

        std::shared_ptr<swganh::object::Object> CreateObjectFromStorage(uint64_t object_id);

        std::shared_ptr<swganh::object::Object> CreateObjectFromTemplate(const std::string& template_name);
    private:
        std::unordered_map<std::string, std::shared_ptr<Creature>>::iterator GetTemplateIter_(const std::string& template_name);
        std::unordered_map<std::string, std::shared_ptr<Creature>> creature_templates_;
    };

}}}  // namespace swganh::object::creature

#endif  // SWGANH_OBJECT_CREATURE_CREATURE_FACTORY_H_
