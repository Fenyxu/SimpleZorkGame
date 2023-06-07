#pragma once

#include "Entity.h"


enum ItemType {
    COMMON,
    WEAPON,
    BATTERY,
    CONSUMABLE
};

class Item :
    public Entity
{

public:
    Item(const std::string name, const std::string description, ItemType itemType = COMMON);
    ~Item();

private:
    ItemType itemType;
    bool hasSlots{ false };
    bool canBePlacedInsideContainer{ false };
    int baseDamage{ 0 };

public:
    void AddItemInside(Item* item);
    void RemoveItemFromInside(Item* item);
    void SetHasSlots(bool hasSlots) {
        this->hasSlots = hasSlots;
    }
    bool HasSlots() {
        return this->hasSlots;
    }
    void SetCanBePlacedInsideContainer(bool canBePlacedInsideContainer) {
        this->canBePlacedInsideContainer = canBePlacedInsideContainer;
    }
    bool CanBePlacedInsideContainer() {
        return this->canBePlacedInsideContainer;
    }
    void SetItemType(ItemType itemType) {
        this->itemType = itemType;
    }
    ItemType GetItemType() {
        return this->itemType;
    }
    int GetBaseDamage() const{
        return baseDamage;
    }
    void setBaseDamage(int baseDamage) {
        this->baseDamage = baseDamage;
    }
};
