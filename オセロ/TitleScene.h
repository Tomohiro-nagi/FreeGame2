#pragma once
#include "SceneBase.h"
class TitleScene :
	public SceneBase
{
public:
	TitleScene(SceneManager* manager);
	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Release(void) override;
private:
	int mImage;
};

