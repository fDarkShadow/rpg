#ifndef _RPG_WEAPONS_AXE_HPP_
#define _RPG_WEAPONS_AXE_HPP_

#include "rpg/weapon.hpp"

namespace rpg::weapons
{
    struct axe : public rpg::visitor::visitable_impl<rpg::weapon, axe>
    {
    public:
        axe() : rpg::visitor::visitable_impl<rpg::weapon, axe>{damages()} {}

        unsigned int damages() const { return 8U; }
    };
}

#endif