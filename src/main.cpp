#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include "Game.hpp"

int main()
{
    Game game;
    try {
        game.run();
    } catch (const std::exception&) {
        return EXIT_FAILURE;
    }
}
