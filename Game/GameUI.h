#pragma once
#include <Windows.h>
#include "Player.h"
#include "Weapon.h"
#include <stdlib.h>
#include "Settings.h"
#include "Stranger.h"
#include "Location.h"
#include "Enemy.h"
void ShowMenu();
void ShowMenu(bool isNew);
void ShowActions(string location);
void ShowBattle(Player P, Enemy EN, int p_curcd, int en_curcd);

static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);