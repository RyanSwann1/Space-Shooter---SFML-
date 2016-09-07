#include "StateManager.h"
#include "StateMainMenu.h"
#include "StateGame.h"
#include <iostream>

StateManager::StateManager(SharedContext* sharedContext)
	: m_sharedContext(sharedContext)
{
	registerState<StateMainMenu>(StateType::MainMenu);
	registerState<StateGame>(StateType::Game);
}

StateManager::~StateManager()
{
}

void StateManager::switchTo(const StateType state)
{
	
	/*std::size_t size = 1;
	if (m_states.size() > size) 
	{
		for (auto cIter = m_states.begin(); cIter != m_states.end(); cIter++)
		{
			if (cIter->first == state)
			{
				StateType tempStateType = cIter->first;
				StateBase* tempStateBase = cIter->second;
				m_states.back().second->onExit();
				m_states.emplace_back(tempStateType, tempStateBase); //Iterators are invalidated upon changing the capacity of the vector
				m_states.back().second->onEnter();
				m_states.erase(cIter);
				m_stateCurrent = m_states.back().first;
				return;
			}
		}
	}*/
	
	createState(state);
	std::cout << "\n" << "Size of states: " << m_states.size() << "\n";
}

void StateManager::createState(const StateType state)
{
	auto iter = m_stateFactory.find(state);
	if (iter != m_stateFactory.cend())
	{
		m_states.emplace_back(iter->first, iter->second());
		m_states.back().second->onCreate();
		m_states.back().second->onEnter();
		m_stateCurrent = m_states.back().first;
	}
}

void StateManager::removeState(const StateType state)
{
	for (auto iter = m_states.begin(); iter != m_states.end(); iter++)
	{
		if (iter->first == state)
		{
			delete iter->second;
			m_states.erase(iter);
			return;
		}
	}
}

void StateManager::processRequests()
{
	while (m_statesToRemove.begin() != m_statesToRemove.end())
	{
		std::cout << "Remove." << "\n";
		removeState(m_statesToRemove.back());
		m_statesToRemove.pop_back();
	}
}

void StateManager::update(const float deltaTime)
{
	for (auto &i : m_states)
	{
		i.second->update(deltaTime);
	}
}

void StateManager::draw(sf::RenderWindow & window)
{
	for (auto &i : m_states)
	{
		i.second->draw(window);
	}
}
