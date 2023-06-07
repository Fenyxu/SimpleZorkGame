#pragma once

#include "Entity.h"
#include "Room.h"
#include <list>


class Creature :
    public Entity
{
public: 
    Creature(const std::string name, const std::string description, Room* location);
    ~Creature();

public:
    Room* location;
    std::list<Entity*> inventory;

private:
    int health {0};
    int baseDamage{ 0 };

public:
    Room* GetLocation() {
        return location;
    }

    bool SetLocation(Room* room) {
        location = room;
    }
    int GetHealth() {
        return health;
    }
    void SetHealth(int health) {
        this->health = health;
    }
    int GetBaseDamage() {
        return baseDamage;
    }
    void SetBaseDamage(int baseDamage) {
        this->baseDamage = baseDamage;
    }
};