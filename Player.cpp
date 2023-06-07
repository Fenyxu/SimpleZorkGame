#include "Player.h"

Player::Player(std::string name, std::string description, Room* location)
	: Creature{ name, description, location } {}


Player::~Player() {}

void Player::Move(const std::string direction, const std::vector<Entity*> entities) {
	Room* room = GetLocation();
	Exit* exit = room->GetExit(direction, entities);
	if (exit != NULL) {
		this->location = exit->destination;
	}
}

void Player::Take(std::string itemName) {
	Room* room = GetLocation();
	std::list<Item*> items = room->GetItems();
	if (items.empty()) {
		return;
	}
	else {
		for (Item *item : items) {
			if (item->name == itemName) {
				this->items.push_back(item);
				room->DeleteItem(item);
				break;
			}
		}
	}
}

void Player::Drop(std::string itemName) {
	if (items.empty()) {
		return;
	}
	for (Item* item : items) {
		if (item->name == itemName) {
			DeleteItem(item);
			Room* room = GetLocation();
			room->AddItem(item);
			break;
		}
	}
}

void Player::PrintInventory() const {
	if (items.empty()) {
		std::cout << "You have the inventory empty" << std::endl;
	}
	else {
		std::cout << "---Inventory---" << std::endl;
		for (Item* item : items) {
			std::cout << item->name << ": " << item->description << std::endl;
		}
		std::cout << "---------------" << std::endl;
	}
	
}