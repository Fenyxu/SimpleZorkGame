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

bool combat(Player* player, Npc* enemy) {
	std::cout << "The final combat is going to start" << std::endl;
	int consumables{ 0 };
	for (Item* item : player->GetItems()) {
		if (item->GetItemType() == WEAPON) {
			player->SetBaseDamage(player->GetBaseDamage() + item->GetBaseDamage());
			std::cout << "Player has equiped the " << item->name << std::endl;
		}
		else if (item->GetItemType() == CONSUMABLE) {
			consumables++;
		}
	}
	std::cout << "Player (health: " << player->GetHealth() << "HP - damage: " << player->GetBaseDamage() << ") vs Enemy(health: " << enemy->GetHealth() << "HP - damage:" << enemy->GetBaseDamage() << ")" << std::endl;
	
	do {
		std::string command{};
		std::cout << "Current Player health: " << player->GetHealth() << "HP - Current Werewolf health: " << enemy->GetHealth() << "HP" << std::endl;
		std::cout << "Available commands: attack or eat" << std::endl;
		std::cout << ">>";
		std::cin >> command;
		// Hero turn
		if (command == "attack") {
			std::cout << "Player attacks the Werewolf inflicting " << player->GetBaseDamage() << " of damage." << std::endl;
			enemy->SetHealth(enemy->GetHealth() - player->GetBaseDamage());
		}
		else if (command == "eat") {
			if (consumables > 0) {
				player->SetHealth(player->GetHealth() + 50);
				consumables--;
			}
			else {
				std::cout << "You have not more consumables to eat!" << std::endl;
			}
		}
		else if (command == "quit") {
			break;
		}
		else {
			std::cout << "Command not available, try again!" << std::endl;
		}

		// Enemy turn
		std::cout << "Werewolf attacks the Player inflicting " << enemy->GetBaseDamage() << " of damage." << std::endl;
		player->SetHealth(player->GetHealth() - enemy->GetBaseDamage());
	} while (player->GetHealth() > 0 && enemy->GetHealth() > 0);

	if (player->GetHealth() > 0 && enemy->GetHealth() <= 0) {
		std::cout << "The werewolf is dead!" << std::endl;
		std::cout << "Congratulations for beating the game!" << std::endl;
		return true;
	}
	else if (player->GetHealth() <= 0 && enemy->GetHealth() > 0) {
		std::cout << "You died!" << std::endl;
	}
	
	return false;
}

int main() {

	World world;
	Player* player = world.player;
	Npc* enemy = world.enemy;
	bool success{false};

	std::cout << "Welcome to this SimpleZorkGame created by Fenyxu" << std::endl;

	// Basic input strategy
	while (true) {
		if (world.combatStarted) {
			success = combat(player, enemy);
			break;
		}

		std::string input {};
		const char delim = ' ';
		std::vector<std::string> out;
		std::cout << "---" << player->location->name << "---" << std::endl;
		std::cout << player->location->description << std::endl;
		std::cout << ">>";
		std::getline(std::cin, input);

		if (input == "") {
			continue;
		}

		if (input == "quit") {
			break;
		}

		if (input == "north" || input == "south" || input == "west" || input == "east") {
			player->Move(input, world.entities);
			if (player->GetLocation()->name == "Cave") {
				world.combatStarted = true;
			}
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

	if (!success) {
		std::cout << "You can try again as many times as you want!" << std::endl;
	}

	std::cout << "Thanks for playing to the game!" << std::endl;

	return 0;
}

