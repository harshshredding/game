#include "Bullet.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "Util.hpp"
#include <algorithm>
#include <locale>
#include <memory>

Bullet::Bullet(float positionX, float positionY) {
    _texture = std::make_unique<sf::Texture>();
    if (!_texture->loadFromFile("media/Bullet.png")) {
        print("Could not load Bullet.png sprite from media/Bullet.png");
        throw std::exception();
    }
    _sprite.setTexture(*_texture);
    _sprite.setPosition(positionX, positionY);
}


void Bullet::update(
    sf::Time delta
) {
    sf::Vector2f bullet_velocity(0.f, 0.f);
    bullet_velocity.y = -1 * _speed;
    _sprite.move(bullet_velocity * delta.asSeconds());
}

Bullet::Bullet(Bullet &&other)
{
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
}

Bullet& Bullet::operator=(Bullet&& other) {
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
    return *this;
}
