#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet {
private:
	// Bullet position in game world
	Vector2f m_Position;

	// Non-texture graphic for bullet
	RectangleShape m_BulletShape;

	// Is the bullet in flight - impacts movement or collision
	bool m_InFlight = false;

	// Bullet speed in pixels per second
	float m_BulletSpeed = 1000;

	// Horizontal and vertical change for each frame
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	// Bullet target
	float m_XTarget;
	float m_YTarget;

	// Max and min horizontal and vertical positions for the bullet
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;

public:
	// Constructor
	Bullet();

	// Called to stop bullet
	void stop();

	// Bullet in flight or not
	bool isInFlight();

	// Shoot a new bullet
	void shoot(float startX, float startY, float xTarget, float yTarget);

	// Get location of bullet for collision detection with zombies
	FloatRect getPosition();

	// Gets a copy of the current state of the bullet rectangle
	RectangleShape getShape();

	// Update the bullet position each frame
	void update(float elapsedTime);

};