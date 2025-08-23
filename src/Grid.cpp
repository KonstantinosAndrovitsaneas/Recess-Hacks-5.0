
//#include "raylib/raylib.h"

#include "Grid.hpp"

static std::vector<struct TileTemplate> tiles;

static int id = 0;
// NEEDS WORK
struct TileTemplate CreateTile(char* name, char* img) {
	struct TileTemplate temp;
	temp.image = LoadTexture();
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
//void Grid::RenderTileSet() {
//	for (struct Tile tile : data) {
//		DrawRectangle(tile.position.x * 80, tile.position.y * 80, 80, 80, MAROON);
//		DrawTexture(tile.image, tile.position.x, tile.position.y, WHITE);
//	}
//}

//Grid::Grid(struct Vec3 size, char* name) {
//	size = size;
//	name = name;
//}