#pragma once

#include "Creature.h"
class Npc :
    public Creature
{

public:
    Npc(const std::string name, const std::string description, Room* location);
    ~Npc();


};
