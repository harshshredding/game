// Represents the state and functions of a player
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include "GameObject.hpp"

#ifndef Player_H
#define Player_H
class Player: public GameObject {
    public:
        Player();
        void update(
            sf::Time delta,
            bool playerMovingUp,
            bool playerMovingDown,
            bool playerMovingLeft,
            bool playerMovingRight
        );
    private:
        // disable copying
        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
};
#endif
