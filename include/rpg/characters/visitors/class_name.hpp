#ifndef _RPG_CHARACTERS_VISITORS_CLASS_NAME_HPP_
#define _RPG_CHARACTERS_VISITORS_CLASS_NAME_HPP_

#include "rpg/characters/visitor.hpp"

#include "rpg/characters/knight.hpp"
#include "rpg/characters/orc.hpp"

#include <string>

namespace rpg::characters::visitors
{
    struct class_name : public rpg::characters::visitor
    {
    public:
        void visit(rpg::characters::knight &) override { _name = "knight"; }
        void visit(rpg::characters::orc &) override { _name = "orc"; }

        std::string const& name() const { return _name; }

    private:
        std::string _name;
    };
}

#endif