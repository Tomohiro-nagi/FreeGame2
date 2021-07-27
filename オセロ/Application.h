#pragma once
#include "SceneManager.h"

class GameScene;

class Application
{
public:			//メンバ関数
	bool Init(void);
	void Run(void);
	bool Release(void);
private:		//メンバ変数
	//インスタンスの生成
	SceneManager mSceneManager;
	GameScene* mGameScene;

};

