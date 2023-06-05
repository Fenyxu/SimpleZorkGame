#include "Entity.h"


Entity::Entity(std::string name, std::string description)
	: name{ name }, description{ description } {
	type = ENTITY;
	contains.push_back(this);
}

Entity::~Entity() {

}