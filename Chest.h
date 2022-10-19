#pragma once
#include <SFML/Graphics.hpp>

class Chest {
private:
	sf::Sprite sprite;
	sf::Texture tex;
public:
	void initialize(sf::Vector2f);
	void update(sf::Vector2f);
};