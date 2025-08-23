#pragma once

class BankAccount
{
double balance;

	BankAccount(
		double new_balance
	);

public:	
	double get_balance();
	void deposit(double amount);
	void withdraw(double amount);
};
