#include "stdafx.h"
#include "CharYuuna.h"


void CharYuuna::Init()
{
	Character::Init();
	eType = YUUNA;

	mat = { 1, 1, 640, 320, 0, 0 };
	frame = { 1, 1, 0, 0 };

	IMAGEMANAGER->AddImage("YUUNA_IDLE", "./Texture/Character/Yuuna/Yuuna_Idle.png");

}

void CharYuuna::Update(double deltaTime)
{

}

void CharYuuna::Render()
{
	IMAGEMANAGER->DrawFrameImage("YUUNA_IDLE", frame, mat);
}

void CharYuuna::Release()
{
}