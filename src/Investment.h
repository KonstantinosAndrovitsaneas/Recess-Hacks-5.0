#pragma once

class Investment {

	double capital;
	double growth_rate;
	std::string name;

	Investment(

		double new_capital,
	double new_growth_rate,
	std::string new_name	
	);


	double update_value();
	double get_capital();

};