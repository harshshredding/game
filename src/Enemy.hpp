// Represents the state and functions of a player
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include <memory>
#include "GameObject.hpp"


#ifndef Enemy_H
#define Enemy_H
class Enemy: public GameObject {
    public:
        Enemy(
            float positionX,
            float positionY,
            float speed
        );

        // disable copying, but enable moving
        Enemy(const Enemy&) = delete;
        Enemy& operator=(const Enemy&) = delete;

        void update(sf::Time delta) override;

        Enemy(Enemy&&);
        Enemy& operator=(Enemy&&);
};
#endif
