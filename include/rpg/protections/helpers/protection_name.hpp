#ifndef _RPG_PROTECTIONS_HELPERS_PROTECTION_NAME_HPP_
#define _RPG_PROTECTIONS_HELPERS_PROTECTION_NAME_HPP_

#include "rpg/protections/visitors/protection_name.hpp"
#include "rpg/protection.hpp"

#include <string>

namespace rpg::protections::helpers
{
    struct protection_name
    {
    public:
        static std::string get(protection & p)
        {
            rpg::protections::visitors::protection_name visitor{};
            p.accept(visitor);
            return visitor.name();
        }
    };
}

#endif