#include "Entity.h"

Entity::Entity() {}

Entity::Entity(const std::string name, const std::string description)
	: name( name ), description( description ) {
}

Entity::~Entity() {}