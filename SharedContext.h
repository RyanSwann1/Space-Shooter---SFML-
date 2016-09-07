#ifndef SHARED_CONTEXT_H
#define SHARED_CONTEXT_H

#include "Window.h"
#include "EventSystem.h"
#include "TextureManager.h"
class EntityManager;
class StateManager;
struct SharedContext
{
	SharedContext() :
		m_stateManager(nullptr),
		m_window(nullptr),
		m_eventSystem(nullptr), 
		m_textureManager(nullptr),
		m_entityManager(nullptr) {}

	StateManager* m_stateManager;
	TextureManager* m_textureManager;
	EntityManager* m_entityManager;
	EventSystem* m_eventSystem;
	Window* m_window;
};
#endif // !SHARED_CONTEXT_H

