#include "ZombieArena.h"
#include "Zombie.h"

// Creates an array of zombie objects
Zombie* createHorde(int numZombies, IntRect arena) {
	Zombie* zombies = new Zombie[numZombies]; // Result variable

	// Gets arena boundaries with adjustments for walls
	int maxY = arena.height - 20;
	int minY = arena.top + 20;
	int maxX = arena.width - 20;
	int minX = arena.left + 20;

	// Loop through each zombie
	for (int i = 0; i < numZombies; i++) {
		// Randomly generate where the zombie should spawn
		srand((int)time(0) * i);
		int side = (rand() % 4);
		float x, y; // Coordinates of zombie

		// Positioning for spawn
		switch (side) {
		case 0: // Left
			x = minX;
			y = (rand() % maxY) + minY;
			break;
		case 1: // Right
			x = maxX;
			y = (rand() % maxY) + minY;
			break;
		case 2: // Top
			x = (rand() % maxX) + minX;
			y = minY;
			break;
		case 3: // Bottom
			x = (rand() % maxX) + minX;
			y = maxY;
			break;
		}

		// Randomly generate type of zombie
		srand((int)time(0) * i * 2);
		int type = (rand() % 3);

		// Place new zombie into the array
		zombies[i].spawn(x, y, type, i);

	}
	return zombies;
}