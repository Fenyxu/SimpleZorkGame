#pragma once
#include "Creature.h"
#include <iostream>

class Player :
    public Creature
{

public:
    Player(std::string name, std::string description, Room* location);
    ~Player();

private:
    std::list<Item*> items;

public:
    void Move(std::string direction, std::vector<Entity*> entities);
    void Take(std::string item);
    void PrintInventory();
};

