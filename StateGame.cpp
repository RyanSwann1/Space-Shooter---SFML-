#include "StateGame.h"
#include "StateManager.h"
#include "EntityManager.h"
#include "EnemySpawner.h"
#include "PowerUpSpawner.h"
#include <iostream>
#include <assert.h>

StateGame::StateGame(StateManager* stateManager)
	: StateBase(stateManager),
	m_timeElasped(0)
{
	EntityManager* entityManager = m_stateManager->getSharedContext()->m_entityManager;
	entityManager->addEntity(EntityType::Player);
	m_spawners.emplace_back(new EnemySpawner(entityManager));
	m_spawners.emplace_back(new PowerUpSpawner(entityManager));
}


StateGame::~StateGame()
{
	for (auto &i : m_spawners)
	{
		delete i;
		i = nullptr;
	}
	m_spawners.clear();
}

void StateGame::onCreate()
{
	std::cout << "StateGame Created." << "\n";
}

void StateGame::onEnter()
{
	std::cout << "StateGame ENtered." << "\n";
}

void StateGame::update(const float deltaTime)
{
	m_timeElasped += deltaTime;
	for (auto &i : m_spawners)
	{
		i->update(m_timeElasped);
	}
	m_stateManager->getSharedContext()->m_entityManager->update(deltaTime);
}

void StateGame::draw(sf::RenderWindow & window)
{
	m_stateManager->getSharedContext()->m_entityManager->draw(window);
}

void StateGame::nextLevel()
{
	m_stateManager->switchTo(StateType::MainMenu);
	m_stateManager->remove(StateType::Game);
	std::cout << "State Size:" << m_stateManager->getStateSize() << "\n";
}

