#include "food.h"
#include <iostream>
#include <string>
using namespace std;		

void food::set_code (string food_code)
{
	code = food_code;
}

void food::set_name (string food_name)
{
	name = food_name;
}

void food::set_type (string food_type)
{
	type = food_type;
}

void food::set_price (int food_price)
{
	price = food_price;
}

string food::get_code()
{
	return code;
}

string food::get_name()
{
	return name;
}

string food::get_type(){
	return type;
}

int food::get_price(){
	return price;
}