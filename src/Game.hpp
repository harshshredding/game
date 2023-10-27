#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "Player.hpp"
#include <vector>
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "EnemySpawner.hpp"
#include "EnemyBullet.hpp"

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
        bool areSpritesColliding(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
    private:
        bool _is_game_over = false;

        sf::RenderWindow _window;
            
        // input state
        bool _playerMovingUp;
        bool _playerMovingLeft;
        bool _playerMovingRight;
        bool _playerMovingDown;
        bool _playerShooting;

        // seconds per frame for 60fps
        int _frame_rate;
        sf::Time _timePerFrame;

        // game objects
        Player _player;
        std::vector<Bullet> _bullet_list;
        std::vector<Enemy> _enemy_list;
        std::vector<EnemyBullet> _enemy_bullets;
        EnemySpawner _enemy_spawner;


        // GAME OVER
        sf::Text _game_over_text;
        sf::Font _game_over_font;
};

#endif
