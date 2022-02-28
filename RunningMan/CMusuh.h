#pragma once
#include "CMovingObject.h"
class CMusuh :
	public CMovingObject
{
protected:
	virtual void initDirection() {};
	virtual void initVariables();
	virtual void initSprite()=0;
public:
	CMusuh(); ~CMusuh(); CMusuh(const CMusuh& n);
	virtual void update(bool die) = 0;
	void render(RenderTarget& target);
	virtual int getType()=0;
	Clock& get_time();
};

