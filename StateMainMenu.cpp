#include "StateMainMenu.h"
#include "StateManager.h"
#include <iostream>

StateMainMenu::StateMainMenu(StateManager* stateManager)
	: StateBase(stateManager)
{
	std::cout << "Hello World." << "\n";
	//m_stateManager->getSharedContext()->m_eventSystem->addCallback<StateMainMenu>(StateType::MainMenu, "Next_Level", &StateMainMenu::startGame, this);
}


StateMainMenu::~StateMainMenu()
{
	m_stateManager->getSharedContext()->m_eventSystem->removeCallback(StateType::MainMenu, "Start_Game");
}

void StateMainMenu::onEnter()
{
	std::cout << "Entered Main Menu." << "\n";
}

void StateMainMenu::onExit()
{
}

void StateMainMenu::onCreate()
{
	std::cout << "Created Main Menu." << "\n";
}

void StateMainMenu::onDestroy()
{
}

void StateMainMenu::update(const float deltaTime)
{
}

void StateMainMenu::draw(sf::RenderWindow& window)
{
}

void StateMainMenu::startGame()
{
	m_stateManager->switchTo(StateType::Game);
	m_stateManager->remove(StateType::MainMenu);
	std::cout << "State Size:" << m_stateManager->getStateSize() << "\n";
}
