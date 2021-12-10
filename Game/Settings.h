#ifndef SETTINGS_H
#define SETTINGS_H
class Settings
{
private:
	float DialogSpeed;
public:
	float get_DialogSpeed();
	void set_DialogSpeed(float ds);
	Settings()
	{
		DialogSpeed = 1.0;
	}
};

#endif