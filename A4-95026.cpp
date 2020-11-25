#include "food.h"
#include "restaurant.h"
#include "customer.h"
#include "order.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void initialize_restaurants (vector <restaurants> &rests, string name, string number, string location)
{
	restaurants r;
	r.set_name (name);
	r.set_number (number);
	r.set_location (location);
	rests.push_back (r);
}

string get_line(ifstream &restaurant_input, string &line)
{
	string all;
	for(int i=0; i<line.size(); i++)
    {
    	if(line.at(i) == ',')
    	{
    		all = line.substr(0,i);
    		line = line.substr(i+1);
    		break;
    	}
    }
    return all;
}

void read_from_food_file (ifstream &restaurant_input, vector<restaurants> &rests, int i)
{
	string line;
	string code, name, type, price;
	while (getline (restaurant_input, line) && line != "")
	{
    	code = get_line(restaurant_input,line);
    	code = rests.back().get_number() + code;
    	name = get_line(restaurant_input,line);
    	type = get_line(restaurant_input,line);
    	price = line;
		rests[i].set_food(code, name, type, price);
	}
}

void read_from_restaurant_file (vector <restaurants> &rests)
{
	ifstream restaurant_input;
	restaurant_input.open("restaurants.txt");
	int i = 0;
	char temp[300];

	while(!restaurant_input.eof())
	{
		restaurant_input.getline(temp,300,',');
		string name(temp);

		restaurant_input.getline(temp,300,',');
		string number(temp);

		restaurant_input.getline(temp,300,'\n');
		string location(temp);

		initialize_restaurants(rests, name, number, location);
		read_from_food_file (restaurant_input, rests, i);
		i++;
	}
}

void initialize_customers (vector <customers> &cust, string name, string phone_number, string location)
{
	customers c;
	c.set_name (name);
	c.set_phone_number (phone_number);
	c.set_location (location);
	cust.push_back (c);
}

void read_from_customers_file(vector <customers> &cust)
{
	ifstream customer_input;
	customer_input.open("customers.txt");
	char temp[300];

	while(!customer_input.eof())
	{
		customer_input.getline(temp,300,',');
		string name(temp);

		customer_input.getline(temp,300,',');
		string phone_number(temp);

		customer_input.getline(temp,300,'\n');
		string location(temp);

		initialize_customers(cust, name, phone_number, location);
	}
}

void get_input_line(string line, vector<string> &command)
{
    for(int i=0; i<line.size(); i++)
    {
    	if(line[i]== ' ')
    	{
    		command.push_back(line.substr(0,i));
    		line = line.substr(i+1);
    		break;
    	}
    	else if(i == line.size() - 1)
    	{
    		command.push_back(line);
    		return;
    	}
    }
    get_input_line(line, command);
}

void reveal_restaurants_near(customers cust, vector <restaurants> rests)
{
	for(int j=0; j<rests.size(); j++)
		if(cust.get_location() == rests[j].get_location())
			cout << rests[j].get_name() << " " << rests[j].get_number() << " "
				 << rests[j].get_location() << endl;
}

void reveal_lists_near(customers cust, vector <restaurants> rests, vector <food> foods)
{
	for(int j=0; j<rests.size(); j++)
		if(cust.get_location() == rests[j].get_location())
		{
			foods = rests[j].get_food();
			for(int k=0; k<foods.size(); k++)
			cout << foods[k].get_code() << " " << foods[k].get_name() << " " 
				 << foods[k].get_type() << " " << foods[k].get_price() << " "
				 << rests[j].get_name() << " " << rests[j].get_location() << endl;
		}
}

void reveal_lists_type(restaurants rests, vector <food> foods, vector <string> command)
{
	for(int i=0; i<foods.size(); i++)
		if(command[2] == foods[i].get_type())
			cout << foods[i].get_code() << " " << foods[i].get_name() << " " 
				 << foods[i].get_type() << " " << foods[i].get_price() << " "
				 << rests.get_name() << " " << rests.get_location() << endl;
}

void menu_command(vector <restaurants> &rests, vector <food> &foods, vector <string> &command)
{
	for(int i=0; i<rests.size(); i++)
		if(command[1] == rests[i].get_number())
		{
			foods = rests[i].get_food();
			for(int j=0; j<foods.size(); j++)
				cout << foods[j].get_code() << " " << foods[j].get_name() << " " 
					 << foods[j].get_type() << " " << foods[j].get_price() << endl ;
		}
	return;
}

void restaurants_command(vector <restaurants> rests, vector <customers> cust, vector <food> foods, vector <string> command)
{
	if(command.size()<2)
	{
		for(int i=0; i<rests.size(); i++)
			cout << rests[i].get_name() << " " << rests[i].get_number() << " "
				 << rests[i].get_location() << endl;
	}
	else if(command[1] == "near")
	{
		for(int i=0; i<cust.size(); i++)
		{

			if(command[2] == cust[i].get_phone_number())
				reveal_restaurants_near(cust[i], rests);
		}
	}
	else
	{
		cerr << "Please Insert Right Commands!";
		return;
	}
}

void list_command(vector <restaurants> rests, vector <food> foods, vector <string> command, vector <customers> cust)
{
	if(command[1] == "near")
	{
		for(int i=0; i<cust.size(); i++)
			if(command[2] == cust[i].get_phone_number())
				reveal_lists_near(cust[i], rests, foods);
	}
	else if(command[1] == "type")
	{
		for(int i=0; i<rests.size(); i++)
		{
			foods = rests[i].get_food();
			reveal_lists_type(rests[i], foods, command);
		}
	}
}

void order_command(vector <restaurants> rests, vector <orders> &order, customers cust, string line 	)
{
	orders new_order;
	vector <food> foods;
	vector <string> food_code;
	vector <string> number;
	vector <string> personalization;
	vector <string> divided_order;

	int i,k;
	while(cin!="$")
	{
		getline(cin, line);
		get_input_line(line, divided_order);

		for(i=0; i<rests.size(); i++)
		{	
			foods = rests[i].get_food();
			for(k=0; k<foods.size(); k++)
				if(divided_order[1] == foods[k].get_code())
					break;
		}
		number.push_back(divided_order[1]);
		for(int j=2; j<divided_order.size(); j++)
			personalization.push_back(divided_order[j]);
		new_order.set_number(number);
		new_order.set_personalization(personalization);

		//cust.set_order(new_order.get_number(), new_order.get_personalization(), new_order.get_food_codes());
		divided_order.clear();
	}
	//cout<<cust.get_name()<<" "<<cust.get_phone_number()<<" "<<total_price;
	return;
}

void find_who_ordered(vector <restaurants> rests, vector <orders> order, vector <customers> cust, vector<string> command)
{
	string line;
	for(int i=0; i<cust.size(); i++)
		if(command[1] == cust[i].get_phone_number())
			order_command(rests, order, cust[i], line);	
	return;
}

int main()
{
	vector <restaurants> rests;
	vector <food> foods;
	vector <customers> cust;
	vector <orders> order;
	vector <string> command;

	string line, restaurant_phone_number, customer_phone_number;
	read_from_restaurant_file(rests);
	read_from_customers_file(cust);

	while (getline (cin, line))
	{
		get_input_line(line, command);
		if(command[0] == "menu")
			menu_command(rests, foods, command);
		else if(command[0] == "restaurants")
			restaurants_command(rests, cust, foods, command);
		else if(command[0] == "list")
			list_command(rests, foods, command, cust);
		else if(command[0] == "order")
			find_who_ordered(rests, order, cust, command);
		command.clear();

	}
}