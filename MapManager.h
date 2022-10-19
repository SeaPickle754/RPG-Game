#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

const int TILE_NUMBER = 4;
class MapManager {
private:
	std::vector<sf::FloatRect> hitboxes;
	std::string nonPassables;
	std::string map[9][10];
	int room = 0;
	bool addNewTile(int);
	sf::Sprite tiles[TILE_NUMBER];
	sf::Texture tileTextures[TILE_NUMBER];
public:
	MapManager();
	bool initMap();
	void updateHitboxes();
	int checkPlayerPage(int);
	void changeRoomTo(int room);
	void setTile(bool, int, int, char, int);
	void saveMapToFile(const char*);
	void drawWorld(sf::RenderWindow*);
	inline std::vector<sf::FloatRect>& getHitboxes() { return hitboxes; }
	inline int getRoom() { return room; }
};