#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Room.h"
#include <sstream>

void tokenize(std::string const& str, const char delim,
	std::vector<std::string>& out)
{
	// construct a stream from the string 
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

int main() {

	World world;

	std::cout << "Welcome to this SimpleZorkGame created by Fenyxu" << std::endl;

	// Basic input strategy
	while (true) {
		std::string input {};
		const char delim = ' ';
		std::vector<std::string> out;
		std::cout << world.player->location->name << std::endl;
		std::cout << world.player->location->description << std::endl;
		std::cout << ">>";
		std::getline(std::cin, input);

		if (input == "quit") {
			break;
		}

		if (input == "north" || input == "south" || input == "west" || input == "east") {
			world.player->Move(input, world.entities);
			continue;
		}

		tokenize(input, delim, out);
		if (out.at(0) == "inventory") {
			world.player->PrintInventory();
			continue;
		}

		if (out.at(0) == "get" || out.at(0) == "take" || out.at(0) == "grab") {
			world.player->Take(out.at(1));
			continue;
		}

		
		std::cout << "Sorry this command is not available." << std::endl;

	}

	std::cout << "Thanks for playing to the game!";

	return 0;
}

