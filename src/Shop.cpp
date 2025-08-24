#include "raylib/raylib.h"
#include "imgui.h"
#include "Shop.hpp"
#include <vector>
#include <string>

static std::vector<struct Item> shop_items;

void RenderShop() {
	ImGui::SetNextWindowSize(ImVec2(400, 300)); // Set desired window size
	ImGui::SetNextWindowPos(ImVec2((GetScreenWidth()  - 400) * 0.5, (GetScreenHeight() - 300) * 0.5)); // Center position
	ImGui::Begin("Shop");
	ImGui::Text("This window is centered!");
	ImGui::BeginChild("ScrollableRegion", ImVec2(0, 300), true);

	for (int i = 0; i < 30; i++) {
		/*if (i % 5 == 0)
			ImGui::NewLine();*/
		ImGui::Button(("Item " + std::to_string(i)).c_str(), ImVec2(100, 100));

	}
	ImGui::EndChild();

	if(ImGui::Button("Purchase")) {}
	ImGui::End();
}

inline int GetItemLocation(char* name) {
	for (int i = 0; i < shop_items.size(); i++) {
		if (shop_items[i].name == name) {
			return i;
		}
	}
	return NULL;
}

struct Item* GetItem(char* name) {
	int location = GetItemLocation(name);
	if(location == NULL)
		return NULL;
	return &shop_items[location];
}

inline bool CheckItem(char* name) {
	if (GetItem(name) == NULL)
		return 0;
	return 1;
}

inline void AddItemToShop(struct Item item) {
	if(!CheckItem(item.name))
		shop_items.push_back(item);
}

void RemoveItemFromShop(char* name) {
	int location = GetItemLocation(name);
	if (location == NULL)
		return;
	shop_items.erase(shop_items.begin() + location);
}

void ChangeItemValue(char* name) {

}

void PurchaseItem(int location);