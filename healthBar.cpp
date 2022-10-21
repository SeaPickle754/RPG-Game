#include "healthBar.h"

void HealthBar::initialize(sf::Vector2f& position, float maxHealth){
    mHealth = maxHealth;
    rect.setPosition(position);
    rect.setSize(sf::Vector2f(1.f, HEALTH_BAR_HEIGHT));
    rect.setFillColor(HEALTH_BAR_COLOR);
    rect.setOutlineColor(HEALTH_BAR_OUTLINE_COLOR);
    rect.setOutlineThickness(HEALTH_BAR_OUTLINE_THICKNESS);
    rect.setScale(map(maxHealth, 0, maxHealth, 0, HEALTH_BAR_MAX_LENGTH), 1);

}


void HealthBar::setMaxWidth(float maxWidth){
mHealth = maxWidth;
}

void HealthBar::updateHealth(float newHealth){
    rect.setScale(map(newHealth, 0, mHealth, 0, HEALTH_BAR_MAX_LENGTH), 1);
}
