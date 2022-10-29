#include "Entity.h"

void Entity::initialize(sf::Vector2f pos) {
    type = '-';
}

void Entity::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	healthBar->draw(window);
}

void Entity::dropPayload(){
return;
}

bool Entity::update(sf::Sprite& s){
//healthBar->updateHealth(health);
return false;
}
