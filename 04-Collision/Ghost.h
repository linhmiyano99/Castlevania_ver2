#pragma once
#include "Enemy.h"

#define GHOST_BBOX_WIDTH 40
#define GHOST_BBOX_HEIGHT 60

class CGhost: public CEnemy
{
public:
	CGhost(float _x = 2000, float _y = 0, int id = 0) :CEnemy(_x, _y, id)
	{
		animations.clear();
		AddAnimation(1000);
		AddAnimation(800);
		nx = -1;
	}
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};