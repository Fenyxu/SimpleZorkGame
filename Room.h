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
    Room(const std::string name, const std::string description);
    ~Room();


private:
    std::list<Item*> items;

public:
    std::list<Item*> GetItems() const;
    Exit* GetExit(std::string direction, std::vector<Entity*> entities) const;
    void AddItem(Item* item);
    void DeleteItem(Item* item);
   
};