#include "CFence.h"

void CFence::initSprite()
{
	texture.loadFromFile("images/fence2.png");
	this->sprite.setTexture(texture);
	this->sprite.setScale(0.7f, 0.7f);
	/*this->sprite.setScale(0.05f, 0.125f);*/
	int rando = rand() % 3;
	switch (rando)
	{
	case 0:
		this->sprite.setPosition(70.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	case 1:
		this->sprite.setPosition(130.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	default:
		this->sprite.setPosition(190.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y));
		break;
	}
}

CFence::CFence()
{
	CMovingObject::initDirection();
	this->initSprite();

}

CFence::~CFence()
{
}

CFence::CFence(const CFence& n)
{
	this->texture = n.texture;
	this->sprite = n.sprite;
	this->direction = n.direction;
	this->time = n.time;
}

void CFence::update(bool die)
{
	if (!die) {
		this->sprite.move(direction);
	}
	else {
		this->sprite.move(direction.x, 0.f);
	}
}

int CFence::getType()
{
	return 2;
}


