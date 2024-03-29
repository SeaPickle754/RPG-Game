#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Player.h"
#include "MapManager.h"
#include "EntityManager.h"
#include <string>
#include "constants.h"
#include "States.h"


class Application {
private:
    #ifdef DOEDIT
    char selected;
    #endif // DOEDIT
	sf::RenderWindow* window;
	State gameState;
	sf::Clock deltaClock;
	MapManager mapManager;
	EntityManager eManager;
	bool DrawDisplay;
	sf::Font DisplayFont;
	sf::Text DisplayText;
	void updatePlayerPage();
	void run();
	void renderTitlescreen();
	void doTitlescreenEvents();
	Player p;
public:
	void initialize();
	void render();
	void update();
	void doEvents();
	inline sf::RenderWindow* getWindow() { return window; };
};
