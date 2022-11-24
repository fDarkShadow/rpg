#ifndef _RPG_WEAPONS_VISITOR_HPP_
#define _RPG_WEAPONS_VISITOR_HPP_

namespace rpg::weapons
{
    struct axe;
    struct blade;

    struct visitor
    {
    public:
        virtual void visit(axe &) = 0;
        virtual void visit(blade &) = 0;
    };
}

#endif