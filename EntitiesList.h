#include "Entity.h"
#include "constants.h"
#include <cmath>

class Chest : public Entity{
public:
     void initialize(sf::Vector2f pos);
     void dropPayload();
     bool update(sf::Sprite&);
     inline void draw(sf::RenderWindow& window) {healthBar->draw(window);};
};

class Slime : public Entity{
public:
     void initialize(sf::Vector2f pos);
     void dropPayload();
     bool update(sf::Sprite&);
     inline void draw(sf::RenderWindow& window) {window.draw(sprite); healthBar->draw(window);};
};
