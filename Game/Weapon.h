#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;
class Weapon
{
public:
	Weapon(string n, float d, float c, int cd, string r)
	{
		name = n;
		damage = d;
		crit = c;
		cooldown = cd;
		rare = r;
	}
	Weapon()
	{
		name = "";
		damage = 0.0;
		crit = 0.0;
		cooldown = 0;
		rare = "";
	}
	string get_name();
	float get_damage();
	float get_crit();
	int get_cd();
	string get_rare();
private:
	string name = "";
	float damage = 0.0;
	float crit = 0.0;
	int cooldown = 0;
	string rare = "";
};
#endif 

