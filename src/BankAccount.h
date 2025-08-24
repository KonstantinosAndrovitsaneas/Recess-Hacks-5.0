#pragma once
#include <iostream>
#include <vector>
class BankAccount
{

public:
	std::string name;
	double balance;
	static std::vector<BankAccount> accounts;

	BankAccount(std::string name, double new_balance);
	
	std::string get_name();
	double get_balance();
	void deposit(double amount);
	void withdraw(double amount);
	static void OpenAccount(const char* name);
	static void CloseAccount(int id);	
	static void RenderBankAccounts();

};
