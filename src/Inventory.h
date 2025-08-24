#pragma once
#include <vector>
#include "BankAccount.hpp"
#include "Investment.h"
class Investment;

struct Inventory {
public:
	 std::vector<Investment*> investments;


	void buyInvestment(const Investment& investment, BankAccount& account);
	void sellInvestment(const Investment& investment, BankAccount& account);
	


};


