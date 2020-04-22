#include "bullet.h"


// Constructor sets the bullet size
Bullet::Bullet() {
	m_BulletShape.setSize(sf::Vector2f(2, 2));
}

// Receives starting position of bullet and target position 
void Bullet::shoot(float startX, float startY, float targetX, float targetY) {
	// Keep track of the bullet
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;

	// Calculate the gradient of the flight path (equation of a line)
	float gradient = (startX - targetX) / (startY - targetY);

	// Any gradient less than zero needs to be negative
	if (gradient < 0) {
		gradient *= -1;
	}

	// Calculate the ratio of vertical to horizontal distance
	// Allows us to change the position correctly for each frame
	// based on the target the bullet is heading towards
	float ratioXY = m_BulletSpeed / (1 + gradient);

	// Set the "speed" horizontally and vertically
	m_BulletDistanceY = ratioXY;
	m_BulletDistanceX = ratioXY * gradient;

	// Point the bullet in the right direction
	if (targetX < startX) {
		m_BulletDistanceX *= -1;
	}

	if (targetY < startY) {
		m_BulletDistanceY *= -1;
	}

	// Set a max range of 1000 pixels
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;

	// Position the bullet ready to be drawn
	m_BulletShape.setPosition(m_Position);
}

void Bullet::stop() {
	m_InFlight = false;
}

bool Bullet::isInFlight() {
	return m_InFlight;
}

// Will be used to detect collisions
FloatRect Bullet::getPosition() {
	return m_BulletShape.getGlobalBounds();
}

RectangleShape Bullet::getShape() {
	return m_BulletShape;
}


void Bullet::update(float elapsedTime) {
	// Used to move bullet at the right angle
	m_Position.x += m_BulletDistanceX * elapsedTime;
	m_Position.y += m_BulletDistanceY * elapsedTime;

	// Move the rectangle shape
	m_BulletShape.setPosition(m_Position);

	// Check if the bullet has gone out of range based on min and max values
	if (m_Position.x < m_MinX || m_Position.x > m_MaxX ||
		m_Position.y < m_MinY || m_Position.y > m_MaxY) {
		m_InFlight = false;
	}

}