#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include <wchar.h>
#include <conio.h>
#include "game_func.h"
#include "Player.h"
#include "Stranger.h"
#include "Settings.h"
#include "Inventory.h"
#include "Enemy.h"

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

void printMap(string location, Player &P)
{
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "Локация: \t" << P.get_location() << endl;
    cout << "\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    // Выыод вариантов
    cout << "Идти\n";
    cout << "\tОстаться тут: {нет}\n\n";
    if (P.get_location() != "палатка") { cout << "\tК палатке: {палатка}\n\n"; }
    if (P.get_location() != "деревня") { cout << "\tВ деревню: {деревня}\n\n"; }
    if (P.get_location() != "полянка") { cout << "\tНа полянку: {полянка}\n\n"; }
    if ((P.get_location() != "пустыня") && (P.loc_desert_isopen))
    {
        cout << "\tВ пустыню: {пустыня}\n\n";
    }
    if ((P.get_location() != "Гора") && (P.loc_mountain_isopen))
    {
        cout << "\tВ горы: {гора}\n\n";
    }
    // ввод места куда идем
    string s;
    cin >> s;
    cout << "\n";
    if ((s.compare("палатка") == 0) || (s.compare("деревня") == 0) || (s.compare("полянка") == 0) || ((s.compare("пустыня") == 0) && (P.loc_desert_isopen)) || ((s.compare("гора") == 0) && (P.loc_mountain_isopen)))
    {
        Waiting(5, 't', 100);
        cout << "Вы прибыли -> " << s << endl;
        P.go_location(s);
    }
    else if (s.compare("нет") == 0)
    {
        cout << "Остались на месте \n";
    }
    else
    {
        cout << "2to`0vfd[psflmv`/.7,.gerg, это типо ничего не получилось введи потом правильно\n";
    }
    Sleep(1500);
}

void lookUp(Location LOC, Player& P)
{
    int num_input;
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\tЛокация: " << LOC.get_location_name() << endl;
    cout << "\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    cout << "1 - Полутаться\n\n";
    for (int i = 0; i < 5; i++)
    {
        if (LOC.get_Person_name_by_num(i) != "")
        {
            cout << 2 + i << " - Поговорить с " << LOC.get_Person_name_by_num(i) << endl;
            cout << "\n";
        }
    }
    cout << "0 - Уйти\n";
    cin >> num_input;
    if (num_input == 1)
    {
        system("cls");
        Looting(LOC, P);
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

void Looting(Location LOC, Player& P)
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t Локация: " << LOC.get_location_name() << endl;
    cout << "\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    int difficult;
    if (LOC.get_location_name() == "полянка") difficult = 60;

    cout << "Сложность " << difficult << "% что ты встретишь врага" << endl;
    cout << "\n";
    cout << "1 - Пробовать\n\n";
    cout << "0 - Не ну нафиг\n\n";

    int in;
    cin >> in;
    while ((in < 0) && (in > 1)) cin >> in;
    
    while (in != 0)
    {
        Waiting(10, 'l', 100);
        if (RundNum(1, 99) > difficult)
        {
            cout << "Ты нашел: ";
            int rund_id = RundNum(1,99);
            cout << "Проверка . Рандомное число: " << rund_id << endl;
            int TEMP_rund = 0;
            int i = 0;
            while (!((TEMP_rund < rund_id) && (rund_id <= LOC.get_arrch(i))))
            {
                TEMP_rund = LOC.get_arrch(i);
                i++;
                if (i > 10)
                {
                    break;
                }
            }
            cout << "Значит выпало: " << NameOfId(LOC.get_arr(i)) << endl;
            int id_item = LOC.get_arr(i);
            PickUpItem(P, id_item);
        }
        else
        {
            SetConsoleTextAttribute(h, CL_BLACK_RED);
            cout << "Драка \n";
            Sleep(1000);
            SetConsoleTextAttribute(h, CL_BLACK_WHITE);
            Fiting(LOC,P);
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

void Fiting(Location LOC, Player& P)
{
    int my_cur_cd = P.get_weapon().get_cd();
    int en_cur_cd;
    Enemy* en = new Enemy(10.0, 1.0, 1, "Заяц", "Enemy_Rabbit.txt");
    if (LOC.get_location_name() == "полянка")
    {
        if (RundNum(1, 2) < 2)
        {
            //Типо 1 или 2 то ЭТО кролик
            Enemy* en = new Enemy(10.0,1.0,1,"Заяц", "Enemy_Rabbit.txt");
        }
        else
        {
            // Типо медведь
            delete en;
            Enemy* en = new Enemy(50.0, 20.0, 3, "Медведь", "Enemy_Bear.txt");
        }
    }
    
    en_cur_cd = (*en).get_cd();
    ShowBattle(P, (*en), my_cur_cd, en_cur_cd);

    cout << "ENTER - Драться\n";
    cout << "0 - Убежать\n";
    int input;
    input = _getch();
    while (input == 13)
    {
        if ((P.get_hp() > 0) && ((*en).get_hp() > 0))
        {
            my_cur_cd--;
            en_cur_cd--;
            ShowBattle(P, (*en), my_cur_cd, en_cur_cd);
            Sleep(100);

            if (my_cur_cd == 0)
            {
                if (RundNum(1,4) < 2)
                {
                    (*en).add_hp(-(P.get_weapon().get_crit() * P.get_weapon().get_damage()));
                    my_cur_cd = P.get_weapon().get_cd();
                }
                else
                {
                    (*en).add_hp(-(P.get_weapon().get_damage()));
                    my_cur_cd = P.get_weapon().get_cd();
                }
                
            }
            if (en_cur_cd == 0)
            {
                int damage = (*en).get_damage() - P.get_armor();
                if (damage < 0) damage = 0;
                P.set_hp(P.get_hp() - damage);
                en_cur_cd = (*en).get_cd();
            }
            ShowBattle(P, (*en), my_cur_cd, en_cur_cd);
            cout << "ENTER - Драться\n";
            cout << "0 - Убежать\n";
            input = _getch();
        }
        else
        {
            if (P.get_hp() > 0)
            {
                cout << "ТЫ победил\n";
                if ((*en).get_name() == "заяц")
                {
                    PickUpItem(P, 3);
                    cout << "Изнего выпало: " << NameOfId(3) << endl;
                }
                if ((*en).get_name() == "медведь")
                {
                    PickUpItem(P, 8);
                    cout << "Изнего выпало: " << NameOfId(8) << endl;
                }
            }
            else
            {
                cout << "ПРОИГРАл\n";
            }
            input = 0;
        }
    }
    delete en;
}

void PickUpItem(Player& P, int id_item)
{
    if ((Find_slotId_by_iditem(P, id_item) != -1) && (id_item != 0))
    {
        cout << "Такой предмет в инвентаре есть +1 \n";
        P.Inventory_set_Id_count(Find_slotId_by_iditem(P, id_item), id_item, P.Inventory_Count_of_items(Find_slotId_by_iditem(P, id_item)) + 1);
    }
    else
    {
        if (id_item != 0)
        {
            cout << "Такого предмета в инвентаре нету \n";
            if (Find_slotId_by_iditem(P, 0) != -1)
            {
                cout << "найден Пустой слот и в  него положили\n";
                P.Inventory_set_Id_count(Find_slotId_by_iditem(P, 0), id_item, 1);
            }
            else
            {
                cout << "Места в инвентаре нету\n";
            }
        }
        else
        {
            cout << "\n";
        }
    }
}

void Waiting(int time, char type, int sec)
{
    SetConsoleTextAttribute(h, CL_BLACK_BLU);
    system("cls");
    int curT = 0;
    int maxT = time;
    while (curT < maxT)
    {
        if (type == 'l')
        {
            cout << "|";
            for (int i = 0; i < curT; i++)
            {
                cout << "#";
            }
            for (int i = curT; i < maxT; i++)
            {
                cout << " ";
            }
            cout << "|";
        }
        if (type == 't')
        {
            cout << "|";
            for (int i = 0; i < curT; i++)
            {
                cout << " ";
            }
            cout << "@";
            for (int i = curT + 1; i < maxT; i++)
            {
                cout << " ";
            }
            cout << "|";
        }
        Sleep(sec);
        system("cls");
        curT++;
    }
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}



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

void ShowSettings(Settings MYSET)
{
    float DialogSpeed;
    system("cls");
    cout << "Скорость диалогов: " << MYSET.get_DialogSpeed() << endl;
    cout << " от 0 до 10 секунд\n Введите \t";
    cin >> DialogSpeed;
    MYSET.set_DialogSpeed(DialogSpeed);
    cout << "Скорость диалогов: " << MYSET.get_DialogSpeed() << endl;
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
    cout << " /|?     \t" << EN.Get_s2()<< endl;
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