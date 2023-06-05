#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Creature.h"
class Player :
    public Creature
{

public:
    Player(std::string name, std::string description, Room* location);
    ~Player();

public:
    bool Move(std::string direction);
};



#endif // __PLAYER_H__