#ifndef __EXIT_H__
#define __EXIT_H__

#include "Entity.h"
#include "Room.h"

class Exit :
    public Entity
{
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