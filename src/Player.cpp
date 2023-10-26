#include "Player.hpp"
#include "SFML/System/Time.hpp"
#include "Util.hpp"

Player::Player() {
    if (!_texture.loadFromFile("media/Idle.png")) {
        print("Could not load Idle.png sprite from media/Idle.png");
        throw std::exception();
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(100.f, 100.f);
}


void Player::update(
    sf::Time delta,
    bool playerMovingUp,
    bool playerMovingDown,
    bool playerMovingLeft,
    bool playerMovingRight
) {
    sf::Vector2f player_velocity(0.f, 0.f);
    if (playerMovingUp)
        player_velocity.y -= _speed;
    if (playerMovingDown)
        player_velocity.y += _speed;
    if (playerMovingLeft)
        player_velocity.x -= _speed;
    if (playerMovingRight)
        player_velocity.x += _speed;
    _sprite.move(player_velocity * delta.asSeconds());
}
