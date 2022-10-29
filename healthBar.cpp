#include "healthBar.h"

void HealthBar::initialize(sf::Vector2f& pos, float maxHealth){
    mHealth = maxHealth;
    currentHealth = maxHealth;
    quad[0].position = pos;
    quad[1].position = sf::Vector2f(pos.x, pos.y+HEALTH_BAR_HEIGHT);
    quad[2].position = sf::Vector2f(pos.x + map(maxHealth,0,maxHealth,0,HEALTH_BAR_MAX_LENGTH), pos.y+HEALTH_BAR_HEIGHT);
    quad[3].position = sf::Vector2f(pos.x + map(maxHealth,0,maxHealth,0,HEALTH_BAR_MAX_LENGTH), pos.y);

    for(int i = 0; i < 4; i++)
        quad[i].color = HEALTH_BAR_COLOR;

    p = pos;
}


void HealthBar::setMaxWidth(float maxWidth){
mHealth = maxWidth;
}

void HealthBar::updateHealth(float newHealth){
    currentHealth = newHealth;
    quad[0].position = p;
    quad[1].position = sf::Vector2f(p.x, p.y+HEALTH_BAR_HEIGHT);
    quad[2].position = sf::Vector2f(p.x + map(currentHealth,0,mHealth,0,HEALTH_BAR_MAX_LENGTH), p.y+HEALTH_BAR_HEIGHT);
    quad[3].position = sf::Vector2f(p.x + map(currentHealth,0,mHealth,0,HEALTH_BAR_MAX_LENGTH), p.y);

}

void HealthBar::moveTo(sf::Vector2f pos){
    quad[0].position = pos;
    quad[1].position = sf::Vector2f(pos.x, pos.y+HEALTH_BAR_HEIGHT);
    quad[2].position = sf::Vector2f(pos.x + map(currentHealth,0,mHealth,0,HEALTH_BAR_MAX_LENGTH), pos.y+HEALTH_BAR_HEIGHT);
    quad[3].position = sf::Vector2f(pos.x + map(currentHealth,0,mHealth,0,HEALTH_BAR_MAX_LENGTH), pos.y);

}
