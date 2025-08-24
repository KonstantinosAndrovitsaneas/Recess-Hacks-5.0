#pragma once
struct Item {
	char* name;
	int value;
	//Texture2D image;
};

void RenderShop();

inline int GetItemLocation(char* name);

struct Item* GetItem(char* name);

inline bool CheckItem(char* name);

inline void AddItemToShop(struct Item item);

void RemoveItemFromShop(char* name);

void ChangeItemValue(char* name);