#include "Events.h"
#include <iostream>

Events::Events(
	std::string new_message,
	double new_amount
) : message(new_message), amount(new_amount)
{}

void Events::emergency_event(BankAccount& account) {

	std::cout << message << std::endl;

	if (ImGui::Button(amount)) {
		
		account.withdraw(amount);

	}


}


void Events::investment_event(BankAccount& account,Inventory& inventory, Investment& investment1, Investment& investment2) {
	std::cout << message << std::endl;
	if (ImGui::Button("Option 1")) {
		inventory.buy(investment1);
		account.withdraw(investment1.capital());
	}

	if (ImGui::Button("Option 2")) {
		inventory.buy(investment2);
		account.withdraw(investment1.capital());
	}