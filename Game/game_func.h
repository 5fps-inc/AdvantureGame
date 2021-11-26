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

// ������� ��� ������ ����
int RundNum(int min, int max); //����� �� ��� �� ����
string rName(int length);  // ��������� ��������

string RundomWeaponType(); // ��� ������ ������ (��� ����� � ��)

void DescribeWeapon(Weapon wep);

#endif // !GAME_FUNC

