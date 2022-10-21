#include "EntitiesList.h"

void Chest::initialize(sf::Vector2f pos){
    health = 10.f;
    healthBar = new HealthBar;
    healthBar->initialize(pos, health);
    tex = new sf::Texture;
    tex->loadFromFile("images/chest.png");
    sprite.setTexture(*tex);
    sprite.setPosition(pos);
}

void Chest::dropPayload(){
delete healthBar;
delete tex;
return;
}

void Chest::update(sf::Vector2f target){
healthBar->updateHealth(health);
return;
}

Chest::~Chest(){
}
