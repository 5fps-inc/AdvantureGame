#include <string>
#include "Weapon.h"



string Weapon::get_name()
{
	return name;
}

float Weapon::get_damage()
{
	return damage;
}

float Weapon::get_crit()
{
	return crit;
}

int Weapon::get_cd()
{
	return cooldown;
}

string Weapon::get_rare()
{
	return rare;
}
