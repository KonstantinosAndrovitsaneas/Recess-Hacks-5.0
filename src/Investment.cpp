#include "Investment.h"
#include <iostream>
#include <random>
#include "Inventory.h"
Investment::Investment(

	double new_capital,
	double new_growth_rate,
	const std::string& new_name,
	Inventory& inventory
)
	: capital(new_capital), growth_rate(new_growth_rate), name(new_name){

	inventory.investments.push_back(this);
}

double Investment::update_value() {
	double max = capital * (growth_rate / 100);
	double min = -max;


	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min,max);

	capital += dist(gen);

	return capital;
}

double Investment::get_capital() {
	return capital;
}

std::string Investment::get_name() {
	return name;
}