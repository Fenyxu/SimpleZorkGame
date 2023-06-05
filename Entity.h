#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <string>
#include <list>

class Entity
{

public:
	Entity(std::string name, std::string description);
	~Entity();

//TODO handle constructor and destructor

public:
	enum Type
	{
		CREATURE,
		NPC,
		PLAYER,
		EXIT,
		ROOM,
		ITEM
	};

	std::string name;
	std::string description;
	std::list<Entity*> contains;

	//virtual void Update();

};

#endif // __ENTITY_H__