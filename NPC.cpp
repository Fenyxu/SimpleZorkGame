#include "Npc.h"

Npc::Npc(std::string name, std::string description, Room* location)
	: Creature{ name, description, location } {}
Npc::~Npc() {}