#ifndef ENEMY_H
#define ENEMY_H

#include <string>
using namespace std;


class Enemy
{
private:
	float Hp;
	float Damage;
	int Coold;
	string s1;
	string s2;
	string s3;
	string s4;
	string EnemyName;
	string txt;
public:
	Enemy(float hp, float damage, int cd, string enName, string txt);
	Enemy();
	string Get_s1();
	string Get_s2();
	string Get_s3();
	string Get_s4();
	string get_name();
	int get_cd();
	float get_damage();
	float get_hp();

	void add_hp(float hp);
};


#endif // !ENEMY_H



