#include "Player.h"

Player::Player(std::string name, std::string description, Room* location)
	: Creature{ name, description, location } {}


Player::~Player() {}

bool Player::Move(std::string direction) {
	Room* room = GetLocation();
	Exit* exit = room->GetExit(direction);
	return true;
}