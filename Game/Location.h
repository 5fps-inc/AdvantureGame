#ifndef  LOCATION_H
#define LOCATION_H
#include <string>
using namespace std;

class Location
{
private:
	int arr[5];
	float arrch[5];
	string location_name;
	string Pers[5];
public:
	Location(int a0, int a1, int a2, int a3, int a4,
		float ch0, float ch1, float ch2, float ch3, float ch4,
		string n, string p0, string p1, string p2, string p3, string p4)
	{
		arr[0] = a0;
		arr[1] = a1;
		arr[2] = a2;
		arr[3] = a3;
		arr[4] = a4;

		arrch[0] = ch0;
		arrch[1] = ch1;
		arrch[2] = ch2;
		arrch[3] = ch3;
		arrch[4] = ch4;

		location_name = n;

		Pers[0] = p0;
		Pers[1] = p1;
		Pers[2] = p2;
		Pers[3] = p3;
		Pers[4] = p4;

	}
	string get_location_name();
	string get_Person_name_by_num(int num);
	int get_arr(int i);
	int get_arrch(int i);
};

#endif // ! LOCATION_H


