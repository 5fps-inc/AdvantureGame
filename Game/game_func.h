#ifndef GAME_FUNC
#define GAME_FUNC
#include "Player.h"
#include "Weapon.h"
#include <stdlib.h>
#include "Settings.h"
#include "Stranger.h"
#include "Location.h"

using namespace std;

void ShowMenu();
void ShowActions(string location);

void GoStory(Stranger S, string my_name, Player &P, Settings Set);
void printDialog(string who, string what, string my_name, int color);

// ������� ��� ������ ����
int RundNum(int min, int max); //����� �� ��� �� ����
string rName(int length);  // ��������� ��������

string RundomWeaponType(); // ��� ������ ������ (��� ����� � ��)

void DescribeWeapon(Weapon wep);

string NameOfId(int i);

void printMap(string location, Player &P);

void lookUp(Location LOC);

void Looting(Location LOC);


#endif // !GAME_FUNC

