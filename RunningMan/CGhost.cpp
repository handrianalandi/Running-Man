#include "CGhost.h"

void CGhost::initSprite()
{
	this->texture.loadFromFile("images/ghost.png");
	this->sprite.setTexture(texture);
	sprite.setScale(0.05f, 0.05f);
	sprite.setColor(Color(255, 255, 255, 120));
}

CGhost::CGhost()
{
	this->initSprite();
}

CGhost::~CGhost()
{
}

CGhost::CGhost(const CGhost& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->direction = n.direction;
}

int CGhost::getType()
{
	return 1;
}
