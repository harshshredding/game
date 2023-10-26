#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Player.hpp"

#ifndef Game_H  // Include guard to prevent double inclusion
#define Game_H

class Game {
    public:
        Game();
        void run();
    private:
        void update(sf::Time delta);
        void render();
        void processEvents();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    private:
        sf::RenderWindow _window;
            
        // input state
        bool _playerMovingUp;
        bool _playerMovingLeft;
        bool _playerMovingRight;
        bool _playerMovingDown;
        // seconds per frame for 60fps

        sf::Time _timePerFrame = sf::seconds(1.f / 60.f);

        // game objects
        Player _player;
};

#endif
