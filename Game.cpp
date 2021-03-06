#include "Game.h"
#include <iostream>

// i think it's good practice to always explicitly initialize everything in the constructor, in the same orders as in the header file


Game::Game()
	: m_stateManager(&m_sharedContext),
	m_window(&m_sharedContext, sf::Vector2u(480, 640), "SFML_Engine"),
	m_entityManager(&m_sharedContext)
{
	m_sharedContext.m_window = &m_window;
	m_sharedContext.m_eventSystem = m_window.getEventSystem();
	m_sharedContext.m_stateManager = &m_stateManager;
	m_sharedContext.m_entityManager = &m_entityManager;
	m_sharedContext.m_textureManager = &m_textureManager;
	//Unknown reason as to why this was null when setting this in the eventSystem class instead of here - now known
	m_stateManager.switchTo(StateType::Game);
}

Game::~Game()
{
}

void Game::update()
{
	m_window.update();
	m_stateManager.update(m_elaspedTime.asSeconds());
}

void Game::render()
{
	m_window.beginDraw();
	m_stateManager.draw(m_window.getWindow());
	m_window.endDraw();
}

void Game::lateUpdate()
{
	m_stateManager.processRequests();
	m_elaspedTime = m_clock.restart();

}
