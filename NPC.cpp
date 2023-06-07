#include "Npc.h"

Npc::Npc(const std::string name, const std::string description, Room* location)
	: Creature{ name, description, location } {}
Npc::~Npc() {}