#include "Fishman.h"
#include "Simon.h"

void CFishman::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	float s_x, s_y;
	CSimon* simon = new CSimon();
	simon->GetPosition(s_x, s_y);
	if (y <= 448)
	{
		vy = SIMON_GRAVITY * dt;
		vy = 1;
		if (x < s_x)
		{
			nx = 1;
			vx = 0.5f;
		}
		else
		{
			nx = -1;
			vx = -0.15f;
		}
	}

	if (x < s_x)
	{
		nx = 1;
	}
	else
	{
		nx = -1;
	}

	if (vx == 0)
	{
		CGameObject::Update(dt);
		y += dy;
	}
	else
	{
		if (dt_die == 0)
		{
			if (state == TORCH_STATE_NOT_EXSIST) {
				dt_die = GetTickCount();
			}
			else
			{
				CGameObject::Update(dt);

				// Simple fall down
				vy += SIMON_GRAVITY * dt;

				vector<LPGAMEOBJECT> listBrick;
				for (int i = 0; i < coObjects->size(); i++)
				{

					if (dynamic_cast<CBrick*>(coObjects->at(i)))
					{
						CBrick* brick = dynamic_cast<CBrick*>(coObjects->at(i));
						listBrick.push_back(brick);
					}

				}

				vector<LPCOLLISIONEVENT> coEvents;
				vector<LPCOLLISIONEVENT> coEventsResult;

				coEvents.clear();

				// turn off collision when die 
				if (state != SIMON_STATE_DIE)
					CalcPotentialCollisions(&listBrick, coEvents);

				// No collision occured, proceed normally
				if (coEvents.size() == 0)
				{
					x += dx;
					y += dy;
				}
				else
				{
					float min_tx, min_ty, nx = 0, ny;

					FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

					//// block 
					//x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
					x += dx;
					y += min_ty * dy + ny * 0.4f;

					if (ny != 0) vy = 0;
				}
				// clean up collision events
				for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
			}
		}
		else
		{
			if (item != NULL) {//co item
				if (GetTickCount() - dt_die > 150) // cho 150 mili second
				{

					item->Update(dt, coObjects);
					state = TORCH_STATE_ITEM;
				}
			}
		}
	}
	if (x <= 3076 || x >= 3464)
		vx = -vx;

}
void CFishman::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{

	if (state == TORCH_STATE_EXSIST)
	{
		left = x;
		top = y;
		right = x + GHOST_BBOX_WIDTH;
		bottom = y + GHOST_BBOX_HEIGHT;
	}
	else if (state == TORCH_STATE_ITEM)
	{
		item->GetPosition(x, y);
		item->GetBoundingBox(left, top, right, bottom);
	}
}