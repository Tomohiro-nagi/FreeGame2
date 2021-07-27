#include <DxLib.h>
#include <assert.h>
#include <cmath>
#include "KeyCheck.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Piece.h"



Piece::Piece(SceneManager* mSceneManager)
{
	mSceneM = mSceneManager;
}

void Piece::Init(GameScene* scene)
{
	mScene = scene;

	LoadDivGraph(L"Image/オセロ黒.png", 2, 2, 1, BLOCK_IMG_SIZE, BLOCK_IMG_SIZE,&mImage[0]);
	
	BHandl = LoadSoundMem(L"Bgm/囲碁・碁石を打つ01.mp3");

	mImageBlack = mImage[0];
	mImageWhite = mImage[1];

	for (int y = 0; y < SIZE_HEIGHT; y++)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			mMap[y][x] = BlockType::BLOCK_NONE;
		}
	}

	
	mMap[3][3] = BlockType::BLOCK_WHITE;
	mMap[4][4] = BlockType::BLOCK_WHITE;
	mMap[3][4] = BlockType::BLOCK_BLACK;
	mMap[4][3] = BlockType::BLOCK_BLACK;

	mPos = { 0,0 };
	mPos.x = (mPos.x / BLOCK_IMG_SIZE);
	mPos.y = (mPos.y / BLOCK_IMG_SIZE);

	mTurn = 0;

	cantPut = false;

	BlinkCnt = 0;

	WinFlag = false;


	time = 0.0f;
}

void Piece::Update(void)
{
		FinishBoard();
		

		time += mSceneM->GetDeltaTime();
		
		//mScene->ChangeScene();
	

	if (keyTrgDown[KEY_P2_RIGHT])
	{
		if (mPos.x < SIZE_WIDTH-1)
		{
			mPos.x += 1;
		}
		
	}

	if (keyTrgDown[KEY_P2_LEFT])
	{
		if (mPos.x > 0)
		{
			mPos.x -= 1;
		}
		
	}


	if (keyTrgDown[KEY_P2_UP])
	{
		if (mPos.y > 0)
		{
			mPos.y -= 1;
		}
	}

	if (keyTrgDown[KEY_P2_DOWN])
	{
		if (mPos.y < SIZE_HEIGHT - 1)
		{
			mPos.y += 1;
		}
	}
	

	if (!CheckCanPut(mTurn, mPos.x, mPos.y,false))
	{
		//置けないフラグをたてる
		cantPut = true;
		return;
	}


	if (keyTrgDown[KEY_P1_A])
	{
		CheckCanPut(mTurn, mPos.x, mPos.y, true);

		PlaySoundMem(BHandl, DX_PLAYTYPE_BACK);
			
		//mMap[mPos.y][mPos.x] = mTurn;
		mTurn ^= 1;

		if (!CheckCanPutAll(mTurn)) {
			mTurn ^= 1;
			return;
		}

	}

	

	
	//mMap[mPos.y][mPos.x] = BlockType::BLOCK_BLACK;
		
	
	
}

void Piece::Draw(void)
{
	float limitTime = 5.0f;

	float alfha = (sin((double)time * limitTime) + 1.0f) * 0.5f;
	alfha = alfha * 255.0f;

	for (int y = 0; y < SIZE_HEIGHT; y++)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			if (mMap[y][x] == BlockType::BLOCK_WHITE)
			{
				DrawGraph((x * BLOCK_IMG_SIZE) + GAME_AREA_X, (y * BLOCK_IMG_SIZE) + BLOCK_IMG_SIZE, mImageWhite, true);
			}
		}
	}

	for (int y = 0; y < SIZE_HEIGHT; y++)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			if (mMap[y][x] == BlockType::BLOCK_BLACK)
			{
				DrawGraph((x * BLOCK_IMG_SIZE) + GAME_AREA_X, (y * BLOCK_IMG_SIZE) + BLOCK_IMG_SIZE, mImageBlack, true);
			}
		}
	}

	if (!FinishBoard())
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alfha);
		DrawGraph(GAME_AREA_X + (mPos.x * BLOCK_IMG_SIZE), BLOCK_IMG_SIZE + (mPos.y * BLOCK_IMG_SIZE), mImage[mTurn], true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else if (FinishBoard())
	{

		int y = 100;
		for (int i = 0; i < BlockType::BLOCK_MAX; i++)
		{
			DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y - y, 0x000000, L"%d", count[i]);
			y += 50;
		}

		if (count[BlockType::BLOCK_BLACK] == count[BlockType::BLOCK_WHITE])
		{
			DrawString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y - 50, L"引き分け", 0xffffff);
		}

		if (count[BlockType::BLOCK_BLACK] > count[BlockType::BLOCK_WHITE])
		{
			DrawString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y - 50, L"黒の勝ち", 0xffffff);
		}

		if (count[BlockType::BLOCK_BLACK] < count[BlockType::BLOCK_WHITE])
		{
			DrawString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y - 50, L"白の勝ち", 0xffffff);
		}

	}
	
}

void Piece::Release(void)
{
	DeleteSoundMem(BHandl);
}



bool Piece::CheckCanPut(int Turn, int x, int y, bool TurnOver)
{

	int directions[][2] = {
	{0,-1},
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	};

	if (mMap[y][x] != BlockType::BLOCK_NONE)
	{
		return false;
	}
	for (int i = 0; i < DIRECTION_MAX; i++)
	{
		
		int _x = x, _y = y;
		
		_x += directions[i][0];
		_y += directions[i][1];

		if (mMap[_y][_x] != (Turn ^ 1))
		{
			continue;
		}
		while (1)
		{
			
			_x += directions[i][0];
			_y += directions[i][1];

			if ((_x < 0) || (_x >= SIZE_WIDTH) || (_y < 0) || (_y >= SIZE_HEIGHT))
			{
				break;
			}
			if (mMap[_y][_x] == BlockType::BLOCK_NONE)
			{
				break;
			}
			if (mMap[_y][_x] == Turn)
			{
				if (!TurnOver)
				{
					return true;
				}
				int x2 = x, y2 = y;
				while (1)
				{
					mMap[y2][x2] = Turn;
					
					x2 += directions[i][0];
					y2 += directions[i][1];

					

					if ((x2 == _x) && (y2 == _y))
					{
						break;
					}

					if (mMap[y2][x2] == Turn)
					{
						break;
					}
					
					
				}
			}
		}

	}
	return false;
}

bool Piece::CheckCanPutAll(int turn)
{
	for (int y = 0; y < SIZE_HEIGHT; y++)
	{
		for (int x = 0; x < SIZE_WIDTH; x++)
		{
			if (CheckCanPut(turn, x, y, false)) {
				return true;
			}
		}
	}
	return false;
}

bool Piece::FinishBoard(void)
{
	if ((!CheckCanPutAll(BlockType::BLOCK_BLACK)) && (!CheckCanPutAll(BlockType::BLOCK_WHITE)))
	{
		if (keyTrgDown[KEY_P1_B])
		{
			mScene->ChangeScene();
		}

		if (!WinFlag)
		{
			for (int y = 0; y < SIZE_HEIGHT; y++)
			{
				for (int x = 0; x < SIZE_WIDTH; x++)
				{
					if (mMap[y][x] != BlockType::BLOCK_NONE)
					{
						count[mMap[y][x]]++;
					}
				}
			}
			WinFlag = true;
		}
		
		return true;
	}

	return false;
}
