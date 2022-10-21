#include "EntityManager.h"
#include <iostream>
void EntityManager::initialize(MapManager* m) {
	textures[0].loadFromFile("images/chest.png");
	std::string str;
	map = m;
	 io::CSVReader<4> in("ram.csv");
    in.read_header(io::ignore_extra_column, "type", "page", "posX", "posY");
	 char type; int page; int posX; int posY;
	 while(in.read_row(type, page, posX, posY)){
        if(type == 'O'){
            Chest e;
            e.initialize(sf::Vector2f(posX, posY));

            entityList[page].push_back(e);
    }}
}

void EntityManager::update(sf::Sprite* weapon, bool isSheathed){
    if(!isSheathed){
    sf::FloatRect bBox = weapon->getGlobalBounds();
    for(auto i = entityList[map->getRoom()].begin();i != entityList[map->getRoom()].end(); i++){
        if(i->getSprite()->getGlobalBounds().intersects(bBox)&&
           sword_cooldown.getElapsedTime().asMilliseconds() >= SWORD_COOLDOWN){
            i->dealDamage(PLAYER_SWORD_DAMAGE);
            sword_cooldown.restart();
            if(i->checkDeath(0.f))
                entityList[map->getRoom()].erase(i);
            break;
        }
        i->update(sf::Vector2f(0.f, 0.f));
    }}
}

void EntityManager::DrawWorld(sf::RenderWindow& window) {
	for (auto i = entityList[map->getRoom()].begin(); i != entityList[map->getRoom()].end(); i++) {
		i->draw(window);
	}
}

void EntityManager::spawnEntity(char type, sf::Vector2f pos){
    if(type == 'O'){
        Chest e;
        e.initialize(pos);

    entityList[map->getRoom()].push_back(e);
}}


void EntityManager::saveToFile(const char* filename){
std::ofstream f;
f.open("ram.csv", std::ofstream::trunc);
f << "type,page,posX,posY" << std::endl;
f.close();
f.open("ram.csv", std::ofstream::app);
for(int i = 0; i < 9; i++){
    for(auto j = entityList[i].begin();j != entityList[i].end();j++){
        sf::Vector2f vec = j->getSprite()->getPosition();
        f << 'O'<<',' << i << ','<< vec.x <<','<< vec.y << std::endl;
    }
}
}
