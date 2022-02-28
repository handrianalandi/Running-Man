#include "CCoin.h"

void CCoin::initVariables()
{
	intRect.left = 0;
	intRect.top = 0;
	intRect.height = 16;
	intRect.width = 16;
	maxSize = 64;
	plusWidth = 16;
}

void CCoin::initSprite()
{
	sprite.setTextureRect(intRect);
	int rando = rand() % 3;
	switch (rando)
	{
	case 0:
		//((60-16)/2)
		sprite.setPosition(82.f, 0.f-16.f);
		break;
	case 1:
		sprite.setPosition(142.f, 0.f - 16.f);
		break;
	case 2:
		sprite.setPosition(202.f, 0.f - 16.f);
		break;
	default:
		break;
	}
}


CCoin::CCoin()
{
	this->initVariables();
	this->initSprite();
	this->initDirection();
}

CCoin::~CCoin()
{
}

CCoin::CCoin(const CCoin& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->direction = n.direction;
}

void CCoin::update(bool die)
{
	if (!die) {
		this->sprite.move(direction);
	}
	updateAnimation();
}

void CCoin::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
