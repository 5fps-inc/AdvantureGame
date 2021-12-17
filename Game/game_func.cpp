#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <locale>
#include <iomanip>
#include <wchar.h>
#include "game_func.h"
#include "Player.h"
#include "Stranger.h"
#include "Settings.h"
#include "Inventory.h"

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
    if (tt == "�������")
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREY);
        cout << "=============================================\n";
    }
    if (tt == "������")
    {
        SetConsoleTextAttribute(h, CL_BLACK_BLU);
        cout << "=============================================\n";
    }
    cout << " |" << wep.get_name() << "|" << "\n����: " << wep.get_damage() << "\n����: " << wep.get_crit() << "\n����� ����� �������: " << wep.get_cd() << endl;
    cout << "=============================================\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}


void printMap(string location, Player &P)
{
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << L"�������: \t" << P.get_location() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    cout << "����\n";
    if (P.get_location() != "�������") { cout << "\t� �������: {tent}\n"; }
    if (P.get_location() != "�������") { cout << "\t� �������: {village}\n"; }
    if (P.get_location() != "�������") { cout << "\t�� �������: {field}\n"; }
    if ((P.get_location() != "�������") && (P.loc_desert_isopen))
    {
        cout << "\t� �������: {desert}\n";
    }
    if ((P.get_location() != "����") && (P.loc_mountain_isopen))
    {
        cout << "\t� ����: {mountain}\n";
    }
    string s;
    cin >> s;
    while (!((s.compare("tent") == 0) || (s.compare("village") == 0) || (s.compare("field") == 0) || (s.compare("desert") == 0) || (s.compare("mountain") == 0)))
    {
        cout << "����� �������� �� {} \n";
        cin >> s;
    }
    cout << "\n";
    if (s.compare("village") == 0)
    {
        cout << "��� �������� �� �������� �������\n ������� �������� \n";
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "-----";
        }
        s = "�������";
        cout << "\n �� ������� � ����� ����������) "<< s << endl;
    }
    if (s.compare("tent") == 0)
    {
        cout << "��� \n";
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "-----";
        }
        s = "�������";
        cout << "\n �� ������� � ����� ����������) " << s << endl;
    }
    if (s.compare("field") == 0)
    {
        cout << "��� �������� �� �������� �������\n ������� �������� \n";
        for (int i = 0; i < 5; i++)
        {
            Sleep(1000);
            cout << "-----";
        }
        s = "�������";
        cout << "\n �� ������� � ����� ����������) " << s << endl;
    }
    P.go_location(s);
}

void lookUp(Location LOC, Player& P)
{
    int num_input;
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t" << LOC.get_location_name() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    cout << "1 - ����������\n";
    for (int i = 0; i < 5; i++)
    {
        if (LOC.get_Person_name_by_num(i) != "")
        {
            cout << 2 + i << " - ���������� � " << LOC.get_Person_name_by_num(i) << endl;
        }
    }
    cout << "0 - ����\n";
    cin >> num_input;
    if (num_input == 1)
    {
        system("cls");
        Looting(LOC, P);
    }
    else if ((num_input > 1) && (num_input < 7) && (LOC.get_Person_name_by_num(num_input) != ""))
    {
        cout << "������� ���� ���������� � �����\n";
    }
    else if (num_input > 7)
    {
        cout << "����� �� ���� ���-�� �� ��� ������� �������� ����� � �� �������\n";
    }

}

void Looting(Location LOC, Player& P)
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t �������: " << LOC.get_location_name() << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    int difficult;
    if (LOC.get_location_name() == "�������") difficult = 50;

    cout << "��������� " << difficult << "% ��� �� ��������� �����" << endl;
    cout << "1 - ���������\n";
    cout << "0 - �� �� �����\n";
    int in;
    cin >> in;
    while ((in < 0) && (in > 1)) cin >> in;
    
    while (in != 0)
    {
        SetConsoleTextAttribute(h, CL_BLACK_GREEN);
        cout << "������� . . .\n";
        for (int i = 0; i < 10; i++)
        {
            cout << "-~-~-~";
            Sleep(100);
        }
        cout << "\n";
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
        if (RundNum(1, 99) > difficult)
        {
            cout << "�� �����: ";
            int rund_id = RundNum(1,99);
            cout << "�������� . ��������� �����: " << rund_id << endl;
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
            cout << "������ ������ id_item: " << LOC.get_arr(i) << endl;
            int id_item = LOC.get_arr(i);
            if (Find_slotId_by_iditem(P, id_item) != -1)
            {
                cout << "����� ������� � ��������� ���� +1 \n";
                P.Inventory_set_Id_count(Find_slotId_by_iditem(P, id_item), id_item,P.Inventory_Count_of_items(Find_slotId_by_iditem(P, id_item)) + 1);
            }
            else
            {
                cout << "������ �������� � ��������� ���� \n";
                if (Find_slotId_by_iditem(P, 0) != -1)
                {
                    cout << "������ ����\n";
                    P.Inventory_set_Id_count(Find_slotId_by_iditem(P, 0), id_item, 1);
                }
            }
        }
        else
        {
            SetConsoleTextAttribute(h, CL_BLACK_RED);
            cout << "����� \n";
            SetConsoleTextAttribute(h, CL_BLACK_WHITE);
            Fiting(LOC,P);
        }
        system("pause");
        system("cls");
        SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
        cout << "\t �������: " << LOC.get_location_name() << endl;
        SetConsoleTextAttribute(h, CL_BLACK_WHITE);
        cout << "��������� " << difficult << "%" << endl;
        cout << "1 - ��� ���\n";
        cout << "0 - �� �� �����\n";
        cin >> in;
    }
    
}

void Fiting(Location LOC, Player& P)
{
    string s1;
    string s2;
    string s3;
    string s4;
    string Enemy_name;
    float my_Hp = 50.0;
    int my_CD = P.get_weapon().get_cd();
    int my_cur_cd = my_CD;
    float en_Hp;
    int en_CD;
    int en_cur_cd;
    float en_DM;
    
    if (LOC.get_location_name() == "�������")
    {
        if (RundNum(1, 3) < 3)
        {
            //���� 1 ��� 2 �� ��� ������
            s1 = " (/__ / ) ";
            s2 = "(= '.' = )";
            s3 = "  (')_(') ";
            s4 = "  (')_(') ";
            Enemy_name = "����";
            en_Hp = 10.0;
            en_CD = 1;
            en_cur_cd = 1;
            en_DM = 1.0;
        }
        else
        {
            // ���� �������
            s1 = "` (').(')  ";
            s2 = "` (  ' o ')  ";
            s3 = " (' )_( ') ";
            s4 = "(,,)---(,,)";
            Enemy_name = "�������";
            en_Hp = 50.0;
            en_CD = 3;
            en_cur_cd = 3;
            en_DM = 20.0;
        }
    }
    

    system("cls");
    cout << "  0      " << s1 << endl;
    cout << " /|?     " << s2 << endl;
    cout << "  ^      " << s3 << endl;
    cout << " / |     " << s4 << endl;
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "HP:" << setw(5) << my_Hp;
    SetConsoleTextAttribute(h, CL_BLACK_RED);
    cout << Enemy_name << " HP:" <<  setw(5) << en_Hp << endl;
    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "CD:" << setw(5) << my_cur_cd;
    SetConsoleTextAttribute(h, CL_BLACK_RED);
    cout << Enemy_name << " CD:" << setw(5) << en_cur_cd << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    cout << "1 - �������\n";
    cout << "0 - �������\n";
    int input;
    cin >> input;
    while ((input > 1) && (input < 0))
    {
        cin >> input;
    }
    while (input != 0)
    {
        if ((my_Hp > 0) && (en_Hp > 0))
        {
            system("cls");
            my_cur_cd--;
            en_cur_cd--;
            cout << "  0      " << s1 << endl;
            cout << " /|?     " << s2 << endl;
            cout << "  ^      " << s3 << endl;
            cout << " / |     " << s4 << endl;
            cout << "HP:" << setw(5) << my_Hp;
            cout << Enemy_name << " HP:" << setw(5) << en_Hp << endl;
            cout << "CD:" << setw(5) << my_cur_cd;
            cout << Enemy_name << " CD:" << setw(5) << en_cur_cd << endl;
            Sleep(100);

            if (my_cur_cd == 0)
            {
                if (RundNum(1,4) < 2)
                {
                    en_Hp -= P.get_weapon().get_crit() * P.get_weapon().get_damage();
                    my_cur_cd = my_CD;
                }
                else
                {
                    en_Hp -= P.get_weapon().get_damage();
                    my_cur_cd = my_CD;
                }
                
            }
            if (en_cur_cd == 0)
            {
                my_Hp -= en_DM;
                en_cur_cd = en_CD;
            }
            system("cls");
            cout << "  0      " << s1 << endl;
            cout << " /|?     " << s2 << endl;
            cout << "  ^      " << s3 << endl;
            cout << " / |     " << s4 << endl;
            SetConsoleTextAttribute(h, CL_BLACK_GREEN);
            cout << "HP:" << setw(5) << my_Hp;
            SetConsoleTextAttribute(h, CL_BLACK_RED);
            cout << Enemy_name << " HP:" << setw(5) << en_Hp << endl;
            SetConsoleTextAttribute(h, CL_BLACK_GREEN);
            cout << "CD:" << setw(5) << my_cur_cd;
            SetConsoleTextAttribute(h, CL_BLACK_RED);
            cout << Enemy_name << " CD:" << setw(5) << en_cur_cd << endl;
            SetConsoleTextAttribute(h, CL_BLACK_WHITE);

            cout << "1 - ��������� ���\n";
            cout << "0 - �������\n";
            cin >> input;
        }
        else
        {
            if (my_Hp > 0)
            {
                cout << "�� �������\n";

            }
            else
            {
                cout << "��������\n";
            }
            input = 0;
        }
    }
}



void ShowMenu()
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t================ GAME 0.0.10 MENU ===================\n";
    cout << "\t1 - ����� ����\n";
    cout << "\t2 - ��������� ����\n";
    cout << "\t3 - ���������\n";
    SetConsoleTextAttribute(h, CL_YELLOW_BLACK);
    cout << "\t4 - �����\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
}


void ShowActions(string location)
{
    SetConsoleTextAttribute(h, CL_BLACK_YELLOW);
    cout << "\t �������: " << location << endl;
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);
    cout << "\n";

    SetConsoleTextAttribute(h, CL_BLACK_GREEN);
    cout << "1 - �������� ��� �����\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    SetConsoleTextAttribute(h, CL_BLACK_BLU);
    cout << "2 - ������������\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    SetConsoleTextAttribute(h, CL_BLACK_PURP);
    cout << "3 - �����������\n";
    SetConsoleTextAttribute(h, CL_BLACK_WHITE);

    cout << "0 - �����\n";
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
    while (s != "�����")
        {
            if (s == "�")
            {
                getline(in, s);
                printDialog(my_name, s, my_name, CL_BLACK_GREEN);
                Sleep(mySet.get_DialogSpeed()*1000);
            }
            if (s == "�����")
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
            if (s == "����")
            {
                system("cls");
                for (int i = 0; i < 10; i++)
                {
                    getline(in, s);
                    printDialog("", s, my_name, color);
                }
                system("pause");
            }
            if (s == "���")
            {
                getline(in, s2);
                getline(in, s);
                printDialog(s2, s, my_name, color);
                Sleep(mySet.get_DialogSpeed()*1000);
            }
            getline(in, s);
    }
    system("pause");
    if ((P.get_lvl() == 1) && (S.get_stranger_name() == "������ �����������"))
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