#pragma once
#include "CMovingObject.h"
class CTree :
	public CMovingObject
{
protected:
	void initVariables();
	void initSprite();
	
public:
	CTree();
	~CTree();
	CTree(const CTree& n);
	void update(bool die);
	void render(RenderTarget& target);
	void randomize();
};

