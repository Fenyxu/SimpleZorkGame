#pragma once

#include "Entity.h"
#include "Exit.h"
#include <vector>
#include "Item.h"

class Exit;

class Room :
    public Entity
{

public:
    Room();
    Room(std::string name, std::string description);
    ~Room();


private:
    std::list<Item*> items;

public:
    std::list<Item*> GetItems();
    Exit* GetExit(std::string direction, std::vector<Entity*> entities);
    void AddItem(Item* item);
    void DeleteItem(Item* item);
   
};