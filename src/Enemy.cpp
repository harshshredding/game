#include "Enemy.hpp"
#include "Util.hpp"

Enemy::Enemy(
    float positionX,
    float positionY,
    float speed
): GameObject(positionX, positionY, "media/Enemy.png", speed), _bullet_tick(0)
{
}

Enemy::Enemy(Enemy &&other)
{
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
    _isDead = other._isDead;
    _bullet_tick = other._bullet_tick;
}

Enemy& Enemy::operator=(Enemy&& other) {
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
    _isDead = other._isDead;
    _bullet_tick = other._bullet_tick;
    return *this;
}

void Enemy::update(sf::Time delta, std::vector<EnemyBullet> &enemy_bullets) {
    // update position
    sf::Vector2f enemy_velocity(0.f, 0.f);
    enemy_velocity.y = 1 * _speed;
    _sprite.move(enemy_velocity * delta.asSeconds());

    // shoot bullets
    _bullet_tick += 1;
    _bullet_tick %= (constants::FRAME_RATE * 2);
    if (_bullet_tick == 0) {
        enemy_bullets.emplace_back(
            EnemyBullet(_sprite.getPosition().x, _sprite.getPosition().y)
        );
    }
}
