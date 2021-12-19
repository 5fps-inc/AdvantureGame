#include "Player.h"
#include "Weapon.h"
#include <string>
using namespace std;

Player::Player(int l, int c, Weapon wep, string loc)
{
	lvl = l;
	coin = c;
	my_weapon = wep;
	location = loc;
}
int Player::get_lvl()
{
	return lvl;
}

int Player::get_coins()
{
	return coin;
}

void Player::set_name(string n)
{
	name = n;
}

string Player::get_name()
{
	return name;
}

int Player::Inventory_Iditem_OF_slot(int id_slot)
{
	return Inventory[id_slot][0];
}

int Player::Inventory_Count_of_items(int id_slot)
{
	return Inventory[id_slot][1];
}

void Player::Inventory_set_Id_count(int id_slot, int id_item, int count)
{
	Inventory[id_slot][0] = id_item;
	Inventory[id_slot][1] = count;
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

string Player::get_location()
{
	return location;
}

void Player::go_location(string s)
{
	location = s;
}

float Player::get_maxhp()
{
	return MaxHp;
}

float Player::get_hp()
{
	return Hp;
}

float Player::get_armor()
{
	return armor;
}

void Player::set_maxhp(float mhp)
{
	MaxHp = mhp;
}

void Player::set_hp(float hp)
{
	Hp = hp;
}

void Player::set_armor(float ar)
{
	armor = ar;
}


