#include "customer.h"
#include "order.h"
#include <iostream>
#include <string>
using namespace std;

void customers::set_name (string cust_name)
{
	name = cust_name;
}

void customers::set_phone_number (string cust_phone_num)
{
	phone_number = cust_phone_num;
}

void customers::set_location(string cust_loc)
{
	location = cust_loc;
}

//void set_order(string order_number, string order_personalization, string food_code);//-----

string customers::get_name()
{
	return name;
}

string customers::get_phone_number()
{
	return phone_number;
}

string customers::get_location()
{
	return location;
}

//vector <orders> get_order() {return order;}