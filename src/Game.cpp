#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include "Game.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Util.hpp"
#include "Bullet.hpp"

Game::Game(): 
    _window({ 640u, 480u }, "Space Pig"),
    _playerMovingDown(false),
    _playerMovingLeft(false),
    _playerMovingUp(false),
    _playerMovingRight(false),
    _playerShooting(false),
    _frame_rate(60)
{ 
    _timePerFrame = sf::seconds(1.f / _frame_rate);
}

void Game::run() {
    sf::Clock clock;
    sf::Time elapsed = sf::Time::Zero;
    while (_window.isOpen())
    {
        elapsed += clock.restart();
        processEvents();
        // Update every 1/60 seconds
        while (elapsed > _timePerFrame) {
            update(_timePerFrame);
            elapsed -= _timePerFrame;
        } 
        render();
    }
}

void Game::update(sf::Time delta) {
    _player.update(
        delta,
        _playerMovingUp,
        _playerMovingDown,
        _playerMovingLeft, 
        _playerMovingRight
    );
    // update all bullets
    for (auto &bullet: _bullet_list) {
        bullet.update(delta);
    }
    // update all enemies
    for (auto &enemy: _enemy_list) {
        enemy.update(delta);
    }
    _enemy_spawner.update(_enemy_list, _frame_rate);
}

void Game::render() {
    _window.clear();
    _window.draw(_player._sprite);
    // render player bullets
    for (auto &bullet: _bullet_list) {
        _window.draw(bullet._sprite);
    }
    // render enemies
    for (auto &enemy: _enemy_list) {
        _window.draw(enemy._sprite);
    }
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
    else if (key == sf::Keyboard::Space) {
        // holding down the spacebar should NOT
        // shoot multiple times.
        if (_playerShooting != isPressed) {
            _playerShooting = isPressed;
            print("Space");
            // create a new bullet if space is pressed
            if (isPressed)
                _bullet_list.emplace_back(
                    Bullet(_player._sprite.getPosition().x, _player._sprite.getPosition().y)
                );
        }
    }
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
                break;
        }
    }
}
