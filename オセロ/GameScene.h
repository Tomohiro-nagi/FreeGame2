#pragma once

#include "SceneBase.h"
class Stage;
class Piece;

class SceneManager;

class GameScene : public SceneBase
{
public:

	GameScene(SceneManager* manager);
	void Init(void);
	void Update(void);
	void Draw(void);
	void Release(void);

	void ChangeScene(void);

private:
	Stage* stage;
	Piece* piece;
	
};

