#include "Character.h"
#include "EntityManager.h"
#include <iostream>


Character::Character(EntityManager* entityManager)
	:Entity(entityManager)
{
}

Character::~Character()
{
}

void Character::move(const Direction dir)
{
	switch (dir)
	{
	case (Direction::Left) : 
	{
		Entity::move(-m_speed.x, 0);
		break;
	}
	case (Direction::Right) : 
	{
		Entity::move(m_speed.x, 0);
		break;
	}
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

void Character::reduceLivesAmount(const unsigned int i)
{
	std::cout << "\n\n" << m_lives << "\n\n";
	//Do not let 'm_lives' be under 0
	if ((m_lives -= i) <= 0) 
	{
		m_entityManager->removeEntity(m_ID);
	}
	else {
		m_lives -= i;
	}
	std::cout << "\n\n" << m_lives << "\n\n";
}

void Character::addLivesAmount(const unsigned int i)
{
	//Do not let 'm_lives' exceed m_maxLives
	if ((m_lives += i) > m_maxLives) {
		m_lives = m_maxLives;
	}
	else {
		m_lives = m_maxLives;
	}
}
