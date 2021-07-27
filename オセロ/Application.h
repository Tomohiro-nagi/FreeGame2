#pragma once
#include "SceneManager.h"

class GameScene;

class Application
{
public:			//�����o�֐�
	bool Init(void);
	void Run(void);
	bool Release(void);
private:		//�����o�ϐ�
	//�C���X�^���X�̐���
	SceneManager mSceneManager;
	GameScene* mGameScene;

};

