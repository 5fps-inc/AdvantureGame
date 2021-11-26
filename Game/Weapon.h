#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;
class Weapon
{
public:
	Weapon(string n, float d, float c, float ch, string t, string r)
	{
		name = n;
		damage = d;
		crit = c;
		crit_chanse = ch;
		type = t;
		rare = r;
	}
	Weapon()
	{
		name = "";
		damage = 0;
		crit = 0;
		crit_chanse = 0;
		type = "";
		rare = "";
	}
	string get_name();
	float get_damage();
	float get_crit();
	float get_critchanse();
	string get_type();
	string get_rare();
private:
	string name = "";
	float damage = 0.0;
	float crit = 0.0;
	float crit_chanse = 0.0;
	string type = "";
	string rare = "";
};
#endif 

