#ifndef _RPG_WEAPONS_VISITORS_WEAPON_NAME_HPP_
#define _RPG_WEAPONS_VISITORS_WEAPON_NAME_HPP_

#include "rpg/weapons/visitor.hpp"

#include "rpg/weapons/axe.hpp"
#include "rpg/weapons/blade.hpp"

#include <string>

namespace rpg::weapons::visitors
{
    struct weapon_name : public rpg::weapons::visitor
    {
    public:
        void visit(rpg::weapons::axe &) override { _name = "axe"; }
        void visit(rpg::weapons::blade &) override { _name = "blade"; }

        std::string const& name() const { return _name; }

    private:
        std::string _name;
    };
}

#endif