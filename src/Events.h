#pragma once
#include "BankAccount.hpp"
#include "Inventory.h"
#include "Investment.h"
class Events
{
	std::string message;
	double amount;

	Events(
		std::string new_message,
		double new_amount

	);


	void emergency_event(BankAccount& account);
	void investment_event(BankAccount& account, Inventory& inventory, Investment& investment1, Investment& investment2);
};