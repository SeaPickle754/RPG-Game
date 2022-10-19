#include "Chest.h"

void Chest::initialize(sf::Vector2f pos) {
	tex.loadFromFile("images/chest.png");
	sprite.setTexture(tex);
	sprite.setPosition(pos);
}
void Chest::update(sf::Vector2f target) {

}