#ifndef _RPG_CORE_GAME_HPP_
#define _RPG_CORE_GAME_HPP_

#include "rpg/character.hpp"
#include "rpg/capacities/visitors/apply.hpp"

#include "rpg/dice/roller.hpp"

#include <vector>
#include <memory>

namespace rgp::core
{
    template<class Displayer>
    struct game final
    {
    public:
        game(Displayer displayer) : _displayer{std::move(displayer)} {}
        game(game const&) = delete;
        game(game &&) = delete;
        game & operator=(game const&) = delete;
        game & operator=(game &&) = delete;

        void play()
        {
            auto attacker = _displayer.choose_character(1U);
            auto defender = _displayer.choose_character(2U);

            std::vector<std::pair<unsigned int, std::shared_ptr<rpg::character>>> round_queue{
                {0, attacker},
                {1, defender}
            };

            rpg::dice::roller random_dice{};

            unsigned int nb_rounds{0U};
            std::shared_ptr<rpg::character> winner{};
            while(!winner)
            {
                ++nb_rounds;

                _displayer.update_round(nb_rounds);

                for(auto const& character : round_queue)
                {
                    if(std::get<1>(character)->is_dead())
                    {
                        continue;
                    }

                    decltype(round_queue) possible_victims{};
                    possible_victims.reserve(round_queue.size());
                    std::copy_if(
                        round_queue.cbegin(),
                        round_queue.cend(),
                        std::back_inserter(possible_victims),
                        [&character](auto const& c) { return std::get<0>(c) != std::get<0>(character) && !std::get<1>(c)->is_dead(); }
                    );
                    if(possible_victims.empty())
                    {
                        winner = std::get<1>(character);
                        break;
                    }

                    auto victim = possible_victims.front();

                    _displayer.refresh(std::get<1>(character), std::get<1>(victim), nb_rounds);
                    if(std::get<1>(character)->is_stun())
                    {
                        std::get<1>(character)->unstun();
                        _displayer.is_stun(std::get<1>(character));
                        continue;
                    }
                    auto capacity = _displayer.choose_capacity(std::get<1>(character), nb_rounds);
                    rpg::capacities::visitors::apply capacity_applier{std::get<1>(character), std::get<1>(victim)};
                    if(capacity)
                    {
                        capacity->used(nb_rounds);
                        if(random_dice.succeed(capacity->success_rate()))
                        {
                            capacity->accept(capacity_applier);
                            _displayer.capacity_succeed(capacity);
                        }
                        else
                        {
                            _displayer.capacity_failed(capacity);
                        }
                    }
                    else
                    {
                        _displayer.capacity_passed();
                    }

                    _displayer.refresh(std::get<1>(character), std::get<1>(victim), nb_rounds);
                    auto attack_weapon = _displayer.choose_attack(std::get<1>(character));
                    if(attack_weapon)
                    {
                        if(random_dice.succeed(std::get<1>(victim)->agility()))
                        {
                            _displayer.attack_failed(attack_weapon);
                        }
                        else
                        {
                            std::get<1>(victim)->take_damages(attack_weapon->damages());
                            _displayer.attack_succeed(attack_weapon);
                        }
                    }
                    else
                    {
                        _displayer.attack_passed();
                    }

                    auto character_win = !std::any_of(
                        possible_victims.cbegin(),
                        possible_victims.cend(),
                        [](auto const& c) { return !std::get<1>(c)->is_dead(); }
                    );
                    if(character_win)
                    {
                        winner = std::get<1>(character);
                        break;
                    }
                }
            }
            _displayer.win(winner);
        }

    private:
        Displayer _displayer;
    };
}

#endif