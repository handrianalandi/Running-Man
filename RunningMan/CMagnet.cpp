#include "CMagnet.h"

void CMagnet::initSprite()
{
	texture.loadFromFile("images/magnet2.png");
	sprite.setTexture(texture);
	sprite.setScale(0.03f, 0.03f);
}

CMagnet::CMagnet()
{
	initSprite();
}

CMagnet::~CMagnet()
{
}

CMagnet::CMagnet(const CMagnet& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->direction = n.direction;
}

int CMagnet::getType()
{
	return 0;
}
