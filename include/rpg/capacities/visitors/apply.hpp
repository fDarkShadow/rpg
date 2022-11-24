#ifndef _RPG_CAPACITIES_VISITORS_APPLY_HPP_
#define _RPG_CAPACITIES_VISITORS_APPLY_HPP_

#include "rpg/character.hpp"

#include "rpg/capacities/visitor.hpp"

#include "rpg/capacities/charge.hpp"
#include "rpg/capacities/stun.hpp"

#include <memory>
#include <functional>

namespace rpg::capacities::visitors
{
    struct apply : public rpg::capacities::visitor
    {
    public:
        apply(
            std::shared_ptr<rpg::character> attacker,
            std::shared_ptr<rpg::character> victim
        ) :
            _attacker{attacker},
            _victim{victim},
            _backward{[](){}}
        {}
        ~apply()
        {
            _backward();
        }

        void visit(rpg::capacities::charge &) override
        {
            _attacker->weapon()->damages(_attacker->weapon()->damages() * 2U);
            auto attacker = _attacker;
            _backward = [attacker]() { attacker->weapon()->damages(attacker->weapon()->damages() / 2U); };
        }
        void visit(rpg::capacities::stun &) override
        {
            _victim->stun();
        }

    private:
        std::shared_ptr<rpg::character> _attacker;
        std::shared_ptr<rpg::character> _victim;
        std::function<void()> _backward;
    };
}

#endif