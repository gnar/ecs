//
// Created by gselke on 2/3/20.
//

#ifndef UNTITLED_GAMELOGIC_H
#define UNTITLED_GAMELOGIC_H

#include "../ECS.h"

class GameLogic {
    ECS &ecs;
public:
    GameLogic(ECS &ecs);

    void update(float dt);
};


#endif //UNTITLED_GAMELOGIC_H
