#include "CGranny.h"

void CGranny::initVariables()
{
	intRect.left = 0;
	intRect.top = 0;
	intRect.height = 113;
	intRect.width = 82;
	maxSize = 328;
	plusWidth = 82;
}

void CGranny::initSprite()
{
	texture.loadFromFile("images/granny.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(this->intRect);

	int rando = rand() % 2;
	switch (rando)
	{
	case 0:
		this->sprite.setPosition(120.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y)); sprite.setScale(-0.6f, 0.546f);
		break;
	default:
		this->sprite.setPosition(183.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y)); sprite.setScale(0.6f, 0.546f);
		break;
	}
}

void CGranny::initDirection()
{
	if (sprite.getPosition().x < 130) {
		CMovingObject::initDirection();
		direction.x = 0.55f;
		/*direction.y = 3.f;*/
		/*horizontaldir.x = 60.f;
		horizontaldir.y = 0.f;*/
	}
	else {
		CMovingObject::initDirection();
		direction.x = -0.55f;
		/*direction.y = 3.f;*/                                                                          
		/*horizontaldir.x = -60.f;
		horizontaldir.y = 0.f;*/
	}
}

CGranny::CGranny()
{
	this->initVariables();
	this->initSprite();
	this->initDirection();
}

CGranny::~CGranny()
{
}

CGranny::CGranny(const CGranny& n)
{
	this->direction = n.direction;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->time = n.time;
}

void CGranny::update(bool die)
{
	updateAnimation();
	

	if (!die) {
		this->sprite.move(direction);
	}
	else {
		this->sprite.move(direction.x, 0.f);
	}
	
	


}


int CGranny::getType()
{
	return 0;
}
