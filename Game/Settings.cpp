#include "Settings.h"
#include "game_func.h"
#include "GameUI.h"
#include <Windows.h>

float Settings::get_DialogSpeed()
{
    return DialogSpeed;
}

void Settings::set_DialogSpeed(float ds)
{
    DialogSpeed = ds;
}

void Settings::ShowSettings()
{
    int UserInput = 0;
    system("cls");       
    cout << "Settings:" << endl;
    cout << "1 - DialogSpeed" << endl;
    cout << "2 - ConsoleColor" << endl;
    cout << "3 - TextColor" << endl;
    cout << "4 - Exit" << endl;
    cin >> UserInput;
    if (UserInput == 1) GetDialogSpeedFromUser();
    else if (UserInput == 2) GetConsoleColorFromUser();
    else if (UserInput == 3) GetTextColorFromUser();
    else if (UserInput == 4) {
        SaveSettingsInFile();
        ShowMenu();
    }
}

void Settings::GetDialogSpeedFromUser()
{
    float diagSpeed;
    cout << "—корость диалогов: " << DialogSpeed << endl;
    cout << " от 0 до 10 секунд (0 - пропуск диалогов)\n ¬ведите \t";
    cin >> diagSpeed;
    if (diagSpeed <= 0) diagSpeed = 0;
    if (diagSpeed >= 10) diagSpeed = 10;
    set_DialogSpeed(diagSpeed);
    ShowSettings();
}

void Settings::GetConsoleColorFromUser()
{
    int color;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Enter console color (digits): ";
    cin >> color;
    ConsoleColor = color;
    SetConsoleTextAttribute(h, color * 10 + TextColor); //first digit - background, second digit - text
    ShowSettings();
}

void Settings::GetTextColorFromUser()
{
    int color;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Enter text color (digits): ";
    cin >> color;
    TextColor = color;
    SetConsoleTextAttribute(h, ConsoleColor * 10 + color); //first digit - background, second digit - text
    ShowSettings();
}

void Settings::SaveSettingsInFile()
{
}
