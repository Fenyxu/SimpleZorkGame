#include "Entity.h"

Entity::Entity() {}

Entity::Entity(std::string name, std::string description)
	: name( name ), description( description ) {
}

Entity::~Entity() {}