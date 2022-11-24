#ifndef _RPG_DISPLAY_CONSOLE_HPP_
#define _RPG_DISPLAY_CONSOLE_HPP_

#include "rpg/character.hpp"
#include "rpg/characters/knight.hpp"
#include "rpg/characters/orc.hpp"
#include "rpg/characters/helpers/class_name.hpp"

#include "rpg/weapons/helpers/weapon_name.hpp"

#include "rpg/protections/helpers/protection_name.hpp"

#include "rpg/capacities/helpers/capacity_name.hpp"

#include <vector>
#include <memory>

#include <iostream>

namespace rpg::display
{
    struct console final
    {
    public:
        std::shared_ptr<rpg::character> choose_character(unsigned int player_nb)
        {
            std::cout << "Player " << player_nb << " : choose your characer\n";
            std::cout << tabulation() << "1 - knight\n";
            std::cout << tabulation() << "2 - orc\n";
            std::cout << "Character choice number : ";
            std::string input{};
            std::getline(std::cin, input);
            unsigned int input_number{0U};
            try
            {
                input_number = std::stoul(input);
            }
            catch(std::exception const&) {}
            while(input_number != 1U && input_number != 2U)
            {
                std::cout << "error\n";
                std::cout << "Character choice number : ";
                std::getline(std::cin, input);
                try
                {
                    input_number = std::stoul(input);
                }
                catch(std::exception const&) {}
            }

            input.clear();
            std::cout << "Enter character name : ";
            std::getline(std::cin, input);
            while(input.empty())
            {
                std::cout << "error\n";
                std::cout << "Enter character name : ";
                std::getline(std::cin, input);
            }
            std::cout << '\n';

            std::shared_ptr<rpg::character> chosen{};
            if(input_number == 1U)
            {
                chosen = std::make_shared<rpg::characters::knight>(std::move(input));

            }
            else
            {
                chosen = std::make_shared<rpg::characters::orc>(std::move(input));
            }
            add_character(chosen);
            return chosen;
        }

        void add_character(std::shared_ptr<rpg::character> character)
        {
            _characters.emplace_back(character);
        }

        void update_round(unsigned int round_nb) const
        {
            std::cout << "\n==== Round " << round_nb << " ====\n";
        }

        void refresh(std::shared_ptr<rpg::character> attacker, std::shared_ptr<rpg::character> victim, unsigned int round_nb) const
        {
            auto nb_character{0U};
            auto attacker_id = nb_character;
            auto victim_id = nb_character;

            std::cout << "--------------------\n";
            for(auto character : _characters)
            {
                ++nb_character;
                if(character == attacker)
                {
                    attacker_id = nb_character;
                }
                if(character == victim)
                {
                    victim_id = nb_character;
                }
                std::cout << '|' << tabulation() << nb_character << " - " << character->name() << " (" << rpg::characters::helpers::class_name::get(*character) << ") " << (character->is_stun() ? "(stun)" : "") << '\n';
                std::cout << '|' << tabulation() << tabulation() << "hp : " << character->hp() << '\n';
                std::cout << '|' << tabulation() << tabulation() << "dodge rate : " << character->agility() << "%\n";
                std::cout << '|' << tabulation() << tabulation() << "weapon : " << rpg::weapons::helpers::weapon_name::get(*character->weapon()) << " (" << character->weapon()->damages() << " damages)\n";
                std::cout << '|' << tabulation() << tabulation() << "protections : " << (character->protections().empty() ? "[]" : "") << '\n';
                for(auto protection : character->protections())
                {
                    std::cout << '|' << tabulation() << tabulation() << tabulation() << "- " << rpg::protections::helpers::protection_name::get(*protection) << " : " << protection->hp() << " hp\n";
                }
                std::cout << '|' << tabulation() << tabulation() << "capacities : " << (character->capacities().empty() ? "[]" : "") << '\n';
                for(auto capacity : character->capacities())
                {
                    std::cout << '|' << tabulation() << tabulation() << tabulation() << "- " << rpg::capacities::helpers::capacity_name::get(*capacity)  << " (cooldown " << capacity->cooldown(round_nb) << " rounds) (success rate " << capacity->success_rate() << "%)\n";
                }
            }
            std::cout << "--------------------\n";
            std::cout << tabulation() << "Attacker : " << attacker_id << '\n';
            std::cout << tabulation() << "Victim : " << victim_id << "\n\n";
        }

        void capacity_succeed(std::shared_ptr<rpg::capacity> capacity) const
        {
            std::cout << tabulation() << tabulation() << "Capacity " << rpg::capacities::helpers::capacity_name::get(*capacity) << " succeed !\n\n";
        }
        void capacity_failed(std::shared_ptr<rpg::capacity> capacity) const
        {
            std::cout << tabulation() << tabulation() << "Capacity " << rpg::capacities::helpers::capacity_name::get(*capacity) << " failed...\n\n";
        }
        void capacity_passed() const
        {
            std::cout << tabulation() << tabulation() << "You did not used capacity this turn...\n\n";
        }
        void attack_succeed(std::shared_ptr<rpg::weapon> weapon) const
        {
            std::cout << tabulation() << tabulation() << "Attack with " << rpg::weapons::helpers::weapon_name::get(*weapon) << " succeed !\n\n";
        }
        void attack_failed(std::shared_ptr<rpg::weapon> weapon) const
        {
            std::cout << tabulation() << tabulation() << "Dodge ! Attack with " << rpg::weapons::helpers::weapon_name::get(*weapon) << " failed...\n\n";
        }
        void attack_passed() const
        {
            std::cout << tabulation() << tabulation() << "You did not attack...\n\n";
        }
        void is_stun(std::shared_ptr<rpg::character> ) const
        {
            std::cout << tabulation() << tabulation() << "You're stun, pass turn...\n\n";
        }

        void win(std::shared_ptr<rpg::character> character) const
        {
            std::cout << character->name() << " wins this game ! Congratulations\n";
        }

        std::shared_ptr<rpg::weapon> choose_attack(std::shared_ptr<rpg::character> attacker) const
        {
            std::cout << tabulation() << tabulation() << "Attack phase : \n";
            std::cout << tabulation() << tabulation() << tabulation() << "1 - attack (" << rpg::weapons::helpers::weapon_name::get(*attacker->weapon()) << ")\n";
            std::cout << tabulation() << tabulation() << tabulation() << "2 - pass\n\n";
            std::cout << tabulation() << tabulation() << tabulation() << "Choose action number : ";
            std::string input{};
            std::getline(std::cin, input);
            unsigned int input_number{0U};
            try
            {
                input_number = std::stoul(input);
            }
            catch(std::exception const&) {}
            while(input_number != 1U && input_number != 2U)
            {
                std::cout << tabulation() << tabulation() << tabulation() << "error\n";
                std::cout << tabulation() << tabulation() << tabulation() << "Choose action number : ";
                std::getline(std::cin, input);
                try
                {
                    input_number = std::stoul(input);
                }
                catch(std::exception const&) {}
            }
            if(input_number == 1U)
            {
                return attacker->weapon();
            }
            return std::shared_ptr<rpg::weapon>{};
        }

        std::shared_ptr<rpg::capacity> choose_capacity(std::shared_ptr<rpg::character> attacker, unsigned int round_nb) const
        {
            std::cout << tabulation() << tabulation() << "Capacity phase : \n";
            auto nb_choice{1U};
            std::vector<unsigned int> cooldown_idx{};
            cooldown_idx.reserve(attacker->capacities().size());
            for(auto capacity : attacker->capacities())
            {
                auto capacity_can_used = capacity->can_use(round_nb);
                std::cout << tabulation() << tabulation() << tabulation();
                if(!capacity_can_used)
                {
                    cooldown_idx.emplace_back(nb_choice);
                    std::cout << 'X';
                }
                else
                {
                    std::cout << nb_choice;
                }
                std::cout << " - " << rpg::capacities::helpers::capacity_name::get(*capacity) << '\n';
                ++nb_choice;
            }
            std::cout << tabulation() << tabulation() << tabulation() << nb_choice << " - pass\n\n";
            std::cout << tabulation() << tabulation() << tabulation() << "Choose action number : ";
            std::string input{};
            std::getline(std::cin, input);
            unsigned int input_number{0U};
            try
            {
                input_number = std::stoul(input);
            }
            catch(std::exception const&) {}
            while(input_number == 0U || input_number > nb_choice || std::find(cooldown_idx.cbegin(), cooldown_idx.cend(), input_number) != cooldown_idx.cend())
            {
                std::cout << tabulation() << tabulation() << tabulation() << "error\n";
                std::cout << tabulation() << tabulation() << tabulation() << "Choose action number : ";
                std::getline(std::cin, input);
                try
                {
                    input_number = std::stoul(input);
                }
                catch(std::exception const&) {}
            }
            if(input_number == nb_choice)
            {
                return std::shared_ptr<rpg::capacity>{};
            }
            return *(attacker->capacities().cbegin() + (input_number - 1U));
        }

    private:
        std::vector<std::shared_ptr<rpg::character>> _characters;

        static constexpr char const* tabulation() { return "    "; }
    };
}

#endif