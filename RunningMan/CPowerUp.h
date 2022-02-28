#pragma once
#include "CMovingObject.h"
class CPowerUp :
	public CMovingObject
{
protected:
	void initVariables();
	virtual void initSprite();
public:
	CPowerUp(); ~CPowerUp();
	CPowerUp(const CPowerUp& n);
	void update(bool die);
	void render(RenderTarget& target);
	virtual int getType() = 0;
};

