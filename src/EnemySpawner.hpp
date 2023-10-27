#include "Enemy.hpp"
#include <vector>

#ifndef EnemySpawner_H  // Include guard to prevent double inclusion
#define EnemySpawner_H
class EnemySpawner {
    private:
        int _tick = 0;
    public:
        EnemySpawner();
        void update(std::vector<Enemy> &enemy_list, int frame_rate);
};
#endif
