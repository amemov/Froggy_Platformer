#include "stdafx.h"
#include "Player.h"
Player::Player() {			//what_impact
	HP = PLAYER_HP;			//1
	ATTACK = PLAYER_ATTACK; //2
	SPEED = PLAYER_SPEED;	//3
	JUMP = PLAYER_JUMP;		//4
	inventory_count = 0;
	X = 3;
	Y = 3;
}
void Player::set_HP(int HP) {
	this->HP += HP;
}
void Player::set_ATTACK(int ATTACK) {
	this->ATTACK += ATTACK;
}
void Player::set_SPEED(int SPEED) {
	this->SPEED = SPEED;
}
void Player::set_JUMP(int JUMP) {
	this->JUMP = JUMP;
}
Player& operator+=(Player& what, Item t) {
	what.Inventory.push_back(t);
	return what;
}
void Player::set_inv_count(int count) {
	inventory_count += count;
}
void Player::print_inventory() {
	std::cout << std::setw(10) << "\nInventory\n";
	int i = 1;
	for (auto c : Inventory)
	{
		std::cout << i << ". " << c.get_name() << "\t";
		i += 1;
	}
	std::cout << "\n";
}
void Player::use_inventory() {
	int item_number;
	
	// Prompt item number
	std::cout << std::setw(10) << "Which item to use?\n";
	std::cout << "Item: ";
	std::cin >> item_number;
	std::cin.ignore(1000, '\n');

	// Check if the inventory empty
	if (inventory_count == 0)
		std::cout << std::setw(10) << "Inventory is empty!\n";
	else 
	{
		// Find the stat and impact of the item. Use it, erase it, and update the counter
		int impact; int stat;
		impact = Inventory[item_number - 1].get_impact(); stat = Inventory[item_number - 1].get_stat();
		
		switch (stat) {
			case 1: set_HP(impact);		inventory_count--; break; // HP
			case 2: set_ATTACK(impact); inventory_count--; break; // ATTACK
			case 3: set_SPEED(impact);	inventory_count--; break; // SPEED
			case 4: set_JUMP(impact);	inventory_count--; break; // JUMP
		}
		
		Inventory.erase(Inventory.begin() + (item_number - 1));
	}
	 
}
void Player::save_inv() {
	// Open inventory file. Write data from vector
	std::ofstream inv_file;  
	inv_file.open("Inventory.txt");
	
	for (auto c : Inventory)
		inv_file << c.get_name() << c.get_stat() << c.get_impact();
	
	// Close file	
	inv_file.close();
}
/*void Player::draw() {

	init_pair(2,COLOR_BLUE,COLOR_RED);
	std::cout << (char)PLAYER;
}*/