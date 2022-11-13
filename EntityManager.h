#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <csv.h>
#include <memory>
#include <math.h>
using std::unique_ptr;
using std::make_unique;
using std::move;
#include "Entity.h"
#include "EntitiesList.h"
#include "MapManager.h"
#include "constants.h"
#include "Player.h"


class EntityManager {
private:
	std::vector<unique_ptr<Entity>> entityList[9];
	MapManager* map;
	sf::Clock sword_cooldown;
public:
    sf::Vector2f getNearestEntity(sf::Vector2f);
	void initialize(MapManager*);
	void update(Player* p);
	void DrawWorld(sf::RenderWindow&);
	void spawnEntity(char type, sf::Vector2f pos);
	void saveToFile(const char* filename);
	void restart();
};
