#include "CSilver.h"

void CSilver::initSprite()
{
	texture.loadFromFile("images/Silvercoin.png");
	sprite.setTexture(texture);
	CCoin::initSprite();
}

CSilver::CSilver()
{
	initVariables();
	initSprite();
}

CSilver::~CSilver()
{
}

CSilver::CSilver(const CSilver& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}

int CSilver::getType()
{
	return 0;
}
