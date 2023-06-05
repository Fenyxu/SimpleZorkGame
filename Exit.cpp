#include "Exit.h"

Exit::Exit(std::string name, std::string description, Room* source, Room* destination)
	: Entity{ name, description }, source{ source }, destination{ destination } {}

Exit::~Exit() {}