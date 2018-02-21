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

class BaseCollider
{
public:
	virtual bool CheckCollision(const CircleCollider& col) const PURE;
	virtual bool CheckCollision(const RectCollider& col) const PURE;
	virtual bool CheckCollision(const LineCollider& col) const PURE;

	virtual bool CheckCollision(const BaseCollider& col) const PURE;

	virtual ~BaseCollider() {}
};


class CircleCollider : public BaseCollider
{
public:
	D3DXVECTOR2& pos;
	D3DXVECTOR2 offset;
	float radius;

	virtual bool CheckCollision(const CircleCollider& col) const override;
	virtual bool CheckCollision(const RectCollider& col) const override;
	virtual bool CheckCollision(const LineCollider& col) const override;

	virtual bool CheckCollision(const BaseCollider& col) const { return false; }

	CircleCollider(D3DXVECTOR2& p, D3DXVECTOR2 off, float r)
	: pos(p), offset(off), radius(r) {}
	~CircleCollider() {}
};


class RectCollider : public BaseCollider
{
public:
	D3DXVECTOR2& pos;
	D3DXVECTOR2 offset;
	float width, height;

	virtual bool CheckCollision(const CircleCollider& col) const override;
	virtual bool CheckCollision(const RectCollider& col) const override;
	virtual bool CheckCollision(const LineCollider& col) const override;

	virtual bool CheckCollision(const BaseCollider& col) const { return false; }

	RectCollider(D3DXVECTOR2& p, D3DXVECTOR2 off, float w, float h)
		: pos(p), offset(off), width(w), height(h) {}
	~RectCollider() {}
};


class LineCollider : public BaseCollider
{
public:
	D3DXVECTOR2& posA;
	D3DXVECTOR2& posB;

	virtual bool CheckCollision(const CircleCollider& col) const override;
	virtual bool CheckCollision(const RectCollider& col) const override;
	virtual bool CheckCollision(const LineCollider& col) const override;
	
	virtual bool CheckCollision(const BaseCollider& col) const { return false; }

	LineCollider(D3DXVECTOR2& pA, D3DXVECTOR2& pB)
		: posA(pA), posB(pB) {}
	~LineCollider() {}
};


class Collider
{
public:
	vector<BaseCollider*> colliderList;

	bool CheckCollision(const CircleCollider& col) const;
	bool CheckCollision(const RectCollider& col) const;
	bool CheckCollision(const LineCollider& col) const;

	bool CheckCollision(const Collider& col) const;

	Collider() {}
	~Collider() {}
};