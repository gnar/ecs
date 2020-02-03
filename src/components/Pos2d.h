#ifndef UNTITLED_POS2D_H
#define UNTITLED_POS2D_H

#include "../Component.h"

class Pos2d : public BaseComponent<1> {
public:
    float x=0, y=0;

    Pos2d() = default;
    Pos2d(float x, float y) : x(x), y(y) {}
    Pos2d(const Pos2d &) = default;

    void debug(std::ostream &out) override;
};

#endif //UNTITLED_POS2D_H
