#include "Exit.h"
#include "Room.h"

Exit::Exit(const std::string name, const std::string description, const std::string directionName, const std::string oppositeDirectionName, Room* source, Room* destination)
	: Entity{ name, description }, directionName{ directionName }, oppositeDirectionName{ oppositeDirectionName }, source{source}, destination{ destination } {
	type = EXIT;
	destination->contains.push_back(this);
}

Exit::~Exit() {}