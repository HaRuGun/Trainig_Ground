#include "stdafx.h"
#include <typeinfo>

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}


//


bool CircleCollider::CheckCollision(const CircleCollider& col)
{
	return false;
}

bool CircleCollider::CheckCollision(const RectCollider & col)
{
	return false;
}

bool CircleCollider::CheckCollision(const LineCollider & col)
{
	return false;
}

bool RectCollider::CheckCollision(const CircleCollider & col)
{
	return false;
}

bool RectCollider::CheckCollision(const RectCollider & col)
{
	return false;
}

bool RectCollider::CheckCollision(const LineCollider & col)
{
	return false;
}

bool LineCollider::CheckCollision(const CircleCollider & col)
{
	return false;
}

bool LineCollider::CheckCollision(const RectCollider & col)
{
	return false;
}

bool LineCollider::CheckCollision(const LineCollider & col)
{
	return false;
}
