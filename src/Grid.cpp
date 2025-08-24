
//#include "raylib/raylib.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "imgui.h"
#include "Grid.hpp"

static Vector2 offset = { 0, 0 };

static std::vector<struct TileTemplate> tiles;

static int id = 0;
// NEEDS WORK
struct TileTemplate CreateTile(char* name, char* img) {
	struct TileTemplate temp;
	temp.image = LoadTexture(img);
	temp.id = id;
	id++;
	temp.name = name;

	return temp;
}
// NEEDS WORK
inline void PushTileToLibrary(struct TileTemplate tile) {
	tiles.push_back(tile);
}

struct TileTemplate GetTileFromSet(char* name) {
	for (struct TileTemplate tile : tiles)
		if (name == tile.name)
			return tile;
}

inline bool CheckInRange(int value, int range_min, int range_max) {
	if (value >= range_min and value <= range_max)
		return true;
	return false;
}

void Grid::PlaceTile(struct Vec3 position, struct Tile tile) {
	if (!CheckInRange(position.x, 0, size.x) or !CheckInRange(position.y, 0, size.y) or !CheckInRange(position.z, 0, size.z))
		return;

	tile.position = position;

	data.push_back(tile);
}

void Grid::RemoveTile(struct Vec3 position) {
	for (int i = 0; i < data.size(); i++)
		if (data[i].position.x == position.x or data[i].position.y == position.y or data[i].position.z == position.z)
			data.erase(data.begin() + i);
}

// Return tile if found else return Null
struct Tile* Grid::GetTile(struct Vec3 position) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].position.x == position.x or data[i].position.y == position.y or data[i].position.z == position.z) {
			return &data[i];
		}
	}
	return NULL;
}


// TODO: Render code needs tweaking
void Grid::RenderTileSet() {
	Vector2 mousePos = GetMousePosition();

	bool over_tile = false;
	for (Tile& tile : data) {

		Rectangle tileRect = {
		(float)(tile.position.x * 80 + offset.x),
		(float)(tile.position.y * 80 + offset.y),
		80.0f,
		80.0f

		};

		DrawRectangle(tile.position.x * 80 + offset.x, tile.position.y * 80 + offset.y, 80, 80, MAROON);
		DrawTexture(tile.image, tile.position.x * 80, tile.position.y * 80, WHITE);

		if (CheckCollisionPointRec(mousePos, tileRect)) {
			over_tile = true;
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				clickedTile = &tile;
			}

		}
		
		if (!over_tile and IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) clickedTile = nullptr;
	}
}

// Added this bit to move camera, currently it also moves with the gui
//void CalculateGridPosition() {
//	if (ImGui::GetIO().MouseDown[0]) {
//		Vector2 mouse_offset = GetMouseDelta();
//		offset.x += mouse_offset.x;
//		offset.y += mouse_offset.y;
//	}
//}

Tile* Grid::GetClickedTile()
{
	return clickedTile;
}

//Grid::Grid(struct Vec3 size, char* name) {
//	size = size;
//	name = name;
//}

std::string LoadFileContent(char* file) {
	std::string total_file;

	std::string line;
	std::ifstream f("example.txt");
	while (getline(f, line))
	{
		total_file.append(line);
	}
	f.close();

	return total_file;
}

//void RenderTileLayer(char* tile_set, std::vector<int> tileset_data, Vector2 position, Vector2 size) {
//	Image tileset = LoadImage("resources/parrots.png");
//	/*DrawRectangle(position.x * 80 + offset.x, position.y * 80 + offset.y, 80, 80, MAROON);*/
//	//DrawTexture(tile.image, tile.position.x * 80, tile.position.y * 80, WHITE);
//	
//	for (int y = 0; y < size.y; y++) {
//		for (int x = 0; x < size.x; x++) {
//			tileset_data[y + x];
//			ImageCrop(&tileset, { 100, 10, 280, 380 });
//			Texture2D texture = LoadTextureFromImage(tileset);
//			RenderTile(texture, , Vector2 position)
//		}
//	}
//}
//
//inline Vector2 ConvertTileIDToPos(int number, Vector2 tile_count) {
//	return { number / tile_count.x, number % tile_count.x };
//}
//
//Rectangle CalculateTileCropDimentions(int number, Vector2 tileset_size, Vector2 tile_size) {
//	Vector2 pos = ConvertTileIDToPos(number, {tileset_size.x / tile_size.x, tileset_size.y / tile_size.y })
//	return {}
//}
//
//void RenderTile(Image tileset, int number, Vector2 Tileset_size, Vector2 position) {
//	/*DrawRectangle(position.x * 80 + offset.x, position.y * 80 + offset.y, 80, 80, MAROON);*/
//	//DrawTexture(tile.image, tile.position.x * 80, tile.position.y * 80, WHITE);
//	Vector4 tileset_size;
//	ImageCrop(&tileset, { 100, 10, 280, 380 });
//	Texture2D texture = LoadTextureFromImage(tileset);
//	DrawTexture(texture, position.x, position.y, WHITE);
//}
//
//inline void RenderTile(Texture2D texture, Vector2 position) {
//	DrawTexture(texture, position.x + offset.x, position.y + offset.y, WHITE);
//}
//
//std::vector<int> LoadTileMap(char* file) {
//	std::stringstream data = LoadFileContent(file).c_str();
//	std::string segment;
//	std::vector<int> seglist;
//
//	while (getline(data, segment, ','))
//	{
//		seglist.push_back(stoi(segment));
//	}
//
//	return seglist;
//}