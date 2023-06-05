#pragma once

#include "Room.h"

class Room;

class Exit :
    public Entity
{
public:
    Exit();
    Exit(std::string name, std::string description, std::string directionName, std::string oppositeDirectionName, Room* source, Room* destination);
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
