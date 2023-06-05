#include "Exit.h"
#include "Room.h"

Exit::Exit() {}

Exit::Exit(std::string name, std::string description, std::string directionName, std::string oppositeDirectionName, Room* source, Room* destination)
	: Entity{ name, description }, directionName{ directionName }, oppositeDirectionName{ oppositeDirectionName }, source{source}, destination{ destination } {
	type = EXIT;
	destination->contains.push_back(this);
}

Exit::~Exit() {}