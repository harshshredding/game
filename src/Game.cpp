#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include <iostream>
#include "Game.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Util.hpp"

Game::Game(): 
    _window({ 640u, 480u }, "Space Pig"),
    _playerMovingDown(false),
    _playerMovingLeft(false),
    _playerMovingUp(false),
    _playerMovingRight(false)
{ 
    _pig.setRadius(30.f);
    _pig.setPosition(100.f, 100.f);
    _pig.setFillColor(sf::Color::Magenta);
}


void Game::run() {
    sf::Clock clock;
    while (_window.isOpen())
    {
        sf::Time frame_delta = clock.restart();
        processEvents();
        update(frame_delta);
        render();
    }
}

void Game::update(sf::Time delta) {
    sf::Vector2f player_velocity(0.f, 0.f);
    if (_playerMovingUp)
        player_velocity.y -= _pig_speed;
    if (_playerMovingDown)
        player_velocity.y += _pig_speed;
    if (_playerMovingLeft)
        player_velocity.x -= _pig_speed;
    if (_playerMovingRight)
        player_velocity.x += _pig_speed;
    _pig.move(player_velocity * delta.asSeconds());
}

void Game::render() {
    _window.clear();
    _window.draw(_pig);
    _window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W)
        _playerMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        _playerMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        _playerMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        _playerMovingRight = isPressed;
}

// process all window events
void Game::processEvents() {
    for (auto event = sf::Event{}; _window.pollEvent(event);)
    {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                _window.close();
                print("Close Window");
                break;
            default:
                print("Cannot handle event type");
        }
    }
}
