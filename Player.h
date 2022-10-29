#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "constants.h"
#include "debugger.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Sprite hearts;
	int health;
	sf::Texture heart_tex;
	sf::Sprite* sword;
	bool sword_sheathed;
	sf::Texture t_sword;
	sf::Texture tex;
	void dealWithMotion(sf::Time&, std::vector<sf::FloatRect>&);
	bool checkCollisions(float x, float y, std::vector<sf::FloatRect>&);
public:
    sf::Clock damageCooldown;
	bool initialize();
	inline int getHealth() {return health;}
	inline void dealDamage(int damage) {health -= damage;}
	inline bool isDead() {return health <= 0.f;}
	void draw(sf::RenderWindow& window);
	void update(sf::Time dt, std::vector<sf::FloatRect>& hitboxes, sf::Vector2f);
    float rotation;
	bool up, down, left, right;
	inline sf::Sprite* getSprite() { return &sprite; }
	inline void toggleSword(){sword_sheathed=!sword_sheathed;}
	inline sf::Sprite* getSword() {return sword;}
	inline bool isSwordSheathed(){return sword_sheathed;}
};
