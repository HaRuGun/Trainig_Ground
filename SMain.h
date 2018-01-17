#pragma once
#include "Scene.h"

class CharYuuna;

class SMain : public Scene
{
protected:
	CharYuuna *yuuna;

public:

	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	SMain();
	virtual ~SMain();
};

