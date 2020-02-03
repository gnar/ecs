#include <iostream>
#include "src/ECS.h"
#include "src/systems/GameLogic.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    ECS ecs;
    ecs.set(42, Actor{"Player 1"});
    ecs.set(42, Pos2d{20, 30});

    GameLogic gameLogic(ecs);

    for (int t=0; t<20; ++t) {
        gameLogic.update(0.5);
    }

    return 0;
}
