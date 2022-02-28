#pragma once
#include "CMusuh.h"
class CFence :
	public CMusuh
{
protected:
	void initSprite();
public:
	CFence(); ~CFence(); CFence(const CFence& n);
	void update(bool die);
	int getType();
};

