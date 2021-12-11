#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <locale>
#include "game_func.h"
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
    tt = wep.get_rare();
    if (tt == "обычное")
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREY);
        cout << "=============================================\n";
    }
    if (tt == "редкое")
    {
        SetConsoleTextAttribute(h, CL_BLACK_BLU);
        cout << "=============================================\n";
    }
    cout << " |" << wep.get_name() << "|" << "\nУрон: " << wep.get_damage() << "\nКрит: " << wep.get_crit() << "\nВремя между ударами: " << wep.get_cd() << endl;
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
        s = "деревня";
        cout << "\n Вы прибыли в пункт назначения) "<< s << endl;
    }
    if (s.compare("tent") == 0)
    {
        cout << "Это проверка на дебелизм разраба\n Система ожидания \n";
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "-----";
        }
        s = "палатка";
        cout << "\n Вы прибыли в пункт назначения) " << s << endl;
    }
    if (s.compare("field") == 0)
    {
        cout << "Это проверка на дебелизм разраба\n Система ожидания \n";
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "-----";
        }
        s = "полянка";
        cout << "\n Вы прибыли в пункт назначения) " << s << endl;
    }
    P.go_location(s);
}

void lookUp(Location LOC)
{
    int num_input;
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t" << LOC.get_location_name() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

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
        system("cls");
        Looting(LOC);
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

void Looting(Location LOC)
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t Локация: " << LOC.get_location_name() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    int difficult;
    if (LOC.get_location_name() == "полянка") difficult = 40;

    cout << "Сложность " << difficult << "% что ты встретишь врага" << endl;
    cout << "1 - Пробовать\n";
    cout << "0 - Не ну нафиг\n";
    int in;
    cin >> in;
    while ((in < 0) && (in > 1)) cin >> in;
    
    while (in != 0)
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREEN);
        cout << "Лутаюсь . . .\n";
        for (int i = 0; i < 10; i++)
        {
            cout << "-~-~-~";
            Sleep(1000);
        }
        cout << "\n";
        if (RundNum(1, 99) > difficult)
        {
            cout << "Ты нашел: ";
            int rund_id = RundNum(1,99);
            cout << "Проверка . Рандомное число: " << rund_id << endl;
            int TEMP_rund = 0;
            int i = 0;
            while (!((TEMP_rund < rund_id) && (rund_id < LOC.get_arrch(i))))
            {
                TEMP_rund = LOC.get_arrch(i);
                i++;
                if (i > 10)
                {
                    break;
                }
            }
            cout << "Выпал предмет: " << i << endl;
        }
        else
        {
            SetConsoleTextAttribute(h, CL_BLACK_RED);
            cout << "Драка \n";
            SetConsoleTextAttribute(h, CL_BLACK_WHITE);
        }
        system("pause");
        system("cls");
        SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
        cout << "\t Локация: " << LOC.get_location_name() << endl;
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
        cout << "Сложность " << difficult << "%" << endl;
        cout << "1 - еще раз\n";
        cout << "0 - Не ну нафиг\n";
        cin >> in;
    }
    
}



void ShowMenu()
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t================ GAME 0.0.10 MENU ===================\n";
    cout << "\t1 - Новая игра\n";
    cout << "\t2 - Загрузить игру\n";
    cout << "\t3 - Настройки\n";
    SetConsoleTextAttribute(h, CL_YELLOW_BLACK);
    cout << "\t4 - Выход\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
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