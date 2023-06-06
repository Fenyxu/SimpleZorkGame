#include "Item.h"

Item::Item(std::string name, std::string description, ItemType itemType)
	: Entity{ name, description }, itemType{ itemType } {
	type = ITEM;
}

Item::~Item() {}

void Item::AddItemInside(Item* item) {
	contains.push_back(item);
}

void Item::RemoveItemFromInside(Item* item) {
	contains.remove(item);
}