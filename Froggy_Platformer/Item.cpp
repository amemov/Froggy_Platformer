#include "stdafx.h"
#include "Item.h"
#include "Player.h"
Item::Item(std::string item_name, int what_impact, int impact) {
	this->item_name = item_name;
	this->what_impact = what_impact;
	this->impact = impact;
}

// adds object to the vector in Player?
void  Item::add() {
	// Initialize player Object
	Player object;
	
	// Create an Item
	Item tyt ("CHOKY MILK", 2, 20);

	// Add it to vector
	object = object + tyt;
}
