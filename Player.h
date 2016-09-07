#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
struct EventDetails;
class Player :
	public Character
{
public:
	Player(EntityManager* entityManager);
	~Player();

	void onEntityCollision(Entity* collider) override;
	void update(const float deltaTime) override;
private:



	void reactToInput(EventDetails* eventDetails);
	void fireLaser();
	sf::Vector2f getFirePos() const;
};
#endif // !PLAYER_H
