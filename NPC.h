#pragma once

#include "Creature.h"
class Npc :
    public Creature
{

public:
    Npc(std::string name, std::string description, Room* location);
    ~Npc();


};
