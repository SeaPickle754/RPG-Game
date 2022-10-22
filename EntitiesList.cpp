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
// =====================================================================

void Amogus::initialize(sf::Vector2f pos){
health = 30.6;
healthBar = new HealthBar;
sf::Vector2f v (pos);
v.y -= (HEALTH_BAR_HEIGHT + 1);
healthBar->initialize(v, health);
tex = new sf::Texture;
tex->loadFromFile("images/entities/amogus.png");
sprite.setTexture(*tex);
sprite.setPosition(pos);
}

void Amogus::dropPayload(){
delete healthBar;
delete tex;
return;
}

void Amogus::update(sf::Vector2f target){
    healthBar->updateHealth(health);
    sf::Vector2f vec = sprite.getPosition();

    float angle = atan2(target.y-vec.y, target.x-vec.x );
    angle = (angle * (180/PI))+270;
    angle = static_cast<float>(angle);
    vec.y -= std::round(std::sin(angle));
    vec.x -= std::round(std::cos(angle));
    healthBar->moveTo(sf::Vector2f(vec.x, vec.y - (HEALTH_BAR_HEIGHT + 1)));
    sprite.setPosition(vec);
}

