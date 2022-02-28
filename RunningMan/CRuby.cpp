#include "CRuby.h"

void CRuby::initSprite()
{
	texture.loadFromFile("images/Rubycoin.png");
	sprite.setTexture(texture);
	CCoin::initSprite();
}

CRuby::CRuby()
{
	initVariables();
	initSprite();
}

CRuby::~CRuby()
{
}

CRuby::CRuby(const CRuby& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}

int CRuby::getType()
{
	return 2;
}
