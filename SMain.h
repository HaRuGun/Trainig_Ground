#pragma once
#include "Scene.h"

class CharYuuna;
class MonStardust;

class SMain : public Scene
{
protected:
	CharYuuna *yuuna;
	vector<MonStardust*> vecStar;

public:

	void Init();
	void Update(double deltaTime);
	void Render();
	void Release();

	SMain();
	virtual ~SMain();
};

