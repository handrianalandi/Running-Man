#pragma once
#include "CMusuh.h"
class CGranny :
	public CMusuh
{
protected:
	/*Vector2f horizontaldir;*/
	void initVariables();
	void initSprite();
	void initDirection();
public:
	CGranny(); ~CGranny(); CGranny(const CGranny& n);
	void update(bool die) ;
	int getType();
};

