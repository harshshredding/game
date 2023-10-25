#include "SFML/Window/Event.hpp"
#include <iostream>
#include "Game.hpp"

Game::Game(): _window({ 640u, 480u }, "Space Pig") { 
    _pig.setRadius(30.f);
    _pig.setPosition(100.f, 100.f);
    _pig.setFillColor(sf::Color::Magenta);
}


void Game::run() {
    while (_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::update() {

}

void Game::render() {
    _window.clear();
    _window.draw(_pig);
    _window.display();
}

void Game::processEvents() {
    for (auto event = sf::Event{}; _window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            _window.close();
            std::cout << "Close Window" << '\n';
        }
    }
}
