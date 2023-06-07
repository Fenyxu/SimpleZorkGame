#pragma once

#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Npc.h"

class World
{
public:
	World();
	~World();

public:
	std::vector<Entity*> entities;
	Player* player;
	Npc* enemy;
	bool combatStarted{ false };
};

