#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Weapon.h"
using namespace std;

class Player
{
private:
	string name;
	int coin;
	Weapon my_weapon;
	int lvl;
	string location;
	int Inventory[10][2];

public:
	Player(int l, int c, Weapon wep, string loc);
	int get_lvl();
	void lvlup();

	int get_coins();
	void addCoin(int a);

	void set_name(string name);
	string get_name();

	// ---------------- »Õ¬≈Õ“¿–‹ ---------

	int Inventory_Id_OF_slot(int id_slot);
	int Inventory_Count_of_items(int id_slot);
	void Inventory_set_Id_count(int id_slot, int id_item, int count);

	// -------------------------------------
	
	Weapon pickUpWeapon();
	Weapon get_weapon();

	string get_location();
	void go_location(string s);

	bool loc_mountain_isopen;
	bool loc_cave_isopen;
	bool loc_desert_isopen;
	bool loc_forest_isopen;
};
#endif // !PLAYER

