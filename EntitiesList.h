#include "Entity.h"

class Chest : public Entity{
public:
     void initialize(sf::Vector2f pos);
     void dropPayload();
     void update(sf::Vector2f target);
     void draw(sf::RenderWindow& window) {healthBar->draw(window);};
     ~Chest();
};
