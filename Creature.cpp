#include "Creature.h"

Creature::Creature(const std::string name, const std::string description, Room* location)
	: Entity{ name, description }, location{ location } {}

Creature:: ~Creature() {}