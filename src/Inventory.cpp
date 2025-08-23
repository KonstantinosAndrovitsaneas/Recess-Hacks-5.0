#include "Inventory.hpp"
#include <iostream>

void Inventory::buyInvestment(const Investment& investment, BankAccount& account) {
	if (account.get_balance() >= investment.capital) {
	
		inventory.push_back(investment);
		account.withdraw(investment.capital);
		std::cout << "Bought investment: " << investment.name << "for $" << investment.capital << std::endl;
	}
	else {
		std::cout << "Not enough funds" << std::endl;
	}
}

void Inventory::sellInvestment(const Investment& investment, BankAccount& account) {

	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i] == investment.name()) {
			account.deposit(investment.capital);
			inventory.erase(inventory.begin() + 1);
			std::cout << "Sold investment: " << investment.name << "for $" << investment.capital << std::endl;
		}
	}

}
