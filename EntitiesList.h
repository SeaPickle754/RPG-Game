#include "Entity.h"

class Chest : public Entity{
public:
     void initialize(sf::Vector2f pos);
     void dropPayload();
     void update(sf::Vector2f target);
     inline void draw(sf::RenderWindow& window) {window.draw(sprite);}
};
