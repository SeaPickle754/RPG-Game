#pragma once
#include <SFML/Graphics.hpp>
#include "healthBar.h"

// ================================================================
// an abstract class to represent a free standing object (chest, sign, shop, ect.)
// an enemy (zombie, slime, ect.)
// or anything else that does not have to be snapped the the grid
// ================================================================

class Entity {
protected:
	sf::Sprite sprite;
	sf::Texture* tex;
	float health;
	HealthBar* healthBar;
public:
	void dropPayload();
	void initialize(sf::Vector2f);
	void update(sf::Vector2f);
	inline sf::Sprite* getSprite() {return &sprite;}
	inline void dealDamage(float damage) {health -= damage;}
    void draw(sf::RenderWindow&);
	inline float Gethealth(){return health;};
	inline bool checkDeath(float minHealth) {return (health < minHealth);}
};
