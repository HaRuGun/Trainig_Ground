#pragma once
#include "Scene.h"

class CharYuuna;
class StarDust;

class SMain : public Scene
{
protected:
	CharYuuna *yuuna;
	StarDust *star;

public:

	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	SMain();
	virtual ~SMain();
};

