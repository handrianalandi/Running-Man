#pragma once
#include "CMovingObject.h"
class CPlayer :
	public CMovingObject
{
protected:
	//vars
	int keyApressed, keyDpressed;


	//init
	void initVariables();
	void initSprite();
public:
	CPlayer();
	~CPlayer();
	CPlayer(const CPlayer& n);
	void update(bool die);
	void render(RenderTarget& target);



};

