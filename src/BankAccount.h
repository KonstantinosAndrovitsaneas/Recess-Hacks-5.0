#pragma once

class BankAccount
{
public:

	double balance;

	BankAccount(
		double new_balance
	);

	double get_balance();
	void deposit(double amount);
	void withdraw(double amount);
};
