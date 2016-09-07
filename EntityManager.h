#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "Entity.h"
#include "SharedContext.h"
#include <unordered_map>
#include <vector>
#include <functional>
#include <string>

class EntityManager
{
public:
	EntityManager(SharedContext* sharedContext);
	~EntityManager();

	std::vector<std::pair<Entity*, unsigned int>>& getEntities() { return m_entities; }

	void addEntity(const EntityType type);
	void addEntity(const EntityType type, Entity* entity);
	void removeEntity(const unsigned int id) { m_entitiesToRemove.push_back(id); }
	void processRemovals();

	void update(const float deltaTime);
	void draw(sf::RenderWindow& window);
	SharedContext* getSharedContext() { return m_sharedContext; }
	sf::Vector2u gameBoundary() const { return m_gameBoundary; }

	template<class T>
	void registerEntity(const EntityType type)
	{
		if (m_entityFactory.find(type) == m_entityFactory.cend())
		{
			m_entityFactory[type] = [this]()->Entity*
			{
				return new T(this);
			};
		}
		else 
		{
			std::cerr << "Type not registered." << "\n";
		}
	}

private:
	std::unordered_map<EntityType, std::function<Entity*()>> m_entityFactory;
	std::vector<std::pair<Entity*, unsigned int>> m_entities; //Entities with a unique identifier
	std::vector<unsigned int> m_entitiesToRemove;
	unsigned int m_entityCount;
	SharedContext* m_sharedContext;
	sf::Vector2u m_gameBoundary; //Entities must stay inline within this boundary

	bool removeActiveEntity(unsigned int id);
	void destroyFactory();
	void destroyEntities();
	void checkCollisions();
};
#endif // !ENTITY_MANAGER_H
