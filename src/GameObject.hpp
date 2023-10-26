// Represents the state and functions of a player
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include <memory>


#ifndef GameObject_H
#define GameObject_H
class GameObject {
    public:
        std::unique_ptr<sf::Texture> _texture;
        sf::Sprite _sprite;
        float _speed;


        GameObject();

        GameObject(
            float positionX,
            float positionY,
            std::string texture_file_path,
            float speed
        );

        virtual void update(sf::Time delta) const = 0;

        // disable copying, but enable moving
        GameObject(const GameObject&) = delete;
        GameObject& operator=(const GameObject&) = delete;

        GameObject(GameObject&&);
        GameObject& operator=(GameObject&&);
};
#endif
