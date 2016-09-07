#ifndef CHARACTER_H
#define CHARACTER_H


#include "Entity.h"
class Character :
	public Entity
{
public:
	Character(EntityManager* entityManager);
	virtual ~Character();

	void move(const Direction dir);
	void reduceLivesAmount(const unsigned int i);
	void addLivesAmount(const unsigned int i);

	virtual void update(const float deltaTime) {}

protected:
	virtual void onEntityCollision(Entity* collider) = 0;
	unsigned int m_lives;
	unsigned int m_maxLives; 
	float m_timeElasped;
	float m_nextFireTime;
	float m_timeBetweenFire;

};
#endif // !CHARACTER_H
