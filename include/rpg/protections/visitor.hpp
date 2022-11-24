#ifndef _RPG_PROTECTIONS_VISITOR_HPP_
#define _RPG_PROTECTIONS_VISITOR_HPP_

namespace rpg::protections
{
    struct shield;

    struct visitor
    {
    public:
        virtual void visit(shield &) = 0;
    };
}

#endif