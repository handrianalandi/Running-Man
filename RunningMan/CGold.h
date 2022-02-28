#pragma once
#include "CCoin.h"
class CGold :
	public CCoin
{
protected:
	void initSprite();
public:
	CGold();
	~CGold();
	CGold(const CGold& n);
	int getType();
};

