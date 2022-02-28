#pragma once
#include "CCoin.h"
class CRuby :
	public CCoin
{
protected:
	void initSprite();
public:
	CRuby();
	~CRuby();
	CRuby(const CRuby& n);
	int getType();
};

