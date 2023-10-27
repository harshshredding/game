#include "EnemySpawner.hpp"
#include "Enemy.hpp"
#include "Util.hpp"

EnemySpawner::EnemySpawner(): 
_tick(0),
_random_device()
{
    // initialize random number generator
    _number_generator = std::mt19937(_random_device());
    // generate an random integer between 1 and 18
    _distribution = std::uniform_int_distribution<int>(1, 18);
}

void EnemySpawner::update(std::vector<Enemy> &enemy_list, int frame_rate) {
    _tick += 1;
    // spawn every 2 seconds
    _tick %= (frame_rate * 2);
    if (_tick == 0) {
        int x_rand = _distribution(_number_generator);
        int x_pos = x_rand * (constants::GAME_WIDTH / 20);
        enemy_list.emplace_back(Enemy(x_pos, -60, 30));
    }
}
