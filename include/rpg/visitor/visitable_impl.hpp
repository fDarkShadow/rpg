#ifndef _RPG_VISITOR_VISITABLE_IMPL_HPP_
#define _RPG_VISITOR_VISITABLE_IMPL_HPP_

namespace rpg::visitor
{
    template<class Parent, class Derived>
    struct visitable_impl : public Parent
    {
    public:
        template<class ... Args>
        visitable_impl(Args ... args) : Parent{std::move(args)...} {}

        void accept(typename Parent::visitor_type & visitor) override final
        {
            visitor.visit(static_cast<Derived&>(*this));
        }
    };
}

#endif