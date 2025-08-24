#include "BankAccount.hpp"
#include <iostream>
#include "imgui.h"
#include <vector>

std::vector<BankAccount> accounts;

BankAccount::BankAccount(

	std::string name,
	double new_balance
) 

: name(name), balance(new_balance) {}
	
std::string BankAccount::get_name() {
	return name;

}

double BankAccount::get_balance() {
	return balance;
}

void BankAccount::deposit(double amount) {
	balance += amount;
}

void BankAccount::withdraw(double amount) {
	if (amount <= balance) {
		balance -= amount;
	}

}


inline void OpenAccount(const char* name) {
	accounts.emplace_back(BankAccount(name, 0));
}

inline void CloseAccount(int id) {
	accounts.erase(accounts.begin() + id);
}

static int selected_account_id;

void RenderBankAccounts() {
	bool show_account_creation_dialog = 0;

	ImGui::Begin("Bank Account Details", NULL, ImGuiWindowFlags_NoCollapse);

	static int item_selected_idx = 0;
	//int item_highlighted_idx = -1; // Here we store our highlighted data as an index.
	if (ImGui::Button("Open Account")) {
		ImGui::OpenPopup("Create Account");
		
	}
	
	//BTW I USED CHATGPT TO FORMAT THIS AFTERWARDS CAUSE THERE WAS A TON OF RANDOM SPACES - WAHEED
	
	if (ImGui::BeginListBox("Accounts list"))
	{
		static bool second_button = false;
		static bool dis_balance = false;
		for (int i = 0; i < accounts.size(); i++) {
			bool is_selected = (item_selected_idx == i);

			if (ImGui::Selectable(accounts[i].name.c_str(), is_selected)) {
				item_selected_idx = i;
				second_button = true; 
				selected_account_id = i;
				dis_balance = !dis_balance;
			}
		}

		if (dis_balance && selected_account_id >= 0) {
			ImGui::Text("Account Balance: $%.2f", accounts[selected_account_id].get_balance());
		
		}

		ImGui::EndListBox();
		static float amount = 0;
		static bool show_warning = false;
		if (second_button && selected_account_id >= 0) {
			static int third_button = 0;
			if (ImGui::Button("Deposit")) {
				third_button = 1;
			}
			if (ImGui::Button("Withdraw")) {
				third_button = 2;
			}
			
			if (third_button == 1) {
				ImGui::InputFloat("Amount", &amount);
				if (ImGui::Button("Confirm Deposit")) {
					accounts[selected_account_id].deposit(amount);
					
				}
			}
			
			if (third_button == 2) {
				ImGui::InputFloat("Amount", &amount);
				if (ImGui::Button("Confirm Withdraw")) {
					accounts[selected_account_id].withdraw(amount);
					if (accounts[selected_account_id].get_balance() < amount) {
						show_warning = true;
					}
					else {
						show_warning = false;
					}
				}
			}
			if (show_warning == true) {
				ImGui::SetCursorPos(ImVec2(150, 200));
				ImGui::Text("Insufficient funds!");
			}
		}
	}


	//ImGui::SetNextWindowSize(ImVec2(400, 300)); // Set desired window size
	//ImGui::SetNextWindowPos(ImVec2((GetScreenWidth() - 400) * 0.5, (GetScreenHeight() - 300) * 0.5)); // Center position

	if (ImGui::BeginPopupModal("Create Account", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
		ImGui::Text("Select a name for the new account");
		static char account_name[128] = "";
		ImGui::InputText("Enter Account name", account_name, IM_ARRAYSIZE(account_name));
		ImGui::Separator();

		if (ImGui::Button("OK", ImVec2(120, 0)) && account_name[0] != '\0') {
			OpenAccount(account_name);
			ImGui::CloseCurrentPopup();
		}
		ImGui::SetItemDefaultFocus();
		ImGui::SameLine();
		if (ImGui::Button("Cancel", ImVec2(120, 0))) 
			ImGui::CloseCurrentPopup();
		ImGui::EndPopup();
	}

	ImGui::End();
}