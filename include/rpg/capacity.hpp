#ifndef _RPG_CAPACITY_HPP_
#define _RPG_CAPACITY_HPP_

#include "rpg/visitor/visitable.hpp"
#include "rpg/capacities/visitor.hpp"

namespace rpg
{
    struct capacity : public rpg::visitor::visitable<rpg::capacities::visitor>
    {
    public:
        capacity(unsigned int max_cooldown, unsigned int success_rate) : _max_cooldown{max_cooldown}, _last_round_nb{0U}, _success_rate{success_rate} {}

        unsigned int max_cooldown() const { return _max_cooldown; }
        unsigned int cooldown(unsigned int round_nb) const { return _last_round_nb == 0U ? 0U : _max_cooldown + _last_round_nb - round_nb + 1U; }
        bool can_use(unsigned int round_nb) const { return _last_round_nb == 0U || round_nb - _last_round_nb > _max_cooldown; }

        void used(unsigned int round_nb) { _last_round_nb = round_nb; }

        unsigned int success_rate() const { return _success_rate; }

    protected:
        unsigned int _max_cooldown;
        unsigned int _last_round_nb;
        unsigned int _success_rate;
    };
}

#endif