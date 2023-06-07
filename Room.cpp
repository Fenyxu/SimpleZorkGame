#include "Room.h"
#include <string>
#include <iostream>
#include <vector>

Room::Room(const std::string name, const std::string description) 
	: Entity{ name, description } {
	type = ROOM;
}

Room::~Room() {}

Exit* Room::GetExit(std::string direction, std::vector<Entity*> entities) const {
	for (Entity* entity : entities) {
		if (entity->type == EXIT) {
			//std::cout << "Exit found " << entity->name << std::endl;
			
			if (((Exit*)entity)->source->name == this->name && ((Exit*)entity)->directionName == direction) {
				//std::cout << "Moving into exit with direction " << direction << std::endl;
				return (Exit*)entity;
			}
		}
	}

	return NULL;
}

void Room::AddItem(Item* item) {
	this->items.push_back(item);
}

void Room::DeleteItem(Item* item) {
	this->items.remove(item);
}

std::list<Item*> Room::GetItems() const {
	return items;
}