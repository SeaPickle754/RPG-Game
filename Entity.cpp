#include "Entity.h"

void Entity::initialize(sf::Vector2f pos) {

}

void Entity::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	healthBar->draw(window);
}

void Entity::dropPayload(){
return;
}

void Entity::update(sf::Vector2f target){
return;
}
