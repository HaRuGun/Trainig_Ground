#include "stdafx.h"
#include <typeinfo>

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}


//


bool CircleCollider::CheckCollision(const CircleCollider& col) const
{
	float nowX = pos.x + offset.x;
	float nowY = pos.y + offset.y;

	float colX = col.pos.x + col.offset.x;
	float colY = col.pos.y + col.offset.y;

	bool result = SQUARE(colX - nowX) + SQUARE(colY - nowY) <= SQUARE(radius + col.radius);
	
	return result;
}

bool CircleCollider::CheckCollision(const RectCollider & col) const
{
	float nowX = pos.x + offset.x;
	float nowY = pos.y + offset.y;

	float colX = col.pos.x + col.offset.x;
	float colY = col.pos.y + col.offset.y;

	float halfWidth = col.width / 2;
	float halfHeight = col.height / 2;

	float disX = abs(nowX - colX);
	float disY = abs(nowY - colY);

	if (halfWidth + radius <= disX || halfHeight + radius <= disY)
		return false;

	if (disX <= halfWidth)
	{
		if (disY <= halfHeight)
			return true;

		return SQUARE(disX - halfWidth) + SQUARE(disY - halfHeight) < SQUARE(radius);
	}
	return true;
}

bool CircleCollider::CheckCollision(const LineCollider & col) const
{
	float nowX = pos.x + offset.x;
	float nowY = pos.y + offset.y;

	float fLength = DISTANCE(col.posA.x, col.posA.y, col.posB.x, col.posB.y);

	float fProjection = ((nowX - col.posA.x) * (col.posB.x - col.posA.x) + (nowY - col.posA.y) * (col.posB.y - col.posA.y)) / fLength;

	if (fProjection < 0)
		return DISTANCE(col.posA.x, col.posA.y, nowX, nowY) <= radius;
	else if (fLength < fProjection)
		return DISTANCE(col.posB.x, col.posB.y, nowX, nowY) <= radius;
	else
		return (abs((-1) * (nowX - col.posA.x) * (col.posB.y - col.posA.y) + (nowY - col.posA.y) * (col.posB.x - col.posA.x)) / fLength) <= radius;
}

bool RectCollider::CheckCollision(const CircleCollider & col) const
{
	return col.CheckCollision(*this);
}

bool RectCollider::CheckCollision(const RectCollider & col) const
{
	float nowX = pos.x + offset.x;
	float nowY = pos.y + offset.y;

	float colX = col.pos.x + col.offset.x;
	float colY = col.pos.y + col.offset.y;

	bool checkL = nowX - width / 2 <= colX + col.width / 2;
	bool checkR = colX - col.width / 2 <= nowX + width / 2;
	bool checkT = nowY - height / 2 <= colY + col.height / 2;
	bool checkB = colY - col.height / 2 <= nowY + height / 2;

	return (checkL && checkR) && (checkT && checkB);
}

bool RectCollider::CheckCollision(const LineCollider & col) const
{
	float nowX = pos.x + offset.x;
	float nowY = pos.y + offset.y;

	float fLeft = nowX - width / 2;
	float fTop = nowY - height / 2;
	float fRight = nowX + width / 2;
	float fBottom = nowY + height / 2;

	LineCollider lineTop(D3DXVECTOR2(fLeft, fTop), D3DXVECTOR2(fRight, fTop));
	LineCollider lineLeft(D3DXVECTOR2(fLeft, fTop), D3DXVECTOR2(fLeft, fBottom));
	LineCollider lineRight(D3DXVECTOR2(fRight, fTop), D3DXVECTOR2(fRight, fBottom));
	LineCollider* lineBottom = new LineCollider(D3DXVECTOR2(fLeft, fBottom), D3DXVECTOR2(fRight, fBottom));

	return lineTop.CheckCollision(col) || lineLeft.CheckCollision(col) ||
		lineRight.CheckCollision(col) || lineBottom->CheckCollision(col);
		
	return ((fLeft <= col.posA.x && col.posA.x <= fRight && 
		fTop <= col.posA.y && col.posA.y <= fBottom) && 
		(fLeft <= col.posB.x && col.posB.x <= fRight && 
			fTop <= col.posB.y && col.posB.y <= fBottom));

	return false;
}

bool LineCollider::CheckCollision(const CircleCollider & col) const
{
	return col.CheckCollision(*this);
}

bool LineCollider::CheckCollision(const RectCollider & col) const
{
	return col.CheckCollision(*this);
}

bool LineCollider::CheckCollision(const LineCollider & col) const
{
	POINT a = { posA.x, posA.y };
	POINT b = { posB.x, posB.y };
	POINT c = { col.posA.x, col.posA.y };
	POINT d = { col.posB.x, col.posB.y };

	float u = ((d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x)) / ((b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y));
	float v = ((b.x - a.x) * (a.y - c.y) - (b.y - a.y) * (a.x - c.x)) / ((b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y));

	if (u == 0 || v == 0)
		return false;

	if ((0 < u && u < 1) && (0 < v && v < 1))
		return true;

	if (1 < u && 1 < v)
		return false;

	return false;
}

bool Collider::CheckCollision(const CircleCollider & col) const
{
	return false;
}

bool Collider::CheckCollision(const RectCollider & col) const
{
	return false;
}

bool Collider::CheckCollision(const LineCollider & col) const
{
	return false;
}

bool Collider::CheckCollision(const Collider& col) const
{
	for (auto& thisCol : colliderList)
	{
		for (auto& otherCol : col.colliderList)
			if (thisCol->CheckCollision(*otherCol)) return true;
	}	
	return false;
}