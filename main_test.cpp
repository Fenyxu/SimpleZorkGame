#include <iostream>
#include "Room.h"

int main2() {
	Room* room = new Room("name", "description");

	std::cout << "Hello world " << room->name << std::endl;

	return 0;
}