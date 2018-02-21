#include "stdafx.h"

#include "CharYuuna.h"
#include "MonStardust.h"

#include "SMain.h"

SMain::SMain()
{
}

SMain::~SMain()
{
}

void SMain::Init() 
{
	yuuna = new CharYuuna();
	yuuna->Init();

	for (int i = 5; 0 < i; --i)
	{
		MonStardust *dest = new MonStardust();
		vecStar.push_back(dest);
	}

	for (auto& iter : vecStar)
	{
		iter->Init();

		double destX = RandomGeneratoer<double>(0.0, SCREEN_WIDTH);
		double destY = RandomGeneratoer<double>(0.0, SCREEN_HEIGHT);
		iter->SetPosition(D3DXVECTOR2(destX, destY));

		iter->SetChar(yuuna);
	}
}

void SMain::Update(double deltaTime)
{
	yuuna->Update(deltaTime);
	for (auto& iter : vecStar)
	{
		iter->Update(deltaTime);
	}
}

void SMain::Render() 
{
	yuuna->Render();
	for (auto& iter : vecStar)
	{
		iter->Render();
	}
}

void SMain::Release()
{
	yuuna->Release();
	for (auto& iter : vecStar)
	{
		iter->Release();
	}
}