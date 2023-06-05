#include "Room.h"
#include <string>
#include <iostream>

Room::Room(std::string name, std::string description) 
	: Entity{ name, description } {
	type = ROOM;
}

//Exit* Room::GetExit(std::string direction) {
	/*for (Entity* entity : contains) {
		if (entity->type == EXIT) {
			std::cout << "Exit found " << entity->name << std::endl;
			if (((Exit*)entity)->directionName == direction) {
				std::cout << "Moving into exit with direction " << direction << std::endl;
			}
		}
	}*/
//}