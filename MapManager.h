#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Player.h"
#include "debugger.h"
const int TILE_NUMBER = 5;

struct HitboxRequest{
    int page;
    sf::FloatRect f;
    bool active;
};

class MapManager {
private:
	std::vector<sf::FloatRect> hitboxes;
	std::<HitboxRequest> hitboxRequests;
	std::string nonPassables;
	std::string damaging;
	std::string map[9][10];
	int room = 0;
	bool addNewTile(int);
	sf::Sprite tiles[TILE_NUMBER];
	sf::Texture tileTextures[TILE_NUMBER];
public:
	MapManager();
	bool initMap();
	void updateHitboxes();
	void restart() {room = 0;}
	void update(Player* p);
	void addHitbox(struct HitboxRequest);
	int checkPlayerPage(int);
	void changeRoomTo(int room);
	void setTile(bool, int, int, char, int);
	void saveMapToFile(const char*);
	void drawWorld(sf::RenderWindow*);
	inline std::vector<sf::FloatRect>& getHitboxes() { return hitboxes; }
	inline int getRoom() { return room; }
};
