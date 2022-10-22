#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <csv.h>
#include "Entity.h"
#include "EntitiesList.h"
#include "MapManager.h"
#include "constants.h"

const int TEXTURE_NUMBER = 1;

class EntityManager {
private:
	std::vector<Entity*> entityList[9];
	sf::Texture textures[TEXTURE_NUMBER];
	MapManager* map;
	sf::Clock sword_cooldown;
public:
	void initialize(MapManager*);
	void update(sf::Sprite* weapon, bool);
	void DrawWorld(sf::RenderWindow&);
	void spawnEntity(char type, sf::Vector2f pos);
	void saveToFile(const char* filename);
};
