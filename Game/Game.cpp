#include <iostream>
#include <windows.h>
#include "game_func.h"
#include "Weapon.h"
#include <ctime>
#include <stdlib.h>
#include "Player.h"
#include <fstream>
#include "Stranger.h"
#include "Settings.h"
#include "Location.h"

using namespace std;
int SetRundomColorOfRare(); // Прототип функции


// ______________________________________________MAIN _______________________
int main()
{
    
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));

    ShowMenu();
    int input;
    cin >> input;
    float DS;
    Settings MYSET;
    string gamename;
    bool isNewGame;

    while(input < 4)
    {
        if (input == 1)
        {
            system("cls");
            cout << " введите Имя новой игры. В двльнейшем при входе нужно будет его заного указть\n";
            cin >> gamename;
            gamename += ".txt";
            isNewGame = true;
            input = 4;
        }
        if (input == 2)
        {
            system("cls");
            cout << " введите сохраненной игры\n";
            cin >> gamename;
            gamename += ".txt";
            isNewGame = false;
            input = 4;
        }
        if (input == 3)
        {
            system("cls");
            cout << "Скорость диалогов: " << MYSET.get_DialogSpeed() << endl;
            cout << " от 0 до 10 секунд\n Введите \t";
            cin >> DS;
            MYSET.set_DialogSpeed(DS);
            cout << "Скорость диалогов: " << MYSET.get_DialogSpeed() << endl;
            system("cls");
            ShowMenu();
            cin >> input;
        }
    }
    /*
   ПЕременные которые получим из файла или 0 для новой игры
    */
    int curlvl;
    int curcoin;
    string nameofweapon;
    float weapondamage;
    float weaponcrit;
    float critchanse;
    string curtype;
    string currare;
    string curloc;

    if (!isNewGame) // Если есть ужесохранение
    {
        ifstream in;
        in.open(gamename);
        in >> curlvl;
        in.close();
        curcoin = 100;
        nameofweapon = "Что-то";
        weapondamage = 10.0;
        weaponcrit = 1.5;
        critchanse = 25.0;
        curtype = "тип";
        currare = "редкость";
        curloc = "хз";
    }
    else // Если игра новая
    {
        curlvl = 1;
        curcoin = 0;
        nameofweapon = "Кулаки";
        weapondamage = 1.0;
        weaponcrit = 1.5;
        critchanse = 25.0;
        curtype = "дробящее";
        currare = "обычное";
        curloc = "полянка";
    }
    Weapon Hands(nameofweapon, weapondamage, weaponcrit, critchanse, curtype, currare);
    Player P(curlvl, curcoin, Hands, curloc);
    if (isNewGame)
    {
        P.loc_cave_isopen = false;
        P.loc_desert_isopen = false;
        P.loc_forest_isopen = false;
        P.loc_mountain_isopen = false;
    }
    
    if(isNewGame)
    {
        cout << "Введите свое имя !!! на английском !!! а то будеьш без имени сидеть\n";
        string my_Name;
        cin >> my_Name;
        P.set_name(my_Name);
    }




    system("cls");
    Stranger Bandit("Бандит Инококентий", 0, 0, "ino.txt");
    GoStory(Bandit, P.get_name(), P, MYSET);
    system("cls");
    ShowActions(P.get_location());
    Location Field(0,1,2,0,0,50,25,25,0,0,"полянка", "","","","","");

    int c;
    cin >> c;
    while (c!=0)
    {
        switch (c)
        {
        case 1:
            if (P.get_lvl() > 1)
            {
                system("cls");
                cout << "  0   \t" << P.get_name() << endl;
                cout << " /|?   \n";
                cout << "  ^    \n";
                cout << " / |  \n";
                DescribeWeapon(P.get_weapon());
                cout << "Твой уровень " << P.get_lvl() << endl;
                cout << "Монет  " << P.get_coins() << endl;
                system("pause");
            }
            break;
        case 2:
            if (P.get_lvl() > 1)
            {
                system("cls");
                printMap(P.get_location(), P);
                system("pause");
            }
            break;
        case 3:
            system("cls");
            if (P.get_location() == "полянка")
            {
                lookUp(Field);
            }
            system("pause");
            break;
        default:
            break;
        }
        system("cls");
        ShowActions(P.get_location());
        cin >> c;
    }

    return 0;
}
//__________________________________________END MAIN_________________________
