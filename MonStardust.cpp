#include "stdafx.h"
#include "Character.h"
#include "MonStardust.h"


void MonStardust::Init()
{
	Monster::Init();
	eType = STARDUST;

	mat = { D3DXVECTOR2(500, 320), 1, 1, 0, 0 };
	frame = { 1, 1, 0, 0 };

	fYMove = 0.0f;
	iYMoveCount = 0;

	SetCollider();

	IMAGEMANAGER->AddImage("STARDUST_DEF", "./Texture/Monster/Stardust/Sprite_Monster_Stardust.png");
}

void MonStardust::Update(double deltaTime)
{
	MoveY(deltaTime);
}

void MonStardust::Render()
{
	IMAGEMANAGER->DrawImage("STARDUST_DEF", mat);
}

void MonStardust::Release()
{
}

void MonStardust::SetPosition(D3DXVECTOR2 pos)
{
	mat.pos = pos;
}

//

void MonStardust::SetCollider()
{
	
	CircleCollider* destA = new CircleCollider(mat.pos, D3DXVECTOR2(37.0f, 16.0f), 41.0f);
	col.colliderList.push_back(destA);
	CircleCollider* destB = new CircleCollider(mat.pos, D3DXVECTOR2(-32.0f, -1.0f), 31.0f);
	col.colliderList.push_back(destB);
}

void MonStardust::MoveY(double deltaTime)
{
	fYMove = sin(-PI / 2 + PI / 60 * iYMoveCount++) / 2 * 10.0f;
	mat.pos.y += fYMove;
}
