#include <SFML/Graphics.hpp>
#include "constants.h"
class HealthBar{
private:
    sf::RectangleShape rect;
    float mHealth;
public:
    void initialize(sf::Vector2f& position, float);
    void setMaxWidth(float newMaxWidth);
    void updateHealth(float newHealth);
    inline void draw(sf::RenderWindow& window) {window.draw(rect);}
    // stack overflow question #5731863
    inline float map(float x, float in_min, float in_max, float out_min, float out_max){return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;}
};
