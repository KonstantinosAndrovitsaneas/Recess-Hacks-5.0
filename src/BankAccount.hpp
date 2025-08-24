#pragma once
#include <string>
class BankAccount{
public:
		std::string name;

	BankAccount(
		std::string name,
		double new_balance
	);
	std::string get_name();
	double get_balance();
	void deposit(double amount);
	void withdraw(double amount);
private:
	double balance;
};

void RenderBankAccounts();