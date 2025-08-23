#pragma once
class Bank_Account
{
	double balance;

	Bank_Account(
		double new_balance

	);

	double get_balance();
	void deposit(double amount);
	void withdraw(double amount);
	void display_balance();
};

