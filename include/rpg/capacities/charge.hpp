#ifndef _RPG_CAPACITIES_CHARGE_HPP_
#define _RPG_CAPACITIES_CHARGE_HPP_

#include "rpg/capacity.hpp"

namespace rpg::capacities
{
    struct charge : public rpg::visitor::visitable_impl<rpg::capacity, charge>
    {
    public:
        charge() : rpg::visitor::visitable_impl<rpg::capacity, charge>{max_cooldown(), success_rate()} {}

        unsigned int max_cooldown() const { return 3U; }
        unsigned int success_rate() const { return 60U; }
    };
}

#endif