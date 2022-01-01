#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
using namespace std;

class Settings
{
private: //we should get settings from the file settings.txt
	float DialogSpeed;
	int ConsoleColor;
	int TextColor;
public:
	Settings()
	{
		DialogSpeed = 1.0;
		ConsoleColor = 0;
		TextColor = 0;
	}
	float get_DialogSpeed();
	void set_DialogSpeed(float ds);
	void ShowSettings();
	void GetDialogSpeedFromUser();
	void GetConsoleColorFromUser();
	void GetTextColorFromUser();
	void SaveSettingsInFile();
};

#endif