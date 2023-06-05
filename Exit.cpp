#include "Exit.h"

Exit::Exit(std::string name, std::string description, std::string directionName, std::string oppositeDirectionName, Room* source, Room* destination)
	: Entity{ name, description }, directionName{ directionName }, oppositeDirectionName{ oppositeDirectionName },source{source}, destination{ destination } {
	type = EXIT;
}

Exit::~Exit() {}