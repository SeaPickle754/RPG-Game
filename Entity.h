#pragma once
#include <SFML/Graphics.hpp>
#include "healthBar.h"

// ================================================================
// an abstract class to represent a free standing object (chest, sign, shop, ect.)
// an enemy (zombie, slime, ect.)
// or anything else that does not have to be snapped to the grid
// ================================================================

class Entity {
protected:
	sf::Sprite sprite;
	sf::Texture* tex;
	float health;
	HealthBar* healthBar;
public:
    char type;
	virtual void dropPayload();
	virtual void initialize(sf::Vector2f);
	virtual bool update(sf::Sprite&);
	inline sf::Sprite* getSprite() {return &sprite;}
	inline void dealDamage(float damage) {health -= damage;}
    void draw(sf::RenderWindow&);
	inline float Gethealth(){return health;}
	inline bool checkDeath(float minHealth) {return (health < minHealth);}
	void freeMem();
};
