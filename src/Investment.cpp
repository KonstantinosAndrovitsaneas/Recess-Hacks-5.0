#include "Investment.h"
#include <iostream>
#include <random>

Investment::Investment(

	double new_capital,
	double new_growth_rate,
	std::string new_name
)
	: capital(new_capital), growth_rate(new_growth_rate){}

double Investment::update_value() {
	double max = capital * (growth_rate / 100);
	double min = capital * (growth_rate / 100) * -1;


	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min,max);

	capital += dist(gen);

	return capital;
}

double Investment::get_capital() {
	return capital;
}