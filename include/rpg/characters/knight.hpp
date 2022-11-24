#ifndef _RPG_CHARACTER_KNIGHT_HPP_
#define _RPG_CHARACTER_KNIGHT_HPP_

#include "rpg/characters/details/crtp.hpp"

#include "rpg/weapon.hpp"
#include "rpg/weapons/blade.hpp"

#include "rpg/protection.hpp"
#include "rpg/protections/shield.hpp"

#include "rpg/capacity.hpp"
#include "rpg/capacities/charge.hpp"

#include <string>
#include <memory>
#include <vector>

namespace rpg::characters
{
    struct knight : public rpg::characters::details::crtp<knight>
    {
    public:
        knight(std::string name) : _name{std::move(name)} {}

        unsigned int max_hp() const { return 20U; }
        std::string const& name() const { return _name; }

        std::shared_ptr<rpg::weapon> default_weapon() const { return std::make_shared<rpg::weapons::blade>(); }
        std::vector<std::shared_ptr<rpg::protection>> default_protections() const { return {
            std::make_shared<rpg::protections::shield>()
        }; }
        std::vector<std::shared_ptr<rpg::capacity>> default_capacities() const { return {
            std::make_shared<rpg::capacities::charge>()
        }; }
        unsigned int default_agility() const { return 40; }

    private:
        std::string _name;
    };
}

#endif