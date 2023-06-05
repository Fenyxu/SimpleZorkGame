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

	addEntitiesToVector(entities, northHouse, westHouse, eastHouse, southHouse, logCabin, cave, basement, livingRoom, kitchen);

	// Exits
	Exit* exSouthHouseAndLivingRoom = new Exit("", "", southHouse, livingRoom);
	Exit* exSouthHouseAndWestHouse = new Exit("", "", southHouse, westHouse);
	Exit* exWestHouseAndCave = new Exit("", "", westHouse, cave);
	Exit* exWestHouseAndLogCabin = new Exit("", "", westHouse, logCabin);
	Exit* exWestHouseAndBasement = new Exit("", "", westHouse, basement);
	Exit* exLogCabinAndNorthHouse = new Exit ("", "", logCabin, northHouse);
	Exit* exNorthHouseAndEastHouse = new Exit("", "", northHouse, eastHouse);
	Exit* exEastHouseAndSouthHouse = new Exit("", "", northHouse, eastHouse);
	Exit* exBasementAndLivingRoom = new Exit("", "", basement, livingRoom);
	Exit* exLivingRoomAndKitchen = new Exit("", "", livingRoom, kitchen);

	addEntitiesToVector(entities, exSouthHouseAndLivingRoom, exSouthHouseAndWestHouse, exWestHouseAndCave, exWestHouseAndLogCabin, exWestHouseAndBasement, exLogCabinAndNorthHouse,
		exNorthHouseAndEastHouse, exEastHouseAndSouthHouse, exBasementAndLivingRoom, exLivingRoomAndKitchen);
	

	Player* player = new Player("The Player", "This a future Hero", southHouse);

	entities.push_back(player);
}

World::~World() {
	std::cout << "Executing World Entity Destroyer" << std::endl;
	for (Entity *entity : entities) {
		std::cout << "Executing Destroyer for Entity " << entity->name << std::endl;
		delete entity;
	}
}

void addEntitiesToVector(std::vector<Entity*> entities, std::vector<Entity*> entitiesToAdd) {
	for (Entity* ent : entitiesToAdd)
		entities.push_back(ent);
}