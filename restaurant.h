#ifndef _restaurant_file_
#define _restaurant_file_

#include "food.h"
#include <iostream>
#include <string>
#include <vector>

class restaurants {
public:
	void set_name (std::string restaurant_name);
	void set_number (std::string restaurant_number);
	void set_location (std::string restaurant_location);
	void set_food (std::string food_code, std::string food_name, std::string food_type, std::string food_price);
	std::string get_name();
	std::string get_number();
 	std::string get_location();
  	std::vector <food> get_food();
private:
	std::string name;
	std::string number;
	std::string location;
	std::vector <food> foods;
};

#endif