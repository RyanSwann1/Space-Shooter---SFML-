#ifndef STATE_GAME_H
#define STATE_GAME_H

#include "Player.h"
#include "StateBase.h"
#include "Spawner.h"
#include <vector>

class StateGame :
	public StateBase
{
public:
	StateGame(StateManager* stateManager);
	~StateGame();

	void onCreate() override;

	void onEnter() override;

	void update(const float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	
private:
	void nextLevel();
	float m_timeElasped;
	std::vector<Spawner*> m_spawners; //Contains everything that will spawn in game
};
#endif // !STATE_GAME_H
