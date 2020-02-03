#include "Pos2d.h"

#include <ostream>

void Pos2d::debug(std::ostream &out) {
    out << "Pos2d{x: " << x << ", y:" << y << "}";
}
