#ifndef UNTITLED_COMPONENT_H
#define UNTITLED_COMPONENT_H

#include <iosfwd>

class Component {
public:
    virtual int getType() = 0;
    Component *prev = nullptr;
    Component *next = nullptr;

    Component() = default;
    Component(const Component &other) : Component() {}
    virtual ~Component() {
    }

    virtual void debug(std::ostream &out);

    template <typename T>
    T *find() {
        Component *it = this;
        do {
            if (it->getType() == T::getStaticType()) {
                return static_cast<T*>(it);
            } else {
                it = it->next;
            }
        } while (it != this);
    }

private:
    friend class ECS;

    void enchain(Component *other) {
        if (!prev && !next) {
            prev = next = this;
        }

        if (other) {
            prev = other;
            next = other->next;
            other->next->prev = this;
            other->next = this;
        }
    }

    void unchain() {
        prev->next = next;
        next->prev = prev;
        prev = next = this;
    }
};

template <int I>
class BaseComponent : public Component {
    static const int staticType = I;

public:
    static int getStaticType() {
        return staticType;
    }

    int getType() final {
        return getStaticType();
    }
};

#endif
