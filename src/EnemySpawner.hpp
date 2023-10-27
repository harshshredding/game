#include "Enemy.hpp"
#include <vector>
#include <random>

#ifndef EnemySpawner_H  // Include guard to prevent double inclusion
#define EnemySpawner_H
class EnemySpawner {
    private:
        int _tick = 0;

        // state for a random number generator
        // that generates integers between 1 and 18
        std::random_device _random_device;
        std::mt19937 _number_generator;
        std::uniform_int_distribution<int> _distribution;
    public:
        EnemySpawner();
        void update(std::vector<Enemy> &enemy_list, int frame_rate);
};
#endif
