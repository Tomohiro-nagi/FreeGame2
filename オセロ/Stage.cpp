#include <DxLib.h>
#include "GameCommon.h"
#include "Stage.h"

void Stage::Init(void)
{
	
}

void Stage::Update(void)
{
}

void Stage::Draw(void)
{
	for (int y = 0; y < SIZE_HEIGHT+1; y++)
	{
		for (int x = 0; x < SIZE_WIDTH + 1; x++)
		{
			DrawLine(GAME_AREA_X, y * BLOCK_IMG_SIZE + BLOCK_IMG_SIZE, BLOCK_IMG_SIZE * SIZE_WIDTH+GAME_AREA_X, y * BLOCK_IMG_SIZE + BLOCK_IMG_SIZE, 0xffffff);
			DrawLine(x * BLOCK_IMG_SIZE + GAME_AREA_X, BLOCK_IMG_SIZE, x*BLOCK_IMG_SIZE+GAME_AREA_X ,BLOCK_IMG_SIZE * SIZE_HEIGHT+BLOCK_IMG_SIZE, 0xffffff);
			
		}
	}
}

void Stage::Release(void)
{
}
