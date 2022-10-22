#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "constants.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Sprite* sword;
	bool sword_sheathed;
	sf::Texture t_sword;
	sf::Texture tex;
	bool checkCollisions(float x, float y, std::vector<sf::FloatRect>&);
public:
	bool initialize();
	void draw(sf::RenderWindow& window);
	void update(sf::Time dt, std::vector<sf::FloatRect>& hitboxes, sf::Vector2f);
    float rotation;
	bool up, down, left, right;
	inline sf::Sprite* getSprite() { return &sprite; }
	inline void toggleSword(){sword_sheathed=!sword_sheathed;}
	inline sf::Sprite* getSword(){return sword;}
	inline bool isSwordSheathed(){return sword_sheathed;}
};
