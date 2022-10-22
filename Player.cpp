#include "Player.h"

bool Player::initialize(){
	if (!tex.loadFromFile("images/player.png")) return false;
	if(!t_sword.loadFromFile("images/sword.png")) return false;
	sprite.setTexture(tex);
	sprite.setTextureRect(sf::IntRect(0,0,20,20));
	up = false;
	down = false;
	left = false;
	right = false;
	sword = new sf::Sprite(t_sword);
	sword_sheathed = PLAYER_DEFAULT_SWORD;
	sword->setOrigin(5,0);
	return true;
}

bool Player::checkCollisions(float x, float y, std::vector<sf::FloatRect>& hitboxes) {
	for (auto i = hitboxes.begin(); i != hitboxes.end(); i++) {
		if (i->contains(x, y)) {
			return true;
		}
	}
	return false;
}
void Player::draw(sf::RenderWindow& window) {
    if(!sword_sheathed)
        window.draw(*sword);
	window.draw(sprite);
}

void Player::update(sf::Time dt, std::vector<sf::FloatRect>& hitboxes, sf::Vector2f mousePos) {
	sf::Vector2f vec = sprite.getPosition();
	if (up) {
		if (!checkCollisions(vec.x+PLAYER_COLLISION_OFFSET, vec.y - PLAYER_SPEED * dt.asSeconds(), hitboxes)
		&& !checkCollisions(vec.x+PLAYER_WIDTH-PLAYER_COLLISION_OFFSET, (vec.y - PLAYER_SPEED * dt.asSeconds()), hitboxes))
			vec.y -= PLAYER_SPEED * dt.asSeconds();

			sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
	}
	else if (left) {
		if (!checkCollisions(vec.x - (PLAYER_SPEED * dt.asSeconds()), vec.y, hitboxes)&&
			!checkCollisions(vec.x - (PLAYER_SPEED * dt.asSeconds()), vec.y+PLAYER_HEIGHT-PLAYER_COLLISION_OFFSET, hitboxes)) {
			vec.x -= PLAYER_SPEED * dt.asSeconds();

			sprite.setTextureRect(sf::IntRect(PLAYER_WIDTH*2, 0, 20, 20));
		}
	}
	else if (down) {
		if (!checkCollisions(vec.x, vec.y + (PLAYER_SPEED * dt.asSeconds() + PLAYER_HEIGHT), hitboxes)&&
			!checkCollisions(vec.x+PLAYER_HEIGHT, vec.y + (PLAYER_SPEED * dt.asSeconds() + PLAYER_HEIGHT), hitboxes)) {
			vec.y += PLAYER_SPEED * dt.asSeconds();
			sprite.setTextureRect(sf::IntRect(PLAYER_WIDTH, 0, 20, 20));
		}

	}
	else if (right) {
		if (!checkCollisions(vec.x + (PLAYER_SPEED * dt.asSeconds()+PLAYER_WIDTH), vec.y, hitboxes)&&
			!checkCollisions(vec.x + (PLAYER_SPEED * dt.asSeconds() + PLAYER_WIDTH), vec.y+PLAYER_HEIGHT, hitboxes)) {
			vec.x += PLAYER_SPEED * dt.asSeconds();
			sprite.setTextureRect(sf::IntRect(PLAYER_WIDTH*3, 0, 20, 20));
		}
	}
	sprite.setPosition(vec);
	// Rotate the sword to point towards the mouse
	if(!sword_sheathed){
        sword->setPosition(vec.x, vec.y+static_cast<int>(PLAYER_HEIGHT/2));
        sf::Vector2f sVec = sword->getPosition();
        float angle = atan2(mousePos.y-sVec.y, mousePos.x-sVec.x );
        angle = (angle * (180/PI))+270;
        sword->setRotation(angle);
    }

}
