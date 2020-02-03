#include "Actor.h"

#include <ostream>

Actor::Actor(const std::string &name) : name(name) {}

void Actor::debug(std::ostream &out) {
    out << "Actor{name: " << name << "}";
}
