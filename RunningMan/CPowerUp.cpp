#include "CPowerUp.h"

void CPowerUp::initVariables()
{

}

void CPowerUp::initSprite()
{
	int rando = rand() % 3;
	switch (rando)
	{
	case 0:
		//((60-16)/2)
		sprite.setPosition(82.f, 0.f - 16.f);
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

CPowerUp::CPowerUp()
{
	this->initVariables();
	this->initSprite();
	this->initDirection();
}

CPowerUp::~CPowerUp()
{
}

CPowerUp::CPowerUp(const CPowerUp& n)
{
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->direction = n.direction;
}

void CPowerUp::update(bool die)
{
	if (!die) {
		this->sprite.move(direction);
	}
}

void CPowerUp::render(RenderTarget& target)
{
	target.draw(this->sprite);
}
