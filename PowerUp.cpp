#include "PowerUp.h"

PowerUp::PowerUp(EntityManager * entityManager)
	:Entity(entityManager)
{
}

PowerUp::~PowerUp()
{
}

void PowerUp::move(const Direction dir)
{
	switch (dir)
	{
	case Direction::Up :
	{
		Entity::move(0, -m_speed.y);
		break;
	}

	case Direction::Down :
	{
		Entity::move(0, m_speed.y);
		break;
	}
	}
}
