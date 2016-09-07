#ifndef ENEMY_H
#define ENEMY_H


#include "Character.h"
class Enemy :
	public Character
{
public:
	Enemy(EntityManager* entityManager);
	~Enemy();

	void onEntityCollision(Entity* collision) override;
	void update(const float deltaTime) override;

private:

	void fireProjectile();
	sf::Vector2f getFirePos() const;
};
#endif // !ENEMY_H
