#include <iostream>
#include "Entity.h"

int main() {
	std::cout << "Hello" << std::endl;

	Entity *entity1 = new Entity();
	entity1->name = "Name1";

	std::cout << entity1->name << std::endl;

	return 0;
}