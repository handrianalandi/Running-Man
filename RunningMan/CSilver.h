#pragma once
#include "CCoin.h"
class CSilver :
	public CCoin
{
protected:
	void initSprite();
public:
	CSilver();
	~CSilver();
	CSilver(const CSilver& n);
	int getType();
};

