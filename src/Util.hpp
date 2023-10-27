#include <string>



#ifndef Util_H  // Include guard to prevent double inclusion
#define Util_H

void print(std::string &&str);

namespace constants {
    const int GAME_WIDTH = 640u;
    const int GAME_HEIGHT = 480u;
}

#endif
