#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Entity.h"
#include "Player.h"

class World
{
public:
	World();
	~World();

public:
	std::vector<Entity*> entities;
	Player* player;
};

#endif //__WORLD_H__