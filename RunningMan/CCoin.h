#pragma once
#include "CMovingObject.h"
class CCoin :
	public CMovingObject
{
protected:
	void initVariables();
	virtual void initSprite();
	
public:
	CCoin(); ~CCoin();
	CCoin(const CCoin& n);
	void update(bool die);
	void render(RenderTarget &target);
	virtual int getType()=0;
};

