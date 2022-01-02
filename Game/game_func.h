#ifndef GAME_FUNC
#define GAME_FUNC
#include "Player.h"
#include "Weapon.h"
#include <stdlib.h>
#include "Settings.h"
#include "Stranger.h"
#include "Location.h"
#include "Enemy.h"

using namespace std;

void GoStory(Stranger S, string my_name, Player &P, Settings Set);
void printDialog(string who, string what, string my_name, int color);

int RandNum(int min, int max); //Число от мин до макс
string rName(int length);  // Случайное название
string RandomWeaponType(); // Тип оружие рандом (Лук копье и тд)

void DescribeWeapon(Weapon wep);

void printMap(string location, Player &P);
void lookUp(Location LOC, Player &P);
void Looting(Location LOC, Player& P);
void Fiting(Location LOC, Player& P);

void PickUpItem(Player& P, int id_item);

void Waiting(int time, char type, int sec); // type = l    |⃞⃞⃞    | type = t {     ☺   }
#endif // !GAME_FUNC
