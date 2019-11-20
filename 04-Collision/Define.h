﻿#pragma once


#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Castlevania 1986"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(0, 0, 0)
#define SCREEN_WIDTH 560
#define SCREEN_HEIGHT 460

#define MAX_FRAME_RATE 120

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif


// ID của Sprite, object
enum eType
{
	SIMON = 1,
	SIMON_TRANS = 2,

	// object nền
	GATE = 20,
	BRICK_1 = 21,
	BRICK_2 = 22,
	BRICK_3 = 23,


	// object
	TORCH = 31,
	OBJECT_HIDDEN_DOOR = 32,
	STAIR_UP = 33,
	STAIR_DOWN = 34,
	CANDLE = 35,
	OBJECT_HIDDEN_FISHMAN = 36,
	OBJECT_HIDDEN_GHOST_1 = 37,
	OBJECT_HIDDEN_GHOST_STOP_1 = 38,
	OBJECT_HIDDEN_PANTHER_JUMP = 39,


	// weapon
	VAMPIREKILLER = 41,
	DAGGER = 42,
	AXE = 43,

	// item
	HEART = 51,
	WHIPUPGRADE = 52,
	ITEMDAGGER = 53,
	SMALLHEART = 54,
	CHICKEN = 55,
	MONEY_1 = 56,
	MONEY_2 = 57,
	MONEY_3 = 58,
	MONEY_4 = 59,
	CLOCK = 60,
	ITEMAXE = 61,
	CROSS = 62,
	BOSSBALL = 63,


	// other
	FONT = 71,
	BOARD = 72,
	MAP1 = 73,
	MAP2 = 74,



	// Enemy
	GHOST = 141,
	PANTHER = 142,
	BAT = 143,
	FISHMEN = 144,

	//BOSS
	BOSS = 150
};

