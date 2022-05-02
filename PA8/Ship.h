#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

enum class Direction
{
	HORIZONTAL, VERTICAL
};

// Ship is the visual ship seen on the screen and the information about it
class Ship
{
	public:
		// Constructor
		Ship();
		Ship(int setSize, Direction dir);
		Ship(int setSize, Direction dir, int xPos, int yPos, float xSize, float ySize);
		Ship(Ship* copy);

		// setter
		void setDirection(Direction dir);

		// getter
		Object *getShip();
		int getSize();
		Direction getDirection();

	private:
		int size;
		Object *ship = new Object();
		Direction direction;
};