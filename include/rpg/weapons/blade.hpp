#ifndef _RPG_WEAPONS_BLADE_HPP_
#define _RPG_WEAPONS_BLADE_HPP_

#include "rpg/weapon.hpp"

namespace rpg::weapons
{
    struct blade : public rpg::visitor::visitable_impl<rpg::weapon, blade>
    {
    public:
        blade() : rpg::visitor::visitable_impl<rpg::weapon, blade>{damages()} {}

        unsigned int damages() const { return 5U; }
    };
}

#endif