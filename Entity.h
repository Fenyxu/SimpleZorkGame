#pragma once

#include <string>
#include <list>

class Entity
{

public:
	Entity();
	Entity(std::string name, std::string description);
	~Entity();

//TODO handle constructor and destructor

public:
	enum Type
	{
		ENTITY,
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
	Type type;

	//virtual void Update();

};