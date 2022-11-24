#include <iostream>

#include "rpg/display/console.hpp"

#include "rpg/core/game.hpp"

#include <memory>

int main(int, char*[])
{
    ::rpg::display::console displayer{};
    ::rgp::core::game<decltype(displayer)> game{std::move(displayer)};

    game.play();

    return 0;
}