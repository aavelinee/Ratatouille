#ifndef _order_file_
#define _order_file_

#include <iostream>
#include <string>
#include <vector>

class orders {
public:
	void set_number(std::vector <std::string> order_number);
	void set_personalization(std::vector <std::string> perso);
	//void set_food(std::string code, std::string name, std::string type, int price);
	std::vector <std::string> get_number();
	std::vector <std::string> get_personalization();
	std::vector <std::string> get_food_codes();
private:
	std::vector <std::string> number;
	std::vector <std::string> personalization;
	std::vector <std::string> food_code;
};

#endif