#include "CGold.h"

void CGold::initSprite()
{
	texture.loadFromFile("images/Goldcoin.png");
	sprite.setTexture(texture);
	CCoin::initSprite();
}

CGold::CGold()
{
	initVariables();
	initSprite();
}

CGold::~CGold()
{
}

CGold::CGold(const CGold& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}

int CGold::getType()
{
	return 1;
}


