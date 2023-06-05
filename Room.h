#pragma once

#include "Entity.h"
#include "Exit.h"
#include <vector>

class Exit;

class Room :
    public Entity
{

public:
    Room();
    Room(std::string name, std::string description);
    ~Room();


public:
    Exit* GetExit(std::string direction, std::vector<Entity*> entities);
};