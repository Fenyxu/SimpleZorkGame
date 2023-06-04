#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include "Entity.h"

class World
{

	//TODO handle constructor and destructor

public:
	std::vector<Entity*> entities;
};

#endif //__WORLD_H__