#ifndef _RPG_PROTECTION_HPP_
#define _RPG_PROTECTION_HPP_

#include "rpg/visitor/visitable.hpp"
#include "rpg/protections/visitor.hpp"

#include <string>

namespace rpg
{
    struct protection : public rpg::visitor::visitable<rpg::protections::visitor>
    {
    public:
        protection(unsigned int hp) : _hp{hp} {}

        unsigned int hp() const { return _hp; }
        bool is_broken() const { return _hp == 0U; }

        unsigned int take_damages(unsigned int hp)
        {
            auto not_taken_hp{0U};
            if(hp > _hp)
            {
                not_taken_hp = hp - _hp;
                _hp = 0U;
            }
            else
            {
                _hp -= hp;
            }
            return not_taken_hp;
        }
        virtual void repair(unsigned int hp) = 0;

    protected:
        unsigned int _hp;
    };
}

#endif