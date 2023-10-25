#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Keyboard.hpp"

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
        sf::CircleShape _pig;
        float _pig_speed = 50.f;
        bool _playerMovingUp;
        bool _playerMovingLeft;
        bool _playerMovingRight;
        bool _playerMovingDown;
        // seconds per frame for 60fps
        sf::Time _timePerFrame = sf::seconds(1.f / 60.f);
};
