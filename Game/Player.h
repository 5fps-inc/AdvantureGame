#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Weapon.h"
using namespace std;

class Player
{
private:
	string name;
	string location;	
	Weapon my_weapon;
	int coin;
	int lvl;
	int Inventory[10][2];
	float MaxHp = 50.0;
	float Hp = 50.0;
	float armor = 0.0;

public:
	Player(int l, int c, Weapon wep, string loc);
	int get_lvl();
	void lvlup();

	int get_coins();
	void addCoin(int a);

	void set_name(string name);
	string get_name();

	// ---------------- »Õ¬≈Õ“¿–‹ ---------

	int Inventory_Iditem_OF_slot(int id_slot);
	int Inventory_Count_of_items(int id_slot);
	void Inventory_set_Id_count(int id_slot, int id_item, int count);

	// -------------------------------------
	
	Weapon get_weapon();

	string get_location();
	void go_location(string s);

	bool loc_mountain_isopen;
	bool loc_cave_isopen;
	bool loc_desert_isopen;
	bool loc_forest_isopen;

	//---------------hp-----------
	float get_maxhp();
	float get_hp();
	float get_armor();

	void set_maxhp(float mhp);
	void set_hp(float hp);
	void set_armor(float ar);
	//--------------------------
};
#endif // !PLAYER

