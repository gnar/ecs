#include "GameLogic.h"

#include <iostream>
using namespace std;

GameLogic::GameLogic(ECS &ecs) : ecs(ecs) {}

void GameLogic::update(float dt) {
    ecs.join<Actor, Pos2d>([dt](int entityId, Actor *actor, Pos2d *pos2d) {
        if (actor && pos2d) {
            pos2d->y += dt * 2.0f;

            cout << "UPDATE: " << entityId << ": ";
            actor->debug(cout);
            cout << " | ";
            pos2d->debug(cout);
            cout << endl;
        }
    });
}
