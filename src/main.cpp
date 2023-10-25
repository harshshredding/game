#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow{ { 640u, 480u }, "Space Pig" };
    window.setFramerateLimit(144);

    std::cout << "Space Pig" << std::endl;

    // create the pig, the main character
    sf::CircleShape pig;
    pig.setRadius(30.f);
    pig.setPosition(100.f, 100.f);
    pig.setFillColor(sf::Color::Magenta);
    
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                std::cout << "Close Window" << '\n';
            }
        }
        window.clear();
        window.draw(pig);
        window.display();
    }
}
