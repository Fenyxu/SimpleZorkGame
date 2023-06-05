#ifndef __ROOM_H__
#define __ROOM_H__

#include "Entity.h"
#include "Exit.h"

class Room :
    public Entity
{

public:
    Room(std::string name, std::string description);
    ~Room();


public:
    //Exit* GetExit(std::string direction);
    Type type;
};

#endif // __ROOM_H__