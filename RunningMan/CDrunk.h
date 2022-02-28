#pragma once
#include "CMusuh.h"
class CDrunk :
	public CMusuh
{
protected:
	int randtime;
	float timermax, timer;
	void initVariables();
	void initSprite();
	void initDirection();
public:
	CDrunk();
	~CDrunk();
	CDrunk(const CDrunk& n);
	void update(bool die);
	int getType();
};

