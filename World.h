#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Entity.h"

class World
{
public:
	World();
	~World();

public:
	std::vector<Entity*> entities;
	void addEntitiesToVector(std::vector<Entity*> entities, Entity* entity...);
};

#endif //__WORLD_H__