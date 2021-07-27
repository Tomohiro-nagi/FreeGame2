#include <DxLib.h>
#include "KeyCheck.h"
#include "GameCommon.h"
#include "SceneManager.h"
#include "Application.h"

bool Application::Init(void)
{
	SetWindowText(L"オセロ");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	KeyInit();

	mSceneManager.Init();
	/*mGameScene = new GameScene();
	mGameScene->Init();*/

	return true;
}

void Application::Run(void)
{
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		CheckKeyList();
		mSceneManager.Update();



		ScreenFlip();  // 裏画面を表画面に瞬間コピー
	}
}

bool Application::Release(void)
{

	mSceneManager.Release();
	DxLib_End();  // DXライブラリの終了処理
	return true;     //このプログラムの終了

}
