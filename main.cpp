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
	Player* player = world.player;

	std::cout << "Welcome to this SimpleZorkGame created by Fenyxu" << std::endl;

	// Basic input strategy
	while (true) {
		std::string input {};
		const char delim = ' ';
		std::vector<std::string> out;
		std::cout << "---" << player->location->name << "---" << std::endl;
		std::cout << player->location->description << std::endl;
		std::cout << ">>";
		std::getline(std::cin, input);

		if (input == "quit") {
			break;
		}

		if (input == "north" || input == "south" || input == "west" || input == "east") {
			player->Move(input, world.entities);
			continue;
		}

		tokenize(input, delim, out);
		if (out.at(0) == "inventory") {
			player->PrintInventory();
			continue;
		}

		if (out.at(0) == "get" || out.at(0) == "take" || out.at(0) == "grab") {
			player->Take(out.at(1));
			continue;
		}

		if (out.at(0) == "drop") {
			player->Drop(out.at(1));
			continue;
		}

		if (out.at(0) == "put" && out.at(2) == "in") {
			std::string itemToInsertStr{}, itemWithSlotStr{};
			Item* itemToInsert{};
			Item* itemWithSlot{};
			itemToInsertStr = out.at(1);
			itemWithSlotStr = out.at(3);
			int found = 0;
			if (itemToInsertStr != "" && itemWithSlotStr != "") {
				for (Item* item : player->GetItems()) {
					if (item->name == itemToInsertStr) {
						itemToInsert = item;
						found++;
					}
					else if (item->name == itemWithSlotStr) {
						itemWithSlot = item;
						found++;
					}
				}
				if (found == 2) {
					if (itemWithSlot->HasSlots() && itemToInsert->CanBePlacedInsideContainer()) {
						itemWithSlot->AddItemInside(itemToInsert);
						player->DeleteItem(itemToInsert);
						continue;
					}
					else {
						std::cout << "Cannot put " << itemToInsert->name << " in " << itemWithSlot->name << std::endl << std::endl;
						continue;
					}
				}
				else {
					std::cout << "The player doesn't have any or one of those items in the inventory!" << std::endl << std::endl;
					continue;
				}
			}
			else {
				std::cout << "The player doesn't have any of those items in the inventory!" << std::endl << std::endl;
				continue;
			}
		}
		
		std::cout << "Sorry this command is not available." << std::endl << std::endl;

	}

	std::cout << "Thanks for playing to the game!";

	return 0;
}

