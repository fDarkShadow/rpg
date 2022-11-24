#ifndef _RPG_CHARACTERS_HELPERS_CLASS_NAME_HPP_
#define _RPG_CHARACTERS_HELPERS_CLASS_NAME_HPP_

#include "rpg/characters/visitors/class_name.hpp"
#include "rpg/character.hpp"

#include <string>

namespace rpg::characters::helpers
{
    struct class_name
    {
    public:
        static std::string get(character & c)
        {
            rpg::characters::visitors::class_name visitor{};
            c.accept(visitor);
            return visitor.name();
        }
    };
}

#endif