#ifndef __ROOM_H__
#define __ROOM_H__

#include "Entity.h"
class Room :
    public Entity
{

public:
    Room(std::string name, std::string description);
    ~Room();

};

#endif // __ROOM_H__