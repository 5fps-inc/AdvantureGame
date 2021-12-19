#include "Enemy.h"
#include <fstream>

Enemy::Enemy(float hp, float damage, int cd, string enName, string tt)
{
	Hp = hp;
	Damage = damage;
	Coold = cd;
	EnemyName = enName;
	txt = tt;
	ifstream file(tt);
	getline(file,s1);
	getline(file,s2);
	getline(file,s3);
	getline(file,s4);
	file.close();
}

Enemy::Enemy()
{
}

string Enemy::Get_s1()
{
	return s1;
}

string Enemy::Get_s2()
{
	return s2;
}

string Enemy::Get_s3()
{
	return s3;
}

string Enemy::Get_s4()
{
	return s4;
}

string Enemy::get_name()
{
	return EnemyName;
}

int Enemy::get_cd()
{
	return Coold;
}

float Enemy::get_damage()
{
	return Damage;
}

float Enemy::get_hp()
{
	return Hp;
}

void Enemy::add_hp(float hp)
{
	Hp += hp;
}
