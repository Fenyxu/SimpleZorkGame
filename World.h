#pragma once

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

