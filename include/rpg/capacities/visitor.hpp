#ifndef _RPG_CAPACITIES_VISITOR_HPP_
#define _RPG_CAPACITIES_VISITOR_HPP_

namespace rpg::capacities
{
    struct charge;
    struct stun;

    struct visitor
    {
    public:
        virtual void visit(charge &) = 0;
        virtual void visit(stun &) = 0;
    };
}

#endif