#include "CDrunk.h"

void CDrunk::initVariables()
{
	intRect.left = 0;
	intRect.top = 0;
	intRect.height = 417;
	intRect.width = 385;
	maxSize = 385;
	plusWidth =385;
	randtime = 1;
	//
	timermax = 50.f;
	timer = 0.f;
}

void CDrunk::initSprite()
{
	texture.loadFromFile("images/drunkman.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(this->intRect);
	sprite.setScale(0.13f, 0.143f);
	int rando = rand() % 3;
	switch (rando)
	{
	case 0:
		this->sprite.setPosition(60.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y)); 
		break;
	case 1:
		this->sprite.setPosition(120.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y)); 
		break;
	default:
		this->sprite.setPosition(183.f, 0.f - (sprite.getTexture()->getSize().y * sprite.getScale().y)); 
		break;
	}
}

void CDrunk::initDirection()
{
	if (sprite.getPosition().x == 60) {
		CMovingObject::initDirection();
		direction.x = 0.4f;
		/*direction.y = 3.f;*/
	}
	else if (sprite.getPosition().x == 120) {
		int rando = rand() % 2;
		switch (rando)
		{
		case 0:
			CMovingObject::initDirection();
			direction.x = 0.4f;
			/*direction.y = 3.f;*/ break;
		default:
			CMovingObject::initDirection();
			direction.x = -0.4f;
			/*direction.y = 3.f;*/
			break;
		}
		
	}
	else {
		CMovingObject::initDirection();
		direction.x = -0.4f;
		/*direction.y = 3.f;*/
	}
}

CDrunk::CDrunk()
{
	this->initDirection();
	this->initSprite();
	this->initVariables();
}

CDrunk::~CDrunk()
{

}

CDrunk::CDrunk(const CDrunk& n)
{
	this->direction = n.direction;
	this->intRect = n.intRect;
	this->maxSize = n.maxSize;
	this->plusWidth = n.plusWidth;
	this->sprite = n.sprite;
	this->texture = n.texture;
	this->time = n.time;
}

void CDrunk::update(bool die)
{
	updateAnimation();
	
	if (timer>=timermax) {
		timer = 0.f;
		time.restart();
		timermax = static_cast<float>(rand()%240+60);
		if (this->direction.x == 0.4f) {
			this->direction.x = -0.4f;
		}
		else {
			this->direction.x = 0.4f;
		}
	}
	else {
		timer += 1.f;
	}
	if (this->sprite.getPosition().x > 180) {
		this->sprite.setPosition(180.f, this->sprite.getPosition().y);
		direction.x = -0.4f;
	}
	if (this->sprite.getPosition().x < 60) {
		this->sprite.setPosition(60.f, this->sprite.getPosition().y);
		direction.x = 0.4f;
	}
	if (!die) {
		this->sprite.move(direction);
	}
	else {
		this->sprite.move(direction.x, 0.f);
	}
}

int CDrunk::getType()
{
	return 1;
}

