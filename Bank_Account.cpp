#include "Bank_Account.h"
#include <iostream>

Bank_Account::Bank_Account(

	double new_balance)

	: balance(new_balance) {}



double Bank_Account::get_balance() {
	return balance;
}

void Bank_Account::deposit(double amount) {
	balance += amount;
}

void Bank_Account::withdraw(double amount) {
	if (amount > balance) {
		std::cout << "Insufficient funds" << std::endl;
	}
	else {
		balance -= amount;
	}
}

void Bank_Account::display_balance() {
	std::cout << "You have " << balance << " in your account." << std::endl;

}