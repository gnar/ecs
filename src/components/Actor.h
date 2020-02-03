#ifndef UNTITLED_ACTOR_H
#define UNTITLED_ACTOR_H

#include <string>
#include "../Component.h"

class Actor : public BaseComponent<0> {
public:
    Actor() = default;
    Actor(const std::string &name);
    Actor(const Actor &other) = default;

    std::string name = "<unnamed>";

    void debug(std::ostream &out) override;
};

#endif //UNTITLED_ACTOR_H
