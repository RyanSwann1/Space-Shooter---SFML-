#ifndef POWER_UP_H
#define POWER_UP_H


#include "Entity.h"
class PowerUp :
	public Entity
{
public:
	PowerUp(EntityManager* entityManager);
	virtual ~PowerUp();

	virtual void onEntityCollision(Entity* collider) = 0;
	virtual void update(const float deltaTime) {}

	void move(const Direction dir);
protected:
	unsigned int m_powerUpValue;
};
#endif // !POWER_UP_H
