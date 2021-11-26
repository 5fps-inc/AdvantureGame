#include <iostream>
#include "game_func.h"
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <locale>
#include "Player.h"

using namespace std;
using std::cout;

const int CL_BLACK_WHITE = 15;
const int CL_BLACK_RED = 12;
const int CL_YELLOW_BLACK = 96;
const int CL_GREEN_WHITE = 39;

const int CL_BLACK_BLU = 1;
const int CL_BLACK_GREY = 8;
const int CL_BLACK_GREEN = 2;
const int CL_BLACK_PURP = 5;
const int CL_BLACK_YELLOW = 6;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int RundNum(int min, int max)
{
	// Получить случайное число - формула
	int num = min + rand() % (max - min + 1);
	return num;
}

string rName(int length)
{
    char consonents[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z' };
    char vowels[] = { 'a','e','i','o','u','y' };

    string name = "";

    int random = rand() % 2;
    int count = 0;

    for (int i = 0; i < length; i++) {

        if (random < 2 && count < 1) {
            name = name + consonents[rand() % 19];
            count++;
        }
        else {
            name = name + vowels[rand() % 5];
            count = 0;
        }

        random = rand() % 2;

    }

    return name;
}

string RundomWeaponType()
{
    int a = RundNum(1,5);
    switch (a)
    {
    case 1:
        return "Sword";
        break;
    case 2:
        return "Axe";
        break;
    case 3:
        return "Speer";
        break;
    case 4:
        return "Knife";
        break;
    case 5:
        return "Bow";
        break;
    default:
        return "";
        break;
    }
}

void DescribeWeapon(Weapon wep)
{
    string tt;
    string picture;
    tt = wep.get_type();
    if (tt == "булава")
    {
        picture = "----0";
    }
    if (tt == "меч")
    {
        picture = "-|---";
    }
    tt = wep.get_rare();
    if (tt == "обычное")
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREY);
        cout << "=============================================\n";
        cout << picture;
    }
    if (tt == "редкое")
    {
        SetConsoleTextAttribute(h, CL_BLACK_BLU);
        cout << "=============================================\n";
        cout << picture;
    }
    cout << " |" << wep.get_name() << "|" << " Урон " << wep.get_damage() << " Крит " << wep.get_crit() << " Крит шанс " << wep.get_critchanse() << endl;
    cout << "=============================================\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}


void ShowMenu()
{
    cout << "================ GAME 0.0.5 MENU ===================\n";
    cout << "1 - Новая игра\n";
    cout << "2 - Загрузить игру\n";
    cout << "3 - Выход\n";
}


void ShowActions(int lvl)
{
    if(lvl > 1) 
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREEN);
        cout << "1 - Показать мою стату\n";
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    }
    if (lvl > 2)
    {
        SetConsoleTextAttribute(h, CL_BLACK_RED);
        cout << "2 - Пойти пофармить\n";
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    }
    if (lvl > 1)
    {
        SetConsoleTextAttribute(h, CL_BLACK_BLU);
        cout << "3 - В город\n";
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    }
    
    cout << "4 - Сюжет\n";
    cout << "5 - Выход\n";
}

bool Payedlvl3 = false;


void GoStory(int lvl, string my_name, Player &P)
{
    string s;
    string s2;
    int N;
    int d;
    int type;
    int color;
    if ((lvl == 1) or (lvl == 2))
    {
        type = 1; // ТИП диалога
    }
    else if (lvl = 3)
    {
        type = 2; // Тип Задонать 
    }
    ifstream in;
    setlocale(LC_ALL, "Russian");
    switch (type)
    {
    case 1:
        in.open("StoryLvl" + to_string(lvl) + ".txt");
        in >> color;
        in.get();
        getline(in, s);
        while (s != "КОНЕЦ")
        {
            if (s == "Я")
            {
                getline(in, s);
                printDialog(my_name, s, my_name, CL_BLACK_GREEN);
                Sleep(1000);
            }
            if (s == "ВЫБОР")
            {
                in >> N;
                in.get();
                for (int i = 1; i <= N; i++)
                {
                    cout << i << " - ";
                    getline(in, s);
                    printDialog("", s, my_name, CL_BLACK_YELLOW);
                }
                cin >> d;
                while ((d < 1) || (d > N))
                {
                    cin >> d;
                }
                string temp;
                for (int i = 1; i <= d; i++)
                {
                    getline(in, s);
                    temp = s;
                }
                while (d < N)
                {
                    getline(in, s);
                    d++;
                }

                getline(in, s2);
                printDialog(s2, temp, my_name, color);
                Sleep(1000);
            }
            if (s == "КАДР")
            {
                system("cls");
                for (int i = 0; i < 10; i++)
                {
                    getline(in, s);
                    printDialog("", s, my_name, color);
                }
                system("pause");
            }
            if (s == "КТО")
            {
                getline(in, s2);
                getline(in, s);
                printDialog(s2, s, my_name, color);
                Sleep(1000);
            }
            getline(in, s);
        }
        system("pause");
        if (lvl == 1) { P.lvlup(); }
        if (lvl == 2) { P.lvlup(); }
        break;
    case 2:
        in.open("StoryLvl" + to_string(lvl) + ".txt");
        in >> color;
        in.get();
        for (int i = 0; i < 10; i++)
        {
            getline(in, s);
            printDialog("", s, my_name, color);
        }
        bool b;
        if (lvl == 3) { b = Payedlvl3; }

        break;
    default:
        break;
    }
    in.close();
}


void printDialog(string who, string what, string my_name, int color)
{
    if (who == my_name)
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREEN);
        cout << my_name << ": ";
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
        cout << what << endl;
    }
    else
    {
        SetConsoleTextAttribute(h, color);
        cout << who << ": ";
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
        cout << what << endl;
    }
}


int SetRundomColorOfRare()
{
    int s = RundNum(1, 31);
    if (s <= 16)
    {
        return CL_BLACK_GREY;
    }
    if ((s > 16) && (s <= 24))
    {
        return CL_BLACK_GREEN;
    }
    if ((s > 24) && (s <= 28))
    {
        return CL_BLACK_BLU;
    }
    if ((s > 28) && (s <= 30))
    {
        return CL_BLACK_PURP;
    }
    if ((s > 30) && (s <= 31))
    {
        return CL_BLACK_YELLOW;
    }
    else
    {
        return 15;
    }
}