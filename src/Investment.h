#pragma once
#include <iostream>
#include "Inventory.h"
struct Inventory;

class Investment {
public:
	double capital;
	double growth_rate;
	std::string& name;
	Inventory& inventory;
	Investment(

		double new_capital,
		double new_growth_rate,
		std::string& new_name,
		Inventory& inventory
	);

	double update_value();
	double get_capital();
	std::string get_name();
};
