#pragma once
#include <vector>
#include "raylib/raylib.h"

struct Vec3 {
	int x;
	int y;
	int z;
};

struct Tile {
	Texture2D image;
	struct Vec3 position;
	int id;
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

private:
	std::vector<struct Tile> data;
};