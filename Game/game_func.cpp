#include <iostream>
#include "game_func.h"
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <locale>
#include "Player.h"
#include "Stranger.h"
#include "Settings.h"

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
    if (tt == "дробящее")
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

string NameOfId(int i)
{
    switch (i)
    {
    case 0:
        return "монета";
        break;
    default:
        return "хз че за предмет";
        break;
    }
}


void printMap(string location, Player &P)
{
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "Локация: \t" << P.get_location() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    cout << "Идти\n";
    if (P.get_location() != "палатка") { cout << "\tК палатке: {tent}\n"; }
    if (P.get_location() != "деревня") { cout << "\tВ деревню: {village}\n"; }
    if (P.get_location() != "полянка") { cout << "\tНа полянку: {field}\n"; }
    if ((P.get_location() != "пустыня") && (P.loc_desert_isopen))
    {
        cout << "\tВ пустыню: {desert}\n";
    }
    if ((P.get_location() != "Гора") && (P.loc_mountain_isopen))
    {
        cout << "\tВ горы: {mountain}\n";
    }
    string s;
    cin >> s;
    while (!((s.compare("tent") == 0) || (s.compare("village") == 0) || (s.compare("field") == 0) || (s.compare("desert") == 0) || (s.compare("mountain") == 0)))
    {
        cout << "Введи значение из {} \n";
        cin >> s;
    }
    cout << "\n";
    if (s.compare("village") == 0)
    {
        cout << "Это проверка на дебелизм разраба\n Система ожидания \n";
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "-----";
        }
        cout << "\n Вы прибыли в пункт назначения)\n";
    }
    if (s == "village")
        s = "деревня";
    else if (s == "tent")
        s = "палатка";
    P.go_location(s);
}

void lookUp(Location LOC)
{
    int num_input;
    cout << "\t" << LOC.get_location_name() << endl;
    cout << "1 - Полутаться\n";
    for (int i = 0; i < 5; i++)
    {
        if (LOC.get_Person_name_by_num(i) != "")
        {
            cout << 2 + i << " - Поговорить с " << LOC.get_Person_name_by_num(i) << endl;
        }
    }
    cout << "0 - Уйти\n";
    cin >> num_input;
    if (num_input == 1)
    {
        cout << "Фарм\n";
    }
    else if ((num_input > 1) && (num_input < 7) && (LOC.get_Person_name_by_num(num_input) != ""))
    {
        cout << "Функция типо поговорить с челом\n";
    }
    else if (num_input > 7)
    {
        cout << "Сорян ты ввел что-то не так пожтому попробуй позже и по другому\n";
    }

}


void ShowMenu()
{
    cout << "================ GAME 0.0.8 MENU ===================\n";
    cout << "1 - Новая игра\n";
    cout << "2 - Загрузить игру\n";
    cout << "3 - Настройки\n";
    cout << "4 - Выход\n";
}


void ShowActions(string location)
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t Локация: " << location << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    cout << "\n";

    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "1 - Показать мою стату\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    SetConsoleTextAttribute(h, CL_BLACK_BLU);
    cout << "2 - Переместится\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    SetConsoleTextAttribute(h, CL_BLACK_PURP);
    cout << "3 - Осмотреться\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    cout << "0 - Выход\n";
}


void GoStory(Stranger S, string my_name, Player &P, Settings mySet)
{
    string s;
    string s2;
    int N;
    int d;
    int color;
    int wasinput;
    ifstream in;
    setlocale(LC_ALL, "Russian");
    in.open(S.get_txt());
    in >> color;
    in.get();
    getline(in, s);
    while (s != "КОНЕЦ")
        {
            if (s == "Я")
            {
                getline(in, s);
                printDialog(my_name, s, my_name, CL_BLACK_GREEN);
                Sleep(mySet.get_DialogSpeed()*1000);
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
                wasinput = d;
                while (d < N)
                {
                    getline(in, s);
                    d++;
                }

                getline(in, s2);
                printDialog(s2, temp, my_name, color);
                Sleep(mySet.get_DialogSpeed()*1000);
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
                Sleep(mySet.get_DialogSpeed()*1000);
            }
            getline(in, s);
    }
    system("pause");
    if ((P.get_lvl() == 1) && (S.get_stranger_name() == "Бандит Инококентий"))
    { 
        P.lvlup();
        if (wasinput == 1)
        {
            P.addCoin(10);
        }
        else
        {
            P.addCoin(5);
        }
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