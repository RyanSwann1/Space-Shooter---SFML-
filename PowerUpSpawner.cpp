#include "PowerUpSpawner.h"
#include "PowerUpHealth.h"
#include "Utilities.h"


PowerUpSpawner::PowerUpSpawner(EntityManager* entityManager)
	:Spawner(entityManager)
{
	m_timeBetweenSpawn = 4;
	m_nextSpawnTime = 2;
	m_minSpawnPos = 25;
	m_maxSpawnPos = 650;
}

PowerUpSpawner::~PowerUpSpawner()
{
}

void PowerUpSpawner::update(const float timeElasped)
{
	if (timeElasped >= m_nextSpawnTime)
	{
		spawn();
		m_nextSpawnTime += m_timeBetweenSpawn;
	}
}

void PowerUpSpawner::spawn()
{
	Entity* powerUp = new PowerUpHealth(m_entityManager);
	powerUp->setStartPos(sf::Vector2f(Utilities::getRandomNumber(m_minSpawnPos, m_maxSpawnPos), 680));
	m_entityManager->addEntity(EntityType::PowerUp, powerUp);
}
