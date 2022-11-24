#ifndef _RPG_DICE_ROLLER_HPP_
#define _RPG_DICE_ROLLER_HPP_

#include <random>

namespace rpg::dice
{
    struct roller final
    {
    public:
        roller() :
            _device{},
            _rng{_device()},
            _distrib{1, 100}
        {}

        bool succeed(unsigned int success_rate)
        {
            auto random_nb = _distrib(_rng);
            return random_nb <= success_rate;
        }

    private:
        std::random_device _device;
        std::mt19937 _rng;
        std::uniform_int_distribution<std::mt19937::result_type> _distrib;
    };
}

#endif