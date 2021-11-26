#ifndef GAME_FUNC
#define GAME_FUNC
#include "Player.h"
#include "Weapon.h"
#include <stdlib.h>
using namespace std;

void ShowMenu();
void ShowActions(int lvl);

void GoStory(int lvl, string my_name, Player &P);
void printDialog(string who, string what, string my_name, int color);
bool printStringAsChoice(string s, string s2);

// Функции для работы игры
int RundNum(int min, int max); //Число от мин до макс
string rName(int length);  // Случайное название

string RundomWeaponType(); // Тип оружие рандом (Лук копье и тд)

void DescribeWeapon(Weapon wep);

#endif // !GAME_FUNC

