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
public:
	Player(int l, int c, Weapon wep, string loc);
	int get_lvl();
	void lvlup();

	int get_coins();
	void addCoin(int a);

	void set_name(string name);
	string get_name();

	
	
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

