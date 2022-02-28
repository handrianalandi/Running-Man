#include "CMovingObject.h"

void CMovingObject::initDirection()
{
	direction.x = 0.f;
	direction.y = 3.f;
}

void CMovingObject::setDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
}
