
#include "swganh/object/guild/guild.h"

#include <sstream>

#include <swganh/object/guild/guild_message_builder.h>

using namespace std;
using namespace swganh::messages;
using namespace swganh::object::guild;

Guild::Guild()
    : Object()
    , guild_list_counter_(0)
{
    SetObjectId(0xDEADBEEF);
    SetTemplate("object/guild/shared_guild_object.iff");
    guild_list_.insert(std::pair<uint32_t, std::string>(1, "SWGANH"));
}

Guild::Guild(std::map<uint32_t, std::string> guild_list)
    : guild_list_(guild_list)
    , guild_list_counter_(0)
{
}

Guild::~Guild()
{
}

void Guild::AddGuild(uint32_t guild_id, std::string guild_tag)
{
    auto iter = guild_list_.find(guild_id);
    if(iter == guild_list_.end())
    {
        std::stringstream guild_id_tag;
        guild_id_tag << guild_id << ":" << guild_tag;

        guild_list_.insert(std::pair<uint32_t, std::string>(guild_id, guild_tag));
       
        GuildMessageBuilder::BuildGuildListDelta(this, 1, guild_id_tag.str());
    }
}

void Guild::RemoveGuild(uint32_t guild_id)
{
    auto iter = guild_list_.find(guild_id);
    if(iter != guild_list_.end())
    {
        std::stringstream guild_id_tag;
        guild_id_tag << iter->first << ":" << iter->second;

        guild_list_.erase(iter);
        
        GuildMessageBuilder::BuildGuildListDelta(this, 0, guild_id_tag.str());
    }
}

boost::optional<BaselinesMessage> Guild::GetBaseline3()
{
    return GuildMessageBuilder::BuildBaseline3(this);
}

boost::optional<BaselinesMessage> Guild::GetBaseline6()
{
    return GuildMessageBuilder::BuildBaseline6(this);
}