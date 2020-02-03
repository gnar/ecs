#include "Component.h"

#include <ostream>

void Component::debug(std::ostream &out) {
    out << "Component<" << getType() << ">{}";
}


