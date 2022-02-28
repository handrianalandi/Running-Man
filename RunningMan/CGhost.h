#pragma once
#include "CPowerUp.h"
class CGhost :
	public CPowerUp
{
protected:
	void initSprite();
public:
	CGhost();
	~CGhost();
	CGhost(const CGhost& n);
	int getType();
};

