#pragma once
#include "TitleScene.h"
class SceneBase;
class Fader;

enum class SCENE_ID
{
	NONE,
	TITLE,
	GAME,
	GAMESET
};

class SceneManager
{
public:
	void Init(void);
	void Update(void);
	void Release(void);
	void ChangeScene(SCENE_ID nextId, bool isFading);

	//�o�ߎ��Ԃ̎擾
	float GetDeltaTime(void);

private:
	SCENE_ID mSceneID;
	SCENE_ID mWaitSceneID;


	SceneBase* mScene;
	Fader* mFader;

	bool mIsSceneChanging;

	//�f���^�^�C��
	float mTickCount;
	float mDeltaTime;

	void DoChangeScene(void);
};

