#include "restaurant.h"
#include "food.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int convert_string_to_int(string price)
{
	int Result;
	stringstream convert(price);

	if (!(convert >> Result))
    	Result = 0;
    return Result;
}

void restaurants::set_name (string restaurant_name)
{
	name = restaurant_name;
}

void restaurants::set_number (string restaurant_number)
{
	number = restaurant_number;
}

void restaurants::set_location (string restaurant_location)
{
	location = restaurant_location;
}

void restaurants::set_food (string food_code, string food_name, string food_type, string food_price)
{
	food f;
	f.set_code (food_code);
	f.set_name (food_name);
	f.set_type (food_type);
	int value = convert_string_to_int(food_price);
	f.set_price (value);
	foods.push_back (f);
}

string restaurants::get_name()
{
	return name;
}

string restaurants::get_number()
{
	return number;
}

string restaurants::get_location()
{
	return location;
}

vector <food> restaurants::get_food()
{
	return foods;
}