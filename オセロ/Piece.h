#pragma once
#include "GameCommon.h"
#include "Vector2.h"

class GameScene;
class SceneManager;

class Piece
{
public:
	Piece(SceneManager* mSceneManager);
	void Init(GameScene* scene);
	void Update(void);
	void Draw(void);
	void Release(void);



	int count[BlockType::BLOCK_MAX] = {};

private:
	GameScene* mScene;
	SceneManager* mSceneM;

	int mImage[PieceMAX];

	//��
	int mImageWhite;
	int mImageBlack;

	//�}�b�v�̏��
	int mMap[SIZE_HEIGHT][SIZE_WIDTH];

	Vector2 mPos;

	int mTurn;

	bool cantPut;

	int BlinkCnt;

	bool WinFlag;

	int BHandl;//BGM�̃n���h��

	float time;

	bool CheckCanPut(int Turn,int x ,int y,bool TurnOver);

	bool CheckCanPutAll(int turn);

	bool FinishBoard(void);
};

