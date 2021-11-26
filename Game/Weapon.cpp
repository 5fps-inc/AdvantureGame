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

float Weapon::get_critchanse()
{
	return crit_chanse;
}

string Weapon::get_type()
{
	return type;
}

string Weapon::get_rare()
{
	return rare;
}
