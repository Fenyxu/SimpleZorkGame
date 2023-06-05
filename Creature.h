#ifndef __CREATURE_H__
#define __CREATURE_H__

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
};

#endif // __CREATURE_H__