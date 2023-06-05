#pragma once

#include "Entity.h"
#include "Room.h"


class Creature :
    public Entity
{
public: 
    Creature(std::string name, std::string description, Room* location);
    ~Creature();

public:
    Room* location;

    Room* GetLocation() {
        return location;
    }

    bool SetLocation(Room* room) {
        location = room;
    }
};