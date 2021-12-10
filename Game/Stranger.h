#ifndef STRANGER_H
#define STRANGER_H
#include <string>
using namespace std;

class Stranger
{
private:
	bool payed = false;
	int itemNeeded = 0;
	int id_item = 0;
	string name = "";
	string txt = "";
	bool Is_visible;
public:
	void set_true();
	bool is_payed();
	int get_num();
	int get_id();
	string get_stranger_name();
	Stranger(string n, int count, int id, string t)
	{
		name = n;
		itemNeeded = count;
		id_item = id;
		txt = t;
	}

	void set_itemNeed(int a);
	string get_txt();
};

#endif 
