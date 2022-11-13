#include "EntityManager.h"
#include <iostream>
void EntityManager::initialize(MapManager* m) {
	std::string str;
	map = m;
	 io::CSVReader<4> in("ram.csv");
    in.read_header(io::ignore_extra_column, "type", "page", "posX", "posY");
	 char type; int page; int posX; int posY;
	 while(in.read_row(type, page, posX, posY)){
        if(type == 'O'){
            unique_ptr<Entity> e;
            e = make_unique<Chest>();
            e->initialize(sf::Vector2f(posX, posY));
            struct HitboxRequest* hitboxR = new HitboxRequest;
            hitboxR->page = page;
            sf::Sprite s = *(e->getSprite());
            hitboxR->f = s.getGlobalBounds();
            map->addHitbox(*hitboxR);
            delete hitboxR;
            entityList[page].push_back(move(e));
    }
        else if(type == 'a'){
            unique_ptr<Entity> e;
            e= make_unique<Slime>();
            e->initialize(sf::Vector2f(posX, posY));
            entityList[page].push_back(move(e));
        }
    }
}

void EntityManager::restart(){
    for(int i = 0; i < 9; i++){
            for(auto it = entityList[i].begin();it != entityList[i].end(); it++){
                (*it)->freeMem();
        }
        entityList[i].clear();
    }
	std::string str;
    io::CSVReader<4> in("ram.csv");
    in.read_header(io::ignore_extra_column, "type", "page", "posX", "posY");
	 char type; int page; int posX; int posY;
	 while(in.read_row(type, page, posX, posY)){
        if(type == 'O'){
            unique_ptr<Entity> e;
            e = make_unique<Chest>();
            e->initialize(sf::Vector2f(posX, posY));

            entityList[page].push_back(move(e));
    }
        else if(type == 'a'){
            unique_ptr<Entity> e;
            e = make_unique<Slime> ();
            e->initialize(sf::Vector2f(posX, posY));
            entityList[page].push_back(move(e));
        }
    }
}

sf::Vector2f EntityManager::getNearestEntity(sf::Vector2f d1){
sf::Vector2f bestPos(d1);
float bestDistance = 560;
for(auto i = entityList[map->getRoom()].begin(); i != entityList[map->getRoom()].end(); i++){
    sf::Vector2f d2 = (*i)->getSprite()->getPosition();
    float distance = sqrt(pow((d2.x - d1.x), 2)+pow((d2.y-d1.y),2));
    if(distance < bestDistance){
        bestDistance = distance;
        bestPos = d2;
    }
}
return bestPos;
}

void EntityManager::update(Player* p){
        sf::FloatRect bBox = p->getSword()->getGlobalBounds();
    bool isSheathed = p->isSwordSheathed();
    for(auto i = entityList[map->getRoom()].begin();i != entityList[map->getRoom()].end(); i++){
        if((*i)->getSprite()->getGlobalBounds().intersects(bBox)&&
           sword_cooldown.getElapsedTime().asMilliseconds() >= SWORD_COOLDOWN && !isSheathed){
            (*i)->dealDamage(PLAYER_SWORD_DAMAGE);

            sword_cooldown.restart();
            if((*i)->checkDeath(0.f)){
                (*i)->dropPayload();
                (*i)->freeMem();
                entityList[map->getRoom()].erase(i);
            }
            break;
        }

            if((*i)->update(*(p->getSprite()))){
                p->dealDamage(1);
            }
    }
}

void EntityManager::DrawWorld(sf::RenderWindow& window) {
	for (auto i = entityList[map->getRoom()].begin(); i != entityList[map->getRoom()].end(); i++) {
		(*i)->draw(window);
	}
}

void EntityManager::spawnEntity(char type, sf::Vector2f pos){
    if(type == 'O'){
        unique_ptr<Entity> e;
        e= make_unique<Chest>();
        e->initialize(pos);

    entityList[map->getRoom()].push_back(move(e));
    }

    if(type == 'a'){
        unique_ptr<Entity> e;
        e = make_unique<Slime>();
        e->initialize(pos);

    entityList[map->getRoom()].push_back(move(e));

    }
}

void EntityManager::saveToFile(const char* filename){
std::ofstream f;
f.open("ram.csv", std::ofstream::trunc);
f << "type,page,posX,posY" << std::endl;
f.close();
f.open("ram.csv", std::ofstream::app);
for(int i = 0; i < 9; i++){
    for(auto j = entityList[i].begin();j != entityList[i].end();j++){
        sf::Vector2f vec = (*j)->getSprite()->getPosition();
        f << (*j)->type<<',' << i << ','<< static_cast<int>(vec.x) <<','<< static_cast<int>(vec.y)<< std::endl;
    }
}
}
