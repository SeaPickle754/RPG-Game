#include "Editor.h"
#include <iostream>
void Editor::initialize(MapManager* m, sf::RenderWindow* window){
map = m;
selected = '.';
w = window;
}

void Editor::checkEditing(sf::Event& e){
    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
			// get the current mouse position in the window
			sf::Vector2i pixelPos = sf::Mouse::getPosition(*w);
			std::cout << "Line 13" << std::endl;
			// convert it to world coordinates
			sf::Vector2f worldPos = w->mapPixelToCoords(pixelPos);

			map->setTile(true, (int)worldPos.x / 40, (int)worldPos.y / 40, selected, -1);
			map->updateHitboxes();
		}
    if(e.type == sf::Event::KeyPressed)
        if (e.key.code == sf::Keyboard::S)
                    map->saveMapToFile("map.map");

                else if (e.key.code == sf::Keyboard::Num1)
                    selected = '.';
                else if (e.key.code == sf::Keyboard::Num2)
                    selected = '$';
                else if (e.key.code == sf::Keyboard::Num3)
                    selected = '#';
                else if (e.key.code == sf::Keyboard::Num4)
                    selected = '~';
}
