#include <SFML/Graphics.hpp>
#include "MapManager.h"

class Editor{
private:
    char selected;
    MapManager* map;
    sf::RenderWindow* w;
public:
    void checkEditing(sf::Event& e);
    void initialize(MapManager*, sf::RenderWindow*);
};
