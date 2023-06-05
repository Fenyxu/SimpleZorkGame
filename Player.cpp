#include "Player.h"
#include <vector>

Player::Player(std::string name, std::string description, Room* location)
	: Creature{ name, description, location } {}


Player::~Player() {}

bool Player::Move(std::string direction, std::vector<Entity*> entities) {
	Room* room = GetLocation();
	Exit* exit = room->GetExit(direction, entities);
	if (exit != NULL) {
		this->location = exit->destination;
		return true;
	}
	return false;
}