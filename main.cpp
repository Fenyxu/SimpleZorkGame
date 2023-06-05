#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Room.h"

int main() {

	World world;

	std::cout << "Welcome to this SimpleZorkGame created by Fenyxu" << std::endl;

	// Input and game handling will be improved lately
	while (true) {
		std::string input;
		std::cout << ">>";
		std::cin >> input;

		if (input == "quit") {
			break;
		}
		else {
			std::cout << "The player is in " << world.player->GetLocation()->name << std::endl;
			world.player->Move(input);
			std::cout << "Now the player have moved to " << world.player->GetLocation()->name << std::endl;
		}
	}

	std::cout << "Thanks for playing";

	return 0;
}