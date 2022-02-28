#include "CPlayer.h"

void CPlayer::initVariables()
{
	intRect.top = 0;
	intRect.left = 0;
	intRect.width = 530;
	intRect.height = 747;
	keyApressed = 0; keyDpressed = 0;
	//subject to change
	maxSize = 3710;
	plusWidth = 530;
}


void CPlayer::initSprite()
{
	
	texture.loadFromFile("images/idlemenu.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(this->intRect);
	sprite.setPosition(100.f, 225.f);
	sprite.setScale(0.21f, 0.2f);
}


CPlayer::CPlayer()
{
	this->initVariables();
	this->initSprite();
	initDirection();
}


CPlayer::~CPlayer()
{
	
}


CPlayer::CPlayer(const CPlayer& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;

}


void CPlayer::update(bool die)
{
	this->updateAnimation();
	if (!die) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (!keyApressed) {
				keyApressed = 1;
				keyDpressed = 0;
				this->sprite.move(-60.f, 0.f);
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (!keyDpressed) {
				keyDpressed = 1;
				keyApressed = 0;
				this->sprite.move(60.f, 0.f);
			}
		}
		else {
			keyApressed = 0;
			keyDpressed = 0;
		}

		//out of range check
		if (this->sprite.getPosition().x < 60.f) {
			this->sprite.setPosition(Vector2f(60.f, this->sprite.getPosition().y));
		}
		if (this->sprite.getPosition().x > 180.f) {
			this->sprite.setPosition(Vector2f(180.f, this->sprite.getPosition().y));
		}
	}
}


void CPlayer::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
