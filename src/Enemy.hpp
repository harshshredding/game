// Represents the state and functions of a player
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include <memory>
#include <vector>
#include "GameObject.hpp"
#include "EnemyBullet.hpp"


#ifndef Enemy_H
#define Enemy_H
class Enemy: public GameObject {
    private:
        int _bullet_tick;
    public:
        Enemy(
            float positionX,
            float positionY,
            float speed
        );

        // disable copying, but enable moving
        Enemy(const Enemy&) = delete;
        Enemy& operator=(const Enemy&) = delete;

        void update(sf::Time delta, std::vector<EnemyBullet> &enemy_bullets);

        Enemy(Enemy&&);
        Enemy& operator=(Enemy&&);
};
#endif
