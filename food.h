#ifndef _foodfile_
#define _foodfile_

#include <iostream>
#include <string>

class food {
public:
	void set_code (std::string food_code);
	void set_name (std::string food_name);
	void set_type (std::string food_type);
	void set_price (int food_price);
	std::string get_code();
	std::string get_name();
	std::string get_type();
	int get_price();
private:
	std::string code;
	std::string name;
	std::string type;
	int price;
};

#endif