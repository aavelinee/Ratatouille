#ifndef _customer_file_
#define _customer_file_

#include "order.h"
#include <iostream>
#include <string>
#include <vector>

class customers{
public:
	void set_name (std::string cust_name);
	void set_phone_number (std::string cust_phone_num);
	void set_location(std::string cust_loc);
	//void set_order(std::string order_number, std::string order_personalization, std::string food_code);//-----
	std::string get_name();
	std::string get_phone_number();
	std::string get_location();
	//std::vector <orders> get_order();
private:
	std::string name;
	std::string phone_number;
	std::string location;
	//std::vector <orders> order;
};

#endif