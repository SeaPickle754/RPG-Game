#include "Application.h"
#include <iostream>
void Application::initialize() {
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Ziggy 2");
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);
    gameState = State::TITLESCREEN;
	if(!mapManager.initMap()) window->close();
	eManager.initialize(&mapManager);
	DrawDisplay = false;
	#ifdef DOEDIT
	selected = '.';
	#endif
	DisplayFont.loadFromFile("images/ariel.ttf");
	DisplayText.setFont(DisplayFont);
	DisplayText.setScale(sf::Vector2f(0.5, 0.5));
	DisplayText.setString("Room: 1");

	if(!p.initialize()){
        errorMessage("Could not find an image! Quitting");
        window->close();
	}
	//start Game Loop
	run();
}

void Application::render() {
	window->clear(sf::Color(0, 0, 0, 255));
	mapManager.drawWorld(window);
	p.draw(*window);
	eManager.DrawWorld(*window);
	if (DrawDisplay)
		window->draw(DisplayText);
	window->display();
}

void Application::run(){

while(window->isOpen()){
    if(gameState != State::TITLESCREEN){
    doEvents();
    if(gameState != State::PAUSED)
        update();
    render();
    }
    else if(gameState == State::TITLESCREEN){
        renderTitlescreen();
        doTitlescreenEvents();
    }

}
}

void Application::doTitlescreenEvents(){

sf::Event e;
while(window->pollEvent(e)){
    if(e.type == sf::Event::KeyPressed){
        gameState = State::PLAYING;
    }
    if(e.type == sf::Event::Closed)
        window->close();
}
}
void Application::renderTitlescreen(){
    sf::Texture titlescreen;
    if(!titlescreen.loadFromFile("images/startscreen.png")) errorMessage("Error loading titlescreen image(startscreen.png or similar)");
    sf::Sprite s(titlescreen);
    window->clear(sf::Color(255,255,255));
    window->draw(s);
    window->display();
}

void Application::updatePlayerPage(){
    int newRoom;
    sf::Vector2f vec = p.getSprite()->getPosition();
    if (vec.x < 0) {
		newRoom = mapManager.checkPlayerPage(1);
		if (mapManager.getRoom() != newRoom) {
			mapManager.changeRoomTo(newRoom);
			vec.x = 380;
		}
		else
			vec.x = 0;
	}
	else if (vec.x > 380) {
		newRoom = mapManager.checkPlayerPage(3);
		if (mapManager.getRoom() != newRoom) {
			mapManager.changeRoomTo(newRoom);
			vec.x = 0;
		}
		else
			vec.x = 380;
	}
	else if (vec.y < 0) {
		newRoom = mapManager.checkPlayerPage(0);
		if (mapManager.getRoom() != newRoom) {
			mapManager.changeRoomTo(newRoom);
			vec.y = 380;
		}
		else
			vec.y = 0;
	}
	else if (vec.y > 380) {
		newRoom = mapManager.checkPlayerPage(2);
		if (mapManager.getRoom() != newRoom) {
			mapManager.changeRoomTo(newRoom);
			vec.y = 0;
		}
		else
			vec.y = 380;
	}
	p.getSprite()->setPosition(vec);
}

void Application::update() {
	sf::Time dt = deltaClock.restart();
	short prevroom = mapManager.getRoom();
	sf::Vector2f v = eManager.getNearestEntity(p.getSprite()->getPosition());
	p.update(dt, mapManager.getHitboxes(),v);
	updatePlayerPage();
	if(gameState != State::NO_MOTION)
        eManager.update(&p);
    mapManager.update(&p);
    if(p.isDead()){
        gameState = State::TITLESCREEN;
        p.restart();
        eManager.restart();
        mapManager.restart();
    }
}

void Application::doEvents() {
	sf::Event e;
	while (window->pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window->close();
		}
		#ifdef DOEDIT
        if(e.type == sf::Event::MouseButtonPressed &&
        e.mouseButton.button == sf::Mouse::Left &&
        gameState == State::PLAYING){
            sf::Vector2i clickPos = sf::Mouse::getPosition(*window);
            sf::Vector2i worldPos = window->mapCoordsToPixel((sf::Vector2f)clickPos);
            mapManager.setTile(true, worldPos.x/40, worldPos.y/40, selected, -1);
            mapManager.updateHitboxes();
        }
        else if(e.type == sf::Event::MouseButtonPressed &&
        e.mouseButton.button == sf::Mouse::Right){
            sf::Vector2i clickPos = sf::Mouse::getPosition(*window);
            sf::Vector2i worldPos = window->mapCoordsToPixel((sf::Vector2f)clickPos);
            eManager.spawnEntity('O', (sf::Vector2f)worldPos);
        }
        #endif // DOEDIT
		if (e.type == sf::Event::KeyPressed)
		{


        if(gameState != State::PAUSED){
			if (e.key.code == sf::Keyboard::Up)
				p.up = true;
            else if(e.key.code == sf::Keyboard::W)
                p.dealDamage(1);
			else if (e.key.code == sf::Keyboard::Down)
				p.down = true;
			else if (e.key.code == sf::Keyboard::Left)
				p.left = true;
			else if (e.key.code == sf::Keyboard::Right)
				p.right = true;
			else if (e.key.code == sf::Keyboard::F)
				DrawDisplay = !DrawDisplay;
            else if (e.key.code == sf::Keyboard::Space)
                p.toggleSword();
		}
        if(e.key.code == sf::Keyboard::P)
                gameState = !gameState;
    #ifdef DOEDIT
else if (e.key.code == sf::Keyboard::S)
				mapManager.saveMapToFile("map.map");
			else if (e.key.code == sf::Keyboard::Num1)
				selected = '.';
			else if (e.key.code == sf::Keyboard::Num2)
				selected = '$';
			else if (e.key.code == sf::Keyboard::Num3)
				selected = '#';
			else if (e.key.code == sf::Keyboard::Num4)
				selected = '~';
            else if(e.key.code == sf::Keyboard::Num5)
                selected = '^';
            else if (e.key.code == sf::Keyboard::B)
                eManager.saveToFile("ram.csv");
#endif // DOEDIT

		}
		if (e.type == sf::Event::KeyReleased) {
			if (e.key.code == sf::Keyboard::Up)
				p.up = false;
			else if (e.key.code == sf::Keyboard::Down)
				p.down = false;
			else if (e.key.code == sf::Keyboard::Left)
				p.left = false;
			else if (e.key.code == sf::Keyboard::Right)
				p.right = false;
		}
	}
}
