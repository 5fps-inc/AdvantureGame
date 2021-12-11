#include "Location.h"

string Location::get_location_name()
{
    return location_name;
}

string Location::get_Person_name_by_num(int num)
{
    return Pers[num];
}

int Location::get_arr(int i)
{
    return arr[i];
}

int Location::get_arrch(int i)
{
    return arrch[i];
}
