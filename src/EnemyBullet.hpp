#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include <memory>
#include "GameObject.hpp"

#ifndef Class_H  // Include guard to prevent double inclusion
#define Class_H
class EnemyBullet: public GameObject {
    public:
        EnemyBullet(float positionX, float positionY);
        void update(sf::Time delta) override;


        // disable copying, but enable moving
        EnemyBullet(const EnemyBullet&) = delete;
        EnemyBullet& operator=(const EnemyBullet&) = delete;

        EnemyBullet(EnemyBullet&&);
        EnemyBullet& operator=(EnemyBullet&&);
};
#endif

