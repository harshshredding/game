#include "EnemyBullet.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "Util.hpp"
#include <algorithm>
#include <locale>
#include <memory>


EnemyBullet::EnemyBullet(
    float positionX,
    float positionY
): GameObject(positionX, positionY, "media/EnemyBullet.png", 400.f)
{
}

void EnemyBullet::update(
    sf::Time delta
) {
    sf::Vector2f bullet_velocity(0.f, 0.f);
    bullet_velocity.y = -1 * _speed;
    _sprite.move(bullet_velocity * delta.asSeconds());
}

EnemyBullet::EnemyBullet(EnemyBullet &&other)
{
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
}

EnemyBullet& EnemyBullet::operator=(EnemyBullet&& other) {
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
    return *this;
}
