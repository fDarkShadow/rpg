#ifndef _RPG_PROTECTIONS_SHIELD_HPP_
#define _RPG_PROTECTIONS_SHIELD_HPP_

#include "rpg/protections/details/crtp.hpp"

namespace rpg::protections
{
    struct shield : public rpg::protections::details::crtp<shield>
    {
    public:
        shield() = default;

        unsigned int max_hp() const { return 50U; }
    };
}

#endif