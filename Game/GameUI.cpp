#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include <wchar.h>
#include <conio.h>
#include "GameUI.h"
#include "Colors.h"

void ShowMenu()
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t================ GAME 0.0.11 Меню ===================\n\n";
    cout << "\t1 - Новая игра\n\n";
    cout << "\t2 - Загрузить игру\n\n";
    cout << "\t3 - Настройки\n\n";
    SetConsoleTextAttribute(h, CL_YELLOW_BLACK);
    cout << "\t4 - Выход\n\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}

void ShowMenu(bool isnew)
{
    system("cls");
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t1 - Продолжить\n\n";
    cout << "\t2 - Настройки\n\n";
    cout << "\t0 - Выйти из игры\n\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}

void ShowActions(string location)
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t Локация: " << location << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    cout << "\n";

    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << " 1 - Инвентарь\n\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    SetConsoleTextAttribute(h, CL_BLACK_BLU);
    cout << " 2 - Переместится\n\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    SetConsoleTextAttribute(h, CL_BLACK_PURP);
    cout << " 3 - Осмотреться\n\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    cout << " 0 - Выход\n\n";
}

void ShowBattle(Player P, Enemy EN, int p_curcd, int en_curcd)
{
    system("cls");
    cout << setw(10) << P.get_name() << setw(10) << EN.get_name() << endl;
    cout << "  0      \t" << EN.Get_s1() << endl;
    cout << " /|?     \t" << EN.Get_s2() << endl;
    cout << "  ^      \t" << EN.Get_s3() << endl;
    cout << " / |     \t" << EN.Get_s4() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "HP:" << setw(7) << P.get_hp();
    SetConsoleTextAttribute(h, CL_BLACK_RED);
    cout << setw(10) << EN.get_hp() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "CD:" << setw(7) << p_curcd;
    SetConsoleTextAttribute(h, CL_BLACK_RED);
    cout << setw(10) << en_curcd << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}