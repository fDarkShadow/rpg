#ifndef _RPG_PROTECTIONS_DETAILS_CRTP_HPP_
#define _RPG_PROTECTIONS_DETAILS_CRTP_HPP_

#include "rpg/protection.hpp"
#include "rpg/visitor/visitable_impl.hpp"

#include <algorithm>

namespace rpg::protections::details
{
    template<class Derived>
    struct crtp : public rpg::visitor::visitable_impl<rpg::protection, Derived>
    {
    public:
        crtp() :
            rpg::visitor::visitable_impl<rpg::protection, Derived>{
                static_cast<Derived&>(*this).max_hp()
            }
        {}

        void repair(unsigned int hp) override
        {
            rpg::protection::_hp = std::max(static_cast<Derived&>(*this).max_hp(), rpg::protection::_hp + hp);
        }
    };
}

#endif