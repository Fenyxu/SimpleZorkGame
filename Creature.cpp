#include "Creature.h"
#include "Room.h"

Creature::Creature(std::string name, std::string description, Room* location)
	: Entity{ name, description }, location{ location } {}

Creature:: ~Creature() {}