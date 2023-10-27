#include "Enemy.hpp"

Enemy::Enemy(
    float positionX,
    float positionY,
    float speed
): GameObject(positionX, positionY, "media/Enemy.png", speed)
{

}

Enemy::Enemy(Enemy &&other)
{
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
}

Enemy& Enemy::operator=(Enemy&& other) {
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
    return *this;
}

void Enemy::update(sf::Time delta) {
    sf::Vector2f enemy_velocity(0.f, 0.f);
    enemy_velocity.y = 1 * _speed;
    _sprite.move(enemy_velocity * delta.asSeconds());
}
