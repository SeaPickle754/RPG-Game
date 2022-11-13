#include "EntitiesList.h"

void Chest::initialize(sf::Vector2f pos){
    health = 10.f;
    type = 'O';
    healthBar = new HealthBar;
    healthBar->initialize(pos, health);
    tex = new sf::Texture;
    tex->loadFromFile("images/chest.png");
    sprite.setTexture(*tex);
    sprite.setPosition(pos);
}

void Chest::dropPayload(){
return;
}

void Chest::freeMem(){
delete tex;
delete healthBar;
}

bool Chest::update(sf::Sprite& s){
healthBar->updateHealth(health);
return false;
}
// =====================================================================

void Slime::initialize(sf::Vector2f pos){
health = 30.6;
type = 'a';
healthBar = new HealthBar;
sf::Vector2f v (pos);
v.y -= (HEALTH_BAR_HEIGHT + 1);
healthBar->initialize(v, health);
tex = new sf::Texture;
tex->loadFromFile("images/entities/amogus.png");
sprite.setTexture(*tex);
sprite.setPosition(pos);
return;
}

void Slime::dropPayload(){

return;
}

void Slime::freeMem(){
delete tex;
delete healthBar;
}

bool Slime::update(sf::Sprite& s){
    healthBar->updateHealth(health);
    sf::Vector2f vec = sprite.getPosition();
    sf::Vector2f target = s.getPosition();
    float angle = atan2(target.y-vec.y, target.x-vec.x );
    angle = (angle * (180/PI))+270;
    vec.y -= std::sin(angle);
    vec.x -= std::cos(angle);
    healthBar->moveTo(sf::Vector2f(vec.x, vec.y - (HEALTH_BAR_HEIGHT + 1)));
    sprite.setPosition(vec);
    if(sprite.getGlobalBounds().intersects(s.getGlobalBounds()))
        return true;
    return false;
}

