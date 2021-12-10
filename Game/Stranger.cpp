#include "Stranger.h"

void Stranger::set_true()
{
	payed = true;
}

bool Stranger::is_payed()
{
	return payed;
}

int Stranger::get_num()
{
	return itemNeeded;
}

int Stranger::get_id()
{
	return id_item;
}

string Stranger::get_stranger_name()
{
	return name;
}

void Stranger::set_itemNeed(int a)
{
	itemNeeded = a;
}

string Stranger::get_txt()
{
	return txt;
}
