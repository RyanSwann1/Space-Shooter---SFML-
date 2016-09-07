#include "EventSystem.h"
#include "SharedContext.h"
#include "StateManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

EventSystem::EventSystem(SharedContext* sharedContext)
	: m_sharedContext(sharedContext), 
	m_hasFocus(true)
{
	loadBindings();
}

EventSystem::~EventSystem()
{

}

void EventSystem::update(sf::Event sfmlEvent)
{
	//sf::Event m_event;
	//Screen is minimized
	if (!m_hasFocus) {
		return;
	}

	//Search through all bindings
	for (auto &bindIter : m_bindings)
	{
		Binding bind = bindIter.second;

		//Search through all events within bindings
		for (auto &eventIter : bind.m_events)
		{
			EventType eventCurrent = (EventType)sfmlEvent.type;
			////Match given event
			switch (eventCurrent)
			{
			case (EventType::KeyPressed) :
			{
				if (eventCurrent == eventIter.first && sfmlEvent.key.code == eventIter.second.m_code)
				{
					activateEvent(bind, m_sharedContext->m_stateManager->getStateCurrent());
				}
				break;
			}
			case (EventType::Closed):
			{
				if (eventCurrent == eventIter.first)
				{
					activateEvent(bind, StateType(0));
				}
				break;
			}
			}
		}
	}
}

inline void EventSystem::addBinding(const Binding& binding)
{
	if (m_bindings.find(binding.m_bindName) == m_bindings.cend())
	{
		m_bindings.emplace(binding.m_bindName, binding);
	}
}

void EventSystem::activateEvent(Binding & bind, const StateType type)
{
	auto iter = m_callbacks.find(type);
	if (iter != m_callbacks.end())
	{
		auto bindIter = iter->second.find(bind.m_bindName);
		if (bindIter != iter->second.cend())
		{
			bindIter->second(&bind.m_eventDetails); 
		}
	}
}

void EventSystem::readIn()
{
	std::ifstream file;
	file.open("Keys.txt");
	if (!file.is_open())
	{
		std::cerr << "Couldn't open 'Keys.txt" << "\n";

	}
	std::string name;

	
}

void EventSystem::loadBindings()
{
	// -- Temporary --
	//Move Left
	Binding bindMoveLeft("Move_Left");
	EventInfo moveLeftInfo(sf::Keyboard::A);
	bindMoveLeft.bindEvent(EventType::KeyPressed, moveLeftInfo);
	addBinding(bindMoveLeft);

	//Move Right
	Binding bindMoveRight("Move_Right");
	EventInfo moveRightInfo(sf::Keyboard::D);
	bindMoveRight.bindEvent(EventType::KeyPressed, moveRightInfo);
	addBinding(bindMoveRight);

	//Move Up
	Binding bindMoveUp("Move_Up");
	EventInfo moveUpInfo(sf::Keyboard::W);
	bindMoveUp.bindEvent(EventType::KeyPressed, moveUpInfo);
	addBinding(bindMoveUp);

	//Move Down
	Binding bindMoveDown("Move_Down");
	EventInfo moveDownInfo(sf::Keyboard::S);
	bindMoveDown.bindEvent(EventType::KeyPressed, moveDownInfo);
	addBinding(bindMoveDown);

	//Fire Laser
	Binding bindFireLaser("Fire_Laser");
	EventInfo fireLaserInfo(sf::Keyboard::Space);
	bindFireLaser.bindEvent(EventType::KeyPressed, fireLaserInfo);
	addBinding(bindFireLaser);

	Binding bindWindowClose("Window_Close");
	EventInfo windowCloseInfo;
	bindWindowClose.bindEvent(EventType::Closed, windowCloseInfo);
	addBinding(bindWindowClose);
}

void EventSystem::removeCallback(const StateType type, const std::string & name)
{
	auto callbackIter = m_callbacks.find(type);
	if (callbackIter != m_callbacks.cend())
	{
		auto callBackContainerIter = callbackIter->second.find(name);
		if (callBackContainerIter != callbackIter->second.cend())
		{
			m_callbacks.erase(callbackIter);
		}
	}
}
