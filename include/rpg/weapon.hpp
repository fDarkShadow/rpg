#ifndef _RPG_WEAPON_HPP_
#define _RPG_WEAPON_HPP_

#include "rpg/visitor/visitable.hpp"
#include "rpg/weapons/visitor.hpp"

namespace rpg
{
    struct weapon : public rpg::visitor::visitable<rpg::weapons::visitor>
    {
    public:
        weapon(unsigned int damages) : _damages{damages} {}

        unsigned int damages() const { return _damages; }
        void damages(unsigned int value) { _damages = value; }

    protected:
        unsigned int _damages;
    };
}

#endif