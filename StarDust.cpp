#include "stdafx.h"
#include "StarDust.h"


void StarDust::Init()
{
	Monster::Init();
	eType = STARDUST;

	mat = { 1, 1, 500, 320, 0, 0 };
	frame = { 1, 1, 0, 0 };

	fYMove = 0.0f;
	iYMoveCount = 0;

	IMAGEMANAGER->AddImage("STARDUST_DEF", "./Texture/Monster/Stardust/Sprite_Monster_Stardust.png");
}

void StarDust::Update(double deltaTime)
{
	MoveY(deltaTime);
}

void StarDust::Render()
{
	IMAGEMANAGER->DrawImage("STARDUST_DEF", mat);
}

void StarDust::Release()
{
}

//

void StarDust::MoveY(double deltaTime)
{
	
	fYMove = sin(-PI / 2 + PI / 60 * iYMoveCount++) / 2 * 50.0f + 320;
	mat.y = fYMove;
}
