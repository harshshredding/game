// Represents the state and functions of a player
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include <memory>


#ifndef Bullet_H
#define Bullet_H
class Bullet {
    public:
        std::unique_ptr<sf::Texture> _texture;
        sf::Sprite _sprite;
        float _speed = 400.f;

        Bullet(float positionX, float positionY);
        void update(sf::Time delta);


        // disable copying, but enable moving
        Bullet(const Bullet&) = delete;
        Bullet& operator=(const Bullet&) = delete;

        Bullet(Bullet&&);
        Bullet& operator=(Bullet&&);
};
#endif
