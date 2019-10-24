#pragma once
#include "Enemy.h"

#define GHOST_BBOX_WIDTH 40
#define GHOST_BBOX_HEIGHT 60

class CGhost: public CEnemy
{
public:
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};