#ifndef UNTITLED_ECS_H
#define UNTITLED_ECS_H

#include <map>
#include <vector>
#include <functional>
#include "Component.h"
#include "components/Actor.h"
#include "components/Pos2d.h"

template <typename T>
class ComponentTable {
    friend class ECS;
    std::map<int, T> rows;
public:
    T *get(int entity) {
        auto &value = rows[entity];
        return &value;
    }

    T *set(int entity, const T &comp) {
        auto &value = rows[entity];
        value = comp;
        return &value;
    }

    T *unset(int entity) {
        rows.erase(entity);
    }
};

class ECS {
public:
    ECS() {
        getComponentTable<Actor>() = new ComponentTable<Actor>();
        getComponentTable<Pos2d>() = new ComponentTable<Pos2d>();
    }

    virtual ~ECS() {
        delete getComponentTable<Actor>();
        delete getComponentTable<Pos2d>();
    }

    Component *getAny(int entityId) {
        const auto &it = master.find(entityId);
        if (it != master.end()) {
            return it->second;
        } else {
            return nullptr;
        }
    }

    template <typename T>
    T *get(int entityId) {
        auto *table = getComponentTable<T>();
        return table->get(entityId);
    }

    template <typename T>
    T *set(int entityId, const T &comp) {
        T *newComp = getComponentTable<T>()->set(entityId, comp);
        Component *&otherComp = master[entityId];
        newComp->enchain(otherComp);

        if (otherComp == nullptr) {
            otherComp = newComp;
        }
        return newComp;
    }

    template <typename T0, typename T1>
    void join(std::function<void(int, T0*, T1*)> iterFn) {
        static const int INVALID = 0xffffff;

        auto &rows0 = getComponentTable<T0>()->rows;
        auto &rows1 = getComponentTable<T1>()->rows;

        auto it0 = rows0.begin(), end0 = rows0.end();
        auto it1 = rows1.begin(), end1 = rows1.end();

        do {
            int entity0 = (it0 == end0) ? INVALID : it0->first;
            int entity1 = (it1 == end1) ? INVALID : it1->first;

            if (entity0 == INVALID && entity1 == INVALID) {
                break;
            } else if (entity0 == entity1) {
                iterFn(entity0, &it0->second, &it1->second);
                it0++;
                it1++;
            } else if (entity0 < entity1) {
                iterFn(entity0, &it0->second, nullptr);
                it0++;
            } else if (entity1 < entity0) {
                iterFn(entity1, nullptr, &it1->second);
                it1++;
            }
        } while (true);
    }

private:
    std::map<int, Component*> master;
    std::vector<void*> components = std::vector<void*>(256, nullptr);

    template <typename T>
    ComponentTable<T> *&getComponentTable() {
        return reinterpret_cast<ComponentTable<T>*&>(components[T::getStaticType()]);
    }
};

#endif
