#ifndef _RPG_VISITOR_VISITABLE_HPP_
#define _RPG_VISITOR_VISITABLE_HPP_

namespace rpg::visitor
{
    template<class Visitor>
    struct visitable
    {
    public:
        using visitor_type = Visitor;
        virtual void accept(visitor_type & ) = 0;
    };
}

#endif