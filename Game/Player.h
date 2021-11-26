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
public:
	Player(int l, int c, Weapon wep);
	int get_lvl();
	void set_name(string name);
	string get_name();

	void lvlup();
	void addCoin(int a);
	Weapon pickUpWeapon();
	Weapon get_weapon();
};
#endif // !PLAYER

