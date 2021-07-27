#pragma once

//スクリーンサイズ
#define SCREEN_SIZE_X (800)
#define SCREEN_SIZE_Y (800)

//ゲーム開始エリア
#define GAME_AREA_X (100)

//ブロックのサイズ
#define BLOCK_IMG_SIZE (64)

//ブロックの数
#define SIZE (8)

//幅の数
#define SIZE_WIDTH (SIZE)

//高さの数
#define SIZE_HEIGHT (SIZE)

#define PieceMAX (2)

enum BlockType {
	BLOCK_NONE = -1,
	BLOCK_BLACK = 0,
	BLOCK_WHITE = 1,
	BLOCK_MAX
};

enum {
	DIRECTION_UP ,
	DIRECTION_UP_LEFT,
	DIRECTION_LEFT,
	DIRECTION_DOWN_LEFT,
	DIRECTION_DOWN,
	DIRECTION_DOWN_RIGHT,
	DIRECTION_RIGHT,
	DIRECTION_UP_RIGHT,
	DIRECTION_MAX
};


