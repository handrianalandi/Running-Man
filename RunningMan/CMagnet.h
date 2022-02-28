#pragma once
#include "CPowerUp.h"
class CMagnet :
	public CPowerUp
{
protected:
	void initSprite();
public:
	CMagnet();
	~CMagnet();
	CMagnet(const CMagnet& n);
	int getType();
};

