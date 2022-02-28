#include "CObject.h"


CObject::CObject()
{
	
}

CObject::CObject(const CObject& n)
{
}

void CObject::updateAnimation()
{
	if (time.getElapsedTime().asSeconds() > 0.2f) {
		if (this->intRect.left == maxSize) {
			this->intRect.left = 0;
		}
		else {
			this->intRect.left += plusWidth;
		}
		this->sprite.setTextureRect(this->intRect);
		time.restart();
	}
}

Sprite& CObject::getSprite()
{
	return sprite;
}

Texture& CObject::getTexture()
{
	return texture;
}

IntRect& CObject::getIntRect()
{
	return intRect;
}

void CObject::setMaxSize(int x)
{
	maxSize = x;
}

void CObject::setplusWidth(int x)
{
	plusWidth = x;
}
