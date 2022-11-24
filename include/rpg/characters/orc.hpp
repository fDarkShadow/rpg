#ifndef _RPG_CHARACTER_ORC_HPP_
#define _RPG_CHARACTER_ORC_HPP_

#include "rpg/characters/details/crtp.hpp"

#include "rpg/weapon.hpp"
#include "rpg/weapons/axe.hpp"

#include "rpg/protection.hpp"

#include "rpg/capacity.hpp"
#include "rpg/capacities/stun.hpp"

#include <string>
#include <memory>
#include <vector>

namespace rpg::characters
{
    struct orc : public rpg::characters::details::crtp<orc>
    {
    public:
        orc(std::string name) : _name{std::move(name)} {}

        unsigned int max_hp() const { return 60U; }
        std::string const& name() const { return _name; }

        std::shared_ptr<rpg::weapon> default_weapon() const { return std::make_shared<rpg::weapons::axe>(); }
        std::vector<std::shared_ptr<rpg::protection>> default_protections() const { return {}; }
        std::vector<std::shared_ptr<rpg::capacity>> default_capacities() const { return {
            std::make_shared<rpg::capacities::stun>()
        }; }
        unsigned int default_agility() const { return 10; }

    private:
        std::string _name;
    };
}

#endif