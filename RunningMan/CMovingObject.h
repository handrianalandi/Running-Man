#pragma once
#include "CObject.h"
class CMovingObject :
	public CObject
{
protected:
	Vector2f direction;
	virtual void initDirection();
public:
	void setDirection(float x,float y);
};

