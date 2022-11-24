#ifndef _RPG_CHARACTER_VISITOR_HPP_
#define _RPG_CHARACTER_VISITOR_HPP_

namespace rpg::characters
{
    struct knight;
    struct orc;

    struct visitor
    {
    public:
        virtual void visit(knight &) = 0;
        virtual void visit(orc &) = 0;
    };
}

#endif