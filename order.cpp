#include "order.h"
#include <iostream>
#include <string>
using namespace std;		

void orders::set_number(vector <string> order_number)
{
	number = order_number;
}

void orders::set_personalization(vector <string> perso)
{
	personalization = perso;
}

//void set_food(string code, string name, string type, int price);

vector <string> orders::get_number()
{
	return number;
}

vector <string> orders::get_personalization()
{
	return personalization;
}

vector <string> orders::get_food_codes()
{
	return food_code;
}