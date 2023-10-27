// Represents the state and functions of a player
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include <memory>
#include "GameObject.hpp"

#ifndef Bullet_H
#define Bullet_H
class Bullet: public GameObject {
    public:
        Bullet(float positionX, float positionY);
        void update(sf::Time delta) override;


        // disable copying, but enable moving
        Bullet(const Bullet&) = delete;
        Bullet& operator=(const Bullet&) = delete;

        Bullet(Bullet&&);
        Bullet& operator=(Bullet&&);
};
#endif
