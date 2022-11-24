#ifndef _RPG_CHARACTER_HPP_
#define _RPG_CHARACTER_HPP_

#include "rpg/visitor/visitable.hpp"
#include "rpg/characters/visitor.hpp"

#include "rpg/weapon.hpp"
#include "rpg/protection.hpp"
#include "rpg/capacity.hpp"

#include <string>
#include <memory>
#include <vector>
#include <algorithm>

namespace rpg
{
    struct character : public rpg::visitor::visitable<rpg::characters::visitor>
    {
    public:
        character(
            unsigned int max_hp,
            std::shared_ptr<rpg::weapon> weapon,
            std::vector<std::shared_ptr<rpg::protection>> protections,
            std::vector<std::shared_ptr<rpg::capacity>> capacities,
            unsigned int agility
        ) :
            _hp{max_hp},
            _weapon{weapon},
            _protections{std::move(protections)},
            _capacities{std::move(capacities)},
            _is_stun{false},
            _agility{agility}
        {}

        unsigned int hp() const { return _hp; }
        bool is_dead() const { return _hp == 0U; }

        bool is_stun() const { return _is_stun; }
        void stun() { _is_stun = true; }
        void unstun() { _is_stun = false; }

        unsigned int agility() const { return _agility; }

        std::shared_ptr<rpg::weapon> weapon() const { return _weapon; }
        std::shared_ptr<rpg::weapon> weapon() { return _weapon; }
        std::vector<std::shared_ptr<rpg::protection>> const& protections() const { return _protections; }
        std::vector<std::shared_ptr<rpg::protection>> & protections() { return _protections; }
        std::vector<std::shared_ptr<rpg::capacity>> const& capacities() const { return _capacities; }
        std::vector<std::shared_ptr<rpg::capacity>> & capacities() { return _capacities; }

        virtual void take_damages(unsigned int hp)
        {
            auto protection_it = std::find_if_not(
                _protections.cbegin(),
                _protections.cend(),
                [](auto protection) { return protection->is_broken(); }
            );
            if(protection_it != _protections.cend())
            {
                hp = (*protection_it)->take_damages(hp);
            }
            if(hp > _hp)
            {
                _hp = 0U;
            }
            else
            {
                _hp -= hp;
            }
        }
        virtual void heal(unsigned int hp) = 0;
        virtual std::string const& name() const = 0;

    protected:
        unsigned int _hp;
        std::shared_ptr<rpg::weapon> _weapon;
        std::vector<std::shared_ptr<rpg::protection>> _protections;
        std::vector<std::shared_ptr<rpg::capacity>> _capacities;
        bool _is_stun;
        unsigned int _agility;
    };
}

#endif