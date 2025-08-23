//#include <vector>
//
//struct Vec3 {
//	int x;
//	int y;
//	int z;
//};
//
//struct Tile {
//	char* image;
//	struct Vec3 position;
//	int id;
//};
//
//struct TileTemplate{
//	char* name;
//	char* image;
//	int id;
//};
//
//
//class Grid {
//	const char* name;
//	const struct Vec3 size;
//	static std::vector<struct Tile> data;
//
//	void PlaceTile(struct Vec3 position, struct Tile tile);
//	void RemoveTile(struct Vec3 position);
//
//	void ChangeTileImage(struct Vec3 position);
//
//};
//
//
//static std::vector<struct TileTemplate> tiles;
//
//static int id = 0;
//
//struct TileTemplate CreateTile(char* name, char* img) {
//	struct TileTemplate temp;
//	temp.image = img;
//	temp.id = id;
//	id++;
//	temp.name = name;
//
//	return temp;
//}
//
//inline void PushTileToLibrary(struct TileTemplate tile) {
//	tiles.push_back(tile);
//}
//
//struct TileTemplate GetTileFromSet(char* name) {
//	for (struct TileTemplate tile : tiles)
//		if (name == tile.name)
//			return tile;
//}
//
//inline bool CheckInRange(int value, int range_min, int range_max) {
//	if (value >= range_min and value <= range_max)
//		return true;
//	return false;
//}
//
//void Grid::PlaceTile(struct Vec3 position, struct Tile tile) {
//	if (!CheckInRange(position.x, 0, size.x) or !CheckInRange(position.y, 0, size.y) or !CheckInRange(position.z, 0, size.z))
//		return;
//
//	
//}
//
