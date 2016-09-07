#include "PowerUpHealth.h"
#include "EntityManager.h"
#include "Character.h"

PowerUpHealth::PowerUpHealth(EntityManager* entityManager)
	:PowerUp(entityManager)
{
	m_name = "Power_Up_Health";
	m_entityType = EntityType::HealthPowerup;
	m_direction = Direction::Up;
	m_speed = sf::Vector2f(0, 0.010f);
	m_size = sf::Vector2f(1, 1);
	Entity::applyTexture();
}

PowerUpHealth::~PowerUpHealth()
{
}

void PowerUpHealth::onEntityCollision(Entity * collider)
{
	if (collider->getType() == EntityType::Player || collider->getType() == EntityType::Enemy ||
		collider->getType() == EntityType::PlayerProjectile || collider->getType() == EntityType::EnemyProjectile)
	{
		if (collider->getType() == EntityType::Player)
		{
			Character* character = (Character*)collider;
			character->addLivesAmount(m_powerUpValue);
		}

		m_entityManager->removeEntity(m_ID);
	}
}

void PowerUpHealth::update(const float deltaTime)
{
	move(m_direction);

	sf::Vector2u mapBoundary = m_entityManager->getSharedContext()->m_window->getSize();
	if (m_position.y <= 0)
	{
		m_entityManager->removeEntity(m_ID);
	}
	Entity::update(deltaTime);
}
