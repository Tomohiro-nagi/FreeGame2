#include <DxLib.h>
#include "GameCommon.h"
#include "SceneManager.h"
#include "Stage.h"
#include "Piece.h"
#include "GameScene.h"

GameScene::GameScene(SceneManager* manager) : SceneBase(manager)
{

}


void GameScene::Init(void)
{
	stage = new Stage();
	stage->Init();
	
	piece = new Piece(mSceneManager);
	piece->Init(this);

}

void GameScene::Update(void)
{
	//Draw();
	piece->Update();
}

void GameScene::Draw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0x00aa00, true);

	stage->Draw();

	piece->Draw();
}

void GameScene::Release(void)
{
}

void GameScene::ChangeScene(void)
{
	mSceneManager->ChangeScene(SCENE_ID::TITLE, true);
}
