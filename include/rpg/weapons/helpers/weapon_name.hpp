#ifndef _RPG_WEAPONS_HELPERS_WEAPON_NAME_HPP_
#define _RPG_WEAPONS_HELPERS_WEAPON_NAME_HPP_

#include "rpg/weapons/visitors/weapon_name.hpp"
#include "rpg/weapon.hpp"

#include <string>

namespace rpg::weapons::helpers
{
    struct weapon_name
    {
    public:
        static std::string get(weapon & w)
        {
            rpg::weapons::visitors::weapon_name visitor{};
            w.accept(visitor);
            return visitor.name();
        }
    };
}

#endif