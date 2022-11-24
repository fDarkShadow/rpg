#ifndef _RPG_CAPACITIES_STUN_HPP_
#define _RPG_CAPACITIES_STUN_HPP_

#include "rpg/capacity.hpp"

namespace rpg::capacities
{
    struct stun : public rpg::visitor::visitable_impl<rpg::capacity, stun>
    {
    public:
        stun() : rpg::visitor::visitable_impl<rpg::capacity, stun>{max_cooldown(), success_rate()} {}

        unsigned int max_cooldown() const { return 5U; }
        unsigned int success_rate() const { return 100U; }
    };
}

#endif