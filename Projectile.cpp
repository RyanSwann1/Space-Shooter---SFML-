#include "Projectile.h"



Projectile::Projectile(EntityManager* entityManager)
	: Entity(entityManager)
{
	m_name = "Projectile";
	m_name = "Player_Laser";
	Entity::applyTexture();
}


Projectile::~Projectile()
{
}

void Projectile::move(const Direction dir)
{
	switch (dir)
	{
	case (Direction::Up) :
	{
		Entity::move(0, -m_speed.y);
		break;
	}
	case (Direction::Down) :
	{
		Entity::move(0, m_speed.y);
		break;
	}
	}
}
