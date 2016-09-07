#ifndef STATE_MAIN_MENU_H
#define STATE_MAIN_MENU_H


#include "StateBase.h"
class StateMainMenu :
	public StateBase
{
public:
	StateMainMenu(StateManager* stateManager);
	~StateMainMenu();

	void onEnter() override;
	void onExit() override;

	void onCreate() override;
	void onDestroy() override;

	void update(const float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

private:
	void startGame();
};
#endif // !STATE_MAIN_MENU_H
