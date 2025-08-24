#pragma once
#include <vector>
#include "raylib/raylib.h"
#include <iostream>
struct Vec3 {
	int x;
	int y;
	int z;
};

struct Tile {
	Texture2D image;
	struct Vec3 position;
	int id;
	std::string name;
};

struct TileTemplate {
	char* name;
	Texture2D image;
	int id;
};

class Grid {

public:
	char* name;
	struct Vec3 size = {10, 10, 10};

	//Grid(struct Vec3 size, char* name);

	void PlaceTile(struct Vec3 position, struct Tile tile);
	void RemoveTile(struct Vec3 position);

	struct Tile* GetTile(struct Vec3 position);

	void ChangeTileImage(struct Vec3 position);

	void RenderTileSet();

	Tile* GetClickedTile();
private:
	std::vector<struct Tile> data;
	Tile* clickedTile = nullptr;

};

void CalculateGridPosition();

inline Vector2 ConvertTileIDToPos(int number, Vector2 tile_count);

Rectangle CalculateTileCropDimentions(int number, Vector2 tileset_size, Vector2 tile_size);

void RenderTile(Image tileset, int number, Vector2 tileset_size, Vector2 tile_size, Vector2 position);

inline void RenderTile(Texture2D texture, Vector2 position);

void RenderTileLayer(char* tile_set, std::vector<int> tileset_data, Vector2 position, Vector2 size);

std::vector<int> LoadTileMap(char* file);