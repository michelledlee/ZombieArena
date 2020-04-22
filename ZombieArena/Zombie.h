#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Zombie
{
private:
	// Zombie speeds
	const float BLOATER_SPEED = 40;
	const float CHASER_SPEED = 80;
	const float CRAWLER_SPEED = 20;

	// Health of zombies
	const float BLOATER_HEALTH = 5;
	const float CHASER_HEALTH = 1;
	const float CRAWLER_HEALTH = 3;

	// Speed variance
	const int MAX_VARRIANCE = 30;
	const int OFFSET = 101 - MAX_VARRIANCE;

	Vector2f m_Position; // Zombie position	
	Sprite m_Sprite; // Zombie sprite

	float m_Speed; // Current speed
	float m_Health; // Current health
	bool m_Alive;

public:

	// Handle when a bullet hits a zombie
	bool hit();

	// Returns whether this zombie is alive
	bool isAlive();

	// Spawn new zombie
	void spawn(float startX, float startY, int type, int seed);

	// Return a rectangle that is the position in the world
	FloatRect getPosition();

	// Get a copy of the sprite to draw
	Sprite getSprite();

	// Update zombie each frame
	void update(float elapsedTime, Vector2f playerLocation);
};


