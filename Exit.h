#ifndef __EXIT_H__
#define __EXIT_H__

#include "Entity.h"
#include "Room.h"

class Exit :
    public Entity
{
public:
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
    Type type;
};

#endif // __EXIT_H__