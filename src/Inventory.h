#pragma once
#include <vector>
#include "BankAccount.hpp"
#include "Investment.h"
struct Inventory {
	std::vector<Investment> investments;

	void buyInvestment(const Investment& investment, BankAccount& account);
	void sellInvestment(const Investment& investment, BankAccount& account);
};