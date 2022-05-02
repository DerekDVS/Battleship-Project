#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

// The status of the tile if it is empty occupied missed or hit
enum class Status
{
	EMPTY, OCCUPIED, MISSED, HIT, HIGHLIGHTED
};

// The individual tiles on a gameboard the tiles are an object
class Tile : public Object
{
	public:
		// Constructors
		Tile();
		Tile(int xPos, int yPos, float xSize, float ySize);
		Tile(Tile& copy);

		// Setters
		void setState(Status newState);
		void setX(int newX);
		void setY(int newY);

		// Getters
		Status getState();
		int getX();
		int getY();

	private:
		Status state;
		int x;
		int y;
};