#include "Scene.h"
#include "Enemy.h"


CScene* CScene::__instance = NULL;

CScene* CScene::GetInstance()
{
	if (__instance == NULL) __instance = new CScene();
	return __instance;
}


CScene::CScene(int id)
{
	this->id = id;
	map = CMap::GetInstance();
}


void CScene::LoadResoure()
{
	CManagementTexture* manage = new CManagementTexture();
	objects.clear();
	dagger = CDagger::GetInstance();
	objects.push_back(dagger);
	if (id == 0) {
		map->SetMap(0);
		simon = CSimon::GetInstance();
		simon->SetPosition(0.0f, 20.0f);
		objects.push_back(simon);


		CTorch* torch0 = new CTorch(3);
		torch0->SetPosition(190, 300);
		objects.push_back(torch0);

		CTorch* torch1 = new CTorch(1);
		torch1->SetPosition(416, 300);
		objects.push_back(torch1);

		CTorch* torch2 = new CTorch(1);
		torch2->SetPosition(640, 300);
		objects.push_back(torch2);

		CTorch* torch3 = new CTorch(2);
		torch3->SetPosition(864, 300);
		objects.push_back(torch3);


		for (int i = 0; i < 96; i++)
		{
			CBrick* brick = new CBrick();
			brick->SetPosition(i * 32, 360);
			objects.push_back(brick);
		}
		hiden = new CHidenObject();
		hiden->SetPosition(1364, 300);
		objects.push_back(hiden);
	}
	else
	{
		map->SetMap(1);


		dagger = CDagger::GetInstance();
		objects.push_back(dagger);

		simon = CSimon::GetInstance();
		simon->SetPosition(2500.0f, 20.0f);
		objects.push_back(simon);


		if (id == 1)
		{
			CTorch* candle = new CTorch(3, 1);
			candle->SetPosition(190, 300);
			objects.push_back(candle);

			CTorch* candle1 = new CTorch(1, 1);
			candle1->SetPosition(416, 250);
			objects.push_back(candle1);

			CTorch* candle2 = new CTorch(1, 1);
			candle2->SetPosition(640, 300);
			objects.push_back(candle2);

			CTorch* candle3 = new CTorch(2, 1);
			candle3->SetPosition(864, 250);
			objects.push_back(candle3);

			CGhost* enemy = new CGhost();
			enemy->SetPosition(500, 250);
			enemy->SetSpeed(-0.05f, 0);
			objects.push_back(enemy);

			CPanther* enemy2 = new CPanther();
			enemy2->SetPosition(1800, 150);
			enemy2->SetSpeed(0, 0);
			objects.push_back(enemy2);

			for (int i = 0; i < 98; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 394);
				objects.push_back(brick);
			}
			for (int i = 100; i < 112; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 394);
				objects.push_back(brick);
			}
			for (int i = 43; i < 46; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 265);
				objects.push_back(brick);
			}

			for (int i = 47; i < 57; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 200);
				objects.push_back(brick);
			}
			for (int i = 58; i < 63; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 264);
				objects.push_back(brick);
			}
			for (int i = 87; i < 105; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 200);
				objects.push_back(brick);
			}
			for (int i = 104; i < 107; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 264);
				objects.push_back(brick);
			}
			CHidenObject* hiden = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, 1, -1);
			hiden->SetPosition(1236, 350);
			objects.push_back(hiden);
			CHidenObject* hiden2 = new CHidenObject(HIDENOBJECT_TYPE_UPSTAIR, -1, 1, 100);
			hiden2->SetPosition(1380, 170);
			objects.push_back(hiden2);
			CHidenObject* hiden3 = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, 1, -1);
			hiden3->SetPosition(1425, 220);
			objects.push_back(hiden3);
			CHidenObject* hiden4 = new CHidenObject(HIDENOBJECT_TYPE_UPSTAIR, -1, 1, 100);
			hiden4->SetPosition(1535, 80);
			objects.push_back(hiden4);
			CHidenObject* hiden5 = new CHidenObject(HIDENOBJECT_TYPE_UPSTAIR, 1, 1, 100);
			hiden5->SetPosition(1790, 80);
			objects.push_back(hiden5);
			CHidenObject* hiden6 = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, -1, -1);
			hiden6->SetPosition(1870, 220);
			objects.push_back(hiden6);

			CHidenObject* hiden7 = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, 1, -1);
			hiden7->SetPosition(2555, 350);
			objects.push_back(hiden7);
			CHidenObject* hiden8 = new CHidenObject(HIDENOBJECT_TYPE_UPSTAIR, -1, 1, 100);
			hiden8->SetPosition(2785, 80);
			objects.push_back(hiden8);

			CGate* gate = new CGate();
			gate->SetPosition(3063, 105);
			objects.push_back(gate);
		}
		else if (id == 2)
		{
			simon->SetPosition(3069, 77);
			for (int i = 96; i < 104; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 200);
				objects.push_back(brick);
			}

			for (int i = 104; i < 107; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 264);
				objects.push_back(brick);
			}

			for (int i = 95; i < 99; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 394);
				objects.push_back(brick);
			}

			for (int i = 100; i < 112; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 394);
				objects.push_back(brick);
			}
			CHidenObject* hiden = new CHidenObject(HIDENOBJECT_TYPE_DOOR, 1, 1, 100);
			hiden->SetPosition(3137, 335);
			objects.push_back(hiden);
			CHidenObject* hiden1 = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, -1, -1);
			hiden1->SetPosition(3566, 335);
			objects.push_back(hiden1);
			CHidenObject* hiden2 = new CHidenObject(HIDENOBJECT_TYPE_UPSTAIR, 1, 1, 100);
			hiden2->SetPosition(3393, 220);
			objects.push_back(hiden2);
		}
		else if (id == 3)
		{
		simon->SetPosition(3194, 393);
			for (int i = 96; i < 110; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 614);
				objects.push_back(brick);
			}
			
			for (int i = 112; i < 114; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 614);
				objects.push_back(brick);
			}
			for (int i = 116; i < 125; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 614);
				objects.push_back(brick);
			}
			for (int i = 102; i < 104; i++)
			{
				CBrick* brick = new CBrick(1);
				brick->SetPosition(i * 32, 550);
				objects.push_back(brick);
			}
			CHidenObject* hiden1 = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, -1, -1);
			hiden1->SetPosition(3282, 472);
			objects.push_back(hiden1);
			CHidenObject* hiden2 = new CHidenObject(HIDENOBJECT_TYPE_DOWNSTAIR, -1, -1);
			hiden2->SetPosition(3980, 526);
			objects.push_back(hiden2);
		}
	}
}

void CScene::Update(DWORD dt)
{
	float cx, cy;
	simon->GetPosition(cx, cy);


	vector<LPGAMEOBJECT> coObjects;
	for (int i = 0; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}

	// Update camera to follow simon
	cx -= SCREEN_WIDTH / 2 - 40;
	cy -= SCREEN_HEIGHT / 2 + 40;
	if (id == 0)
	{
		
		if (cx < 0) cx = 0; if (cx > 966) cx = 966;
	}
	else if(id == 1)
	{
		if(cx < 3100)
			if (cx < 0) cx = 0; if (cx > 3150 - SCREEN_WIDTH) cx = 3150 - SCREEN_WIDTH;
	}
	else if(id ==2)
	{
		if (cx < 3038)
			cx = 3038;
		if (cx > 3645 - SCREEN_WIDTH)
			cx = 3645 - SCREEN_WIDTH;

	}
	else if (id == 3)
	{
		if (cx < 3073)
			cx = 3073;
		if (cx > 4100 - SCREEN_WIDTH)
			cx = 4100 - SCREEN_WIDTH;
	}
	else
	{
		if (cx < 3711)
			cx = 3711;
		if (cx > 5630 - SCREEN_WIDTH)
			cx = 5630 - SCREEN_WIDTH;
	}
	if (id == 3)
		cy = 430;
	else
		cy = 0;
	game = CGame::GetInstance();
	game->SetCamPos(cx, cy);
}
void CScene::Render() 
{
	map->DrawMap();

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}
}
void CScene::SetMap(int id)
{
	this->id = id;
}