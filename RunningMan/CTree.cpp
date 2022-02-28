#include "CTree.h"

void CTree::initVariables()
{
}

void CTree::initSprite()
{
	texture.loadFromFile("images/tree.png");
	sprite.setTexture(texture);
	// 60(width sideroad)/95(width png)
	sprite.setScale(sf::Vector2f(0.63f, 0.5f));
	int rando = rand() % 2;
	switch (rando)
	{
	case 0:
		sprite.setPosition(240.f, 0.f - sprite.getTexture()->getSize().y);
	default:
		break;
	}
}



CTree::CTree()
{
	initVariables();
	initSprite();
	initDirection();
}

CTree::~CTree()
{
}

CTree::CTree(const CTree& n)
{
	this->direction = n.direction;
	this->sprite = n.sprite;
	this->texture = n.texture;
}



void CTree::update(bool die)
{
	if (!die) {
		this->sprite.move(direction);
	}
}

void CTree::render(RenderTarget& target)
{
	target.draw(this->sprite);
}

void CTree::randomize()
{
	int rando = rand() % 2;
	switch (rando)
	{
	case 0:
		sprite.setPosition(240.f, 0.f - sprite.getTexture()->getSize().y);
		break;
	case 1:
		sprite.setPosition(0.f, 0.f - sprite.getTexture()->getSize().y); break;
	default:
		break;
	}
}
