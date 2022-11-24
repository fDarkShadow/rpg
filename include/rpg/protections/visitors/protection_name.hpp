#ifndef _RPG_PROTECTIONS_VISITORS_PROTECTION_NAME_HPP_
#define _RPG_PROTECTIONS_VISITORS_PROTECTION_NAME_HPP_

#include "rpg/protections/visitor.hpp"

#include "rpg/protections/shield.hpp"

#include <string>

namespace rpg::protections::visitors
{
    struct protection_name : public rpg::protections::visitor
    {
    public:
        void visit(rpg::protections::shield &) override { _name = "shield"; }

        std::string const& name() const { return _name; }

    private:
        std::string _name;
    };
}

#endif