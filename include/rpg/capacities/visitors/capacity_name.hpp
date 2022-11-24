#ifndef _RPG_CAPACITIES_VISITORS_CAPACITY_NAME_HPP_
#define _RPG_CAPACITIES_VISITORS_CAPACITY_NAME_HPP_

#include "rpg/capacities/visitor.hpp"

#include "rpg/capacities/charge.hpp"
#include "rpg/capacities/stun.hpp"

#include <string>

namespace rpg::capacities::visitors
{
    struct capacity_name : public rpg::capacities::visitor
    {
    public:
        void visit(rpg::capacities::charge &) override { _name = "charge"; }
        void visit(rpg::capacities::stun &) override { _name = "stun"; }

        std::string const& name() const { return _name; }

    private:
        std::string _name;
    };
}

#endif