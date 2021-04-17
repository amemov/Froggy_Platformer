// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Item class
/* add() - adds object to the Player inventory */  
#ifndef ITEM_H
#define ITEM_H
class Item {
	private:
		std::string item_name;
		int what_impact;
		int impact;

	public:
		Item(std::string item_name, int what_impact, int impact);
		void static add();
		std::string get_name() { return item_name; };
		int get_stat() { return what_impact; };
		int get_impact() { return impact; };
};
#endif
