#include "stdafx.h"
#include "Item.h"
Item::Item(std::string item_name, int what_impact, int impact) {
	this->item_name = item_name;
	this->what_impact = what_impact;
	this->impact = impact;
}
 
