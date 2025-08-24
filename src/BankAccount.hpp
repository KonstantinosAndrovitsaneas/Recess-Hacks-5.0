#pragma once

class BankAccount{
public:
	const char* name;

	BankAccount(
		const char* name,
		double new_balance
	);

	double get_balance();
	void deposit(double amount);
	void withdraw(double amount);
private:
	double balance;
};

void RenderBankAccounts();