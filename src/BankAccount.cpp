#include "BankAccount.hpp"
#include <iostream>

BankAccount::BankAccount(

	double new_balance)

	: balance(new_balance) {}

double BankAccount::get_balance() {
	return balance;
}

void BankAccount::deposit(double amount) {
	balance += amount;
}

void BankAccount::withdraw(double amount) {
	if (amount > balance) {
		std::cout << "Insufficient funds" << std::endl;
	}
	else {
		balance -= amount;
	}
}