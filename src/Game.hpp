#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class Game {
    public:
        Game();
        void run();
    private:
        void update();
        void render();
        void processEvents();
    private:
        sf::RenderWindow _window;
        sf::CircleShape _pig;
};
