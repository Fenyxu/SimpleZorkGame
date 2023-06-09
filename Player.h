#pragma once
#include "Creature.h"
#include <iostream>

class Player :
    public Creature
{

public:
    Player(const std::string name, const std::string description, Room* location);
    ~Player();

private:
    std::list<Item*> items;

public:
    std::list<Item*> GetItems() {
        return items;
    }
    void Move(std::string direction, std::vector<Entity*> entities);
    void Take(std::string item);
    void Drop(std::string item);
    void Look();
    void DeleteItem(Item* item) {
        this->items.remove(item);
    }
    
    void PrintInventory() const;
};

