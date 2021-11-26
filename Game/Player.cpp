#include "Player.h"
#include "Weapon.h"
#include <string>
using namespace std;

Player::Player(int l, int c, Weapon wep)
{
	lvl = l;
	coin = c;
	my_weapon = wep;
}
int Player::get_lvl()
{
	return lvl;
}

void Player::set_name(string n)
{
	name = n;
}

string Player::get_name()
{
	return name;
}

void Player::lvlup()
{
	lvl++;
}

void Player::addCoin(int a)
{
	coin += a;
}

Weapon Player::get_weapon()
{
	return my_weapon;
}


