#include "BankAccount.hpp"
#include <iostream>
#include "imgui.h"
#include <vector>

std::vector<BankAccount> accounts;

BankAccount::BankAccount(
	const char* name,
	double new_balance) {
	balance = new_balance;
	name = name;
}

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

inline void OpenAccount(const char* name) {
	accounts.push_back(BankAccount(name, 0));
}

inline void CloseAccount(int id) {
	accounts.erase(accounts.begin() + id);
}

static int selected_account_id;

void RenderBankAccounts() {
	bool show_account_creation_dialog = 0;

	ImGui::Begin("Bank Account Details", NULL, ImGuiWindowFlags_NoCollapse);

	static int item_selected_idx = 0;
	static bool item_highlight = false;
	int item_highlighted_idx = -1; // Here we store our highlighted data as an index.

	if (ImGui::BeginListBox("Accounts list"))
	{
		for (int i = 0; i < accounts.size(); i++) {
			const bool is_selected = (item_selected_idx == i);
			if (ImGui::Selectable("accounts[i].name", is_selected))
				item_selected_idx = i;

			if (item_highlight && ImGui::IsItemHovered())
				item_highlighted_idx = i;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndListBox();
	}
	
	if (ImGui::Button("Open Account")) {
		ImGui::OpenPopup("Create Account");
		//show_account_creation_dialog = 1;
	}

	//ImGui::SetNextWindowSize(ImVec2(400, 300)); // Set desired window size
	//ImGui::SetNextWindowPos(ImVec2((GetScreenWidth() - 400) * 0.5, (GetScreenHeight() - 300) * 0.5)); // Center position

	if (ImGui::BeginPopupModal("Create Account", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
		ImGui::Text("Select a name for the new account");
		static char account_name[128] = "";
		ImGui::InputText("Enter Account name", account_name, IM_ARRAYSIZE(account_name));
		ImGui::Separator();

		if (ImGui::Button("OK", ImVec2(120, 0)) && account_name != "") {
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