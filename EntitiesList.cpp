#include "EntitiesList.h"

void Chest::initialize(sf::Vector2f pos){
    health = 10;
    tex = new sf::Texture;
    tex->loadFromFile("images/chest.png");
    sprite.setTexture(*tex);
    sprite.setPosition(pos);
}

void Chest::dropPayload(){
return;
}

void Chest::update(sf::Vector2f target){
return;
}
