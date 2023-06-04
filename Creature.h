#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "Entity.h"
#include "Room.h"


class Creature :
    public Entity
{

public:
    Room *location;
};

#endif // __CREATURE_H__