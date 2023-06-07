#pragma once

#include "Room.h"

class Room;

class Exit :
    public Entity
{
public:
    Exit(const std::string name, const std::string description, const std::string directionName, const std::string oppositeDirectionName, Room* source, Room* destination);
    ~Exit();


public:
    enum Direction {
        NORTH,
        SOUTH,
        WEST,
        EAST
    };

    std::string directionName;
    std::string oppositeDirectionName;
    Room* source;
    Room* destination;
};
