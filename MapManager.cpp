#include "MapManager.h"

MapManager::MapManager() {
	room = 0;
	nonPassables = "$~";
	damaging = "^";
}

void MapManager::addHitbox(struct HitboxRequest r){
    r.active = false;
    hitboxRequests.push_back(r);
}

void MapManager::update(Player* p){
    for(int i = 0; i < 10; i++){
            for(int j = 0; j<10;j++){
				if (damaging.find(map[room][i][j]) != std::string::npos){
					sf::FloatRect f = p->getSprite()->getGlobalBounds();
				if(f.intersects(sf::FloatRect(j * 40, i * 40, 40, 40))){
                            p->dealDamage(3);
                        }
                    }
                }
            }
    for(auto it = hitboxRequests.begin(); it != hitboxRequests.end(); it++){
        if(room == it->page && !it->active){
            hitboxes.push_back(it->f);
            it->active = true;
            break;
        }
    }
}

void MapManager::drawWorld(sf::RenderWindow* window) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[room][i][j] == '.') {
				tiles[0].setPosition(j*40.f, i*40.f);
				window->draw(tiles[0]);
			}
			else if (map[room][i][j] == '$') {
				tiles[1].setPosition(j * 40.f, i * 40.f);
				window->draw(tiles[1]);
			}

			else if (map[room][i][j] == '#') {
				tiles[2].setPosition(j * 40.f, i * 40.f);
				window->draw(tiles[2]);
			}

			else if (map[room][i][j] == '~') {
				tiles[3].setPosition(j * 40.f, i * 40.f);
				window->draw(tiles[3]);
			}
			else if(map[room][i][j] == '^'){
                tiles[4].setPosition(j*40.f, i*40.f);
                window->draw(tiles[4]);
			}
		}
	}
}

bool MapManager::initMap() {

	for (int i = 0; i < TILE_NUMBER; i++) {
		addNewTile(i);
	}

	std::ifstream file;
	hitboxes.clear();
	file.open("map.map");
	for (int i = 0; i < 9; i++) {
		for (int y = 0; y < 10; y++) {
			file >> map[i][y];
			for (int x = 0; x < 10; x++) {
				if (nonPassables.find(map[room][y][x]) != std::string::npos)
					hitboxes.push_back(sf::FloatRect(x * 40, y * 40, 40, 40));
			}
		}
	}
	return true;
}

void MapManager::updateHitboxes() {
    hitboxes.clear();
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (nonPassables.find(map[room][y][x]) != std::string::npos)
				hitboxes.push_back(sf::FloatRect(x * 40, y * 40, 40, 40));
		}
	}
}

void MapManager::changeRoomTo(int r) {
	hitboxes.clear();
	for(auto iter = hitboxRequests.begin(); iter != hitboxRequests.end(); iter++){
        iter->active = false;
	}
	room = r;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (nonPassables.find(map[room][i][j]) != std::string::npos)
				hitboxes.push_back(sf::FloatRect(j * 40, i * 40, 40, 40));
		}
	}
}

bool MapManager::addNewTile(int index){
		sf::Texture t;
		if (!t.loadFromFile("images/tiles.png", sf::IntRect(index * 40, 0, 40, 40)))
			return false;
		tileTextures[index] = t;
		tiles[index] = sf::Sprite(tileTextures[index]);
}

void MapManager::setTile(bool useCurrentRoom = true, int X = 10, int Y = 10, char newVal = '.', int targetRoom=-1){
	map[room][Y][X] = newVal;
}

void MapManager::saveMapToFile(const char* filename) {
	std::ofstream outFile;
	outFile.open(filename, std::ofstream::trunc);
	outFile.close();
	outFile.open(filename);
	for (int i = 0; i < 9; i++) {
		for (int y = 0; y < 10; y++) {
			outFile << map[i][y];
			outFile << '\n';
		}
	}

}

int MapManager::checkPlayerPage(int side) {
	switch (room) {
	case 0:
		switch (side) {
		case 0:
			return room;
		case 1:
			return room;
		case 2:
			return 3;
		case 3:
			return 1;
		}
	case 1:
		switch (side) {
		case 0:
			return room;
		case 1:
			return 0;
		case 2:
			return 4;
		case 3:
			return 2;

		}
	case 2:
		switch (side) {
		case 0:
			return room;
		case 1:
			return 1;
		case 2:
			return 5;
		case 3:
			return room;

		}
	case 3:
		switch (side) {
		case 0:
			return 0;
		case 1:
			return room;
		case 2:
			return 6;
		case 3:
			return 4;
		}
	case 4:
		switch (side) {
		case 0:
			return 1;
		case 1:
			return 3;
		case 2:
			return 7;
		case 3:
			return 5;
		}
	case 5:
		switch (side) {
		case 0:
			return 2;
		case 1:
			return 4;
		case 2:
			return 8;
		case 3:
			return room;

		}
	case 6:
		switch (side) {
		case 0:
			return 3;
		case 1:
			return room;
		case 2:
			return room;
		case 3:
			return 7;
		}
	case 7:
		switch (side) {
		case 0:
			return 4;
		case 1:
			return 6;
		case 2:
			return room;
		case 3:
			return 8;

}
	case 8:
		switch (side) {
		case 0:
			return 5;
		case 1:
			return 7;
		case 2:
			return room;
		case 3:
			return room;
		}
	}
}
