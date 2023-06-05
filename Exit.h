#ifndef __EXIT_H__
#define __EXIT_H__

#include "Entity.h"
#include "Room.h"

class Exit :
    public Entity
{
public:
    Exit(std::string name, std::string description, Room *source, Room *destination);
    ~Exit();


public:
    enum Direction {
        NORTH,
        SOUTH,
        WEST,
        EAST
    };

    Room *source;
    Room *destination;
};

#endif // __EXIT_H__