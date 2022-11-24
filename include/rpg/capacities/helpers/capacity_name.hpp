#ifndef _RPG_CAPACITIES_HELPERS_CAPACITY_NAME_HPP_
#define _RPG_CAPACITIES_HELPERS_CAPACITY_NAME_HPP_

#include "rpg/capacities/visitors/capacity_name.hpp"
#include "rpg/capacity.hpp"

#include <string>

namespace rpg::capacities::helpers
{
    struct capacity_name
    {
    public:
        static std::string get(capacity & c)
        {
            rpg::capacities::visitors::capacity_name visitor{};
            c.accept(visitor);
            return visitor.name();
        }
    };
}

#endif