#include <iostream>

#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Player.h"

World::World() {
	// Rooms
	Room* northHouse = new Room("North of the House", "Here you can see the whole north facade of the house.");
	Room* westHouse = new Room("West of the House", "At the west you can see a cave entrance.\nTo the north you can see a log cabin.\nHere you can see a rusty basement cellar door mid openned.");
	Room* eastHouse = new Room("East of the House", "You can see a kitchen through the window.");
	Room* southHouse = new Room("South of the House", "You can see the main door entrance of the house\nThere's also a mailbox.");
	Room* logCabin = new Room("Log cabin", "There's quite a lot of log rests all around. There's an axe firmly fixed in a huge tree stump.");
	Room* cave = new Room("Cave", "That's a cave.");
	Room* basement = new Room("Basement", "");
	Room* livingRoom = new Room("Living Room", "");
	Room* kitchen = new Room("Kitchen", "");

	entities.push_back(northHouse);
	entities.push_back(westHouse);
	entities.push_back(eastHouse);
	entities.push_back(southHouse);
	entities.push_back(logCabin);
	entities.push_back(cave);
	entities.push_back(basement);
	entities.push_back(livingRoom);
	entities.push_back(kitchen);

	// Exits
	Exit* exSouthHouseAndLivingRoom = new Exit("Exit 1", "Exit between South House and Living Room", "north", "south", southHouse, livingRoom);
	Exit* exSouthHouseAndWestHouse = new Exit("Exit 2", "Exit between South House and West House", "west", "east", southHouse, westHouse);
	/*Exit* exWestHouseAndCave = new Exit("Exit 3", "Exit between West House and Cave", "west", "east", westHouse, cave);
	Exit* exWestHouseAndLogCabin = new Exit("Exit 4", "Exit between West House and Log Cavin", "north", "south", westHouse, logCabin);
	Exit* exWestHouseAndBasement = new Exit("Exit 5", "Exit between West House and Basement", "east", "west", westHouse, basement);
	Exit* exLogCabinAndNorthHouse = new Exit ("Exit 6", "Exit between Log Cabin and North House", "east", "west", logCabin, northHouse);
	Exit* exNorthHouseAndEastHouse = new Exit("Exit 7", "Exit between North House and East House", "east", "north", northHouse, eastHouse);
	Exit* exEastHouseAndSouthHouse = new Exit("Exit 8", "Exit between East House and South House", "south", "east", northHouse, eastHouse);
	Exit* exBasementAndLivingRoom = new Exit("Exit 9", "Exit between Basement and Living Room", "west", "east", basement, livingRoom);
	Exit* exLivingRoomAndKitchen = new Exit("Exit 10", "Exit between Living Room and Kitchen", "west", "east", livingRoom, kitchen);*/

	entities.push_back(exSouthHouseAndLivingRoom);
	entities.push_back(exSouthHouseAndWestHouse);
	/*entities.push_back(exWestHouseAndCave);
	entities.push_back(exWestHouseAndLogCabin);
	entities.push_back(exWestHouseAndBasement);
	entities.push_back(exLogCabinAndNorthHouse);
	entities.push_back(exNorthHouseAndEastHouse);
	entities.push_back(exEastHouseAndSouthHouse);
	entities.push_back(exBasementAndLivingRoom);
	entities.push_back(exLivingRoomAndKitchen);*/
	

	player = new Player("The Player", "This a future Hero", southHouse);

	entities.push_back(player);
}

World::~World() {
	std::cout << "Executing World Entity Destroyer" << std::endl;
	for (Entity *entity : entities) {
		std::cout << "Executing Destroyer for Entity " << entity->name << std::endl;
		delete entity;
	}
}