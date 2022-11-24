#ifndef _RPG_CHARACTERS_DETAILS_CRTP_HPP_
#define _RPG_CHARACTERS_DETAILS_CRTP_HPP_

#include "rpg/character.hpp"
#include "rpg/visitor/visitable_impl.hpp"

#include <algorithm>

namespace rpg::characters::details
{
    template<class Derived>
    struct crtp : public rpg::visitor::visitable_impl<rpg::character, Derived>
    {
    public:
        crtp() :
            rpg::visitor::visitable_impl<rpg::character, Derived>{
                static_cast<Derived&>(*this).max_hp(),
                static_cast<Derived&>(*this).default_weapon(),
                static_cast<Derived&>(*this).default_protections(),
                static_cast<Derived&>(*this).default_capacities(),
                static_cast<Derived&>(*this).default_agility()
            }
        {}

        void heal(unsigned int hp) override
        {
            rpg::character::_hp = std::max(static_cast<Derived&>(*this).max_hp(), rpg::character::_hp + hp);
        }
        std::string const& name() const override
        {
            return static_cast<Derived const&>(*this).name();
        }
    };
}

#endif