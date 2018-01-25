#pragma once


class ObjectManager : public Singleton<ObjectManager>
{
public:


	ObjectManager();
	virtual ~ObjectManager();
};

#define OBJECTMANAGER ObjectManager::GetSingleton()


class CircleCollider;
class RectCollider;
class LineCollider;


class CircleCollider
{
public:
	D3DXVECTOR2& pos;
	D3DXVECTOR2 offset;
	float radius;

	bool CheckCollision(const CircleCollider& col) const;
	bool CheckCollision(const RectCollider& col) const;
	bool CheckCollision(const LineCollider& col) const;

	CircleCollider(D3DXVECTOR2& p, D3DXVECTOR2 off, float r)
	: pos(p), offset(off), radius(r) {}
	~CircleCollider() {}
};


class RectCollider
{
public:
	D3DXVECTOR2& pos;
	D3DXVECTOR2 offset;
	float width, height;

	bool CheckCollision(const CircleCollider& col) const;
	bool CheckCollision(const RectCollider& col) const;
	bool CheckCollision(const LineCollider& col) const;

	RectCollider(D3DXVECTOR2& p, D3DXVECTOR2 off, float w, float h)
		: pos(p), offset(off), width(w), height(h) {}
	~RectCollider() {}
};


class LineCollider
{
public:
	D3DXVECTOR2& posA;
	D3DXVECTOR2& posB;

	bool CheckCollision(const CircleCollider& col) const;
	bool CheckCollision(const RectCollider& col) const;
	bool CheckCollision(const LineCollider& col) const;

	LineCollider(D3DXVECTOR2& pA, D3DXVECTOR2& pB)
		: posA(pA), posB(pB) {}
	~LineCollider() {}
};


class Collider
{
public:
	vector<CircleCollider> circleList;
	vector<RectCollider> rectList;
	vector<LineCollider> lineList;

	Collider() {}
	~Collider() {}
};