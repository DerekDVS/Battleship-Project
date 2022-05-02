#pragma once
#include "Board.h"

class SetBoard : public Board
{
	public:
		// constructor
		SetBoard();
		SetBoard(int x, int y, float xScale, float yScale);
		
		// public functions
		bool placeShips(int tileNum);
		void highlightTiles(sf::Vector2f worldPos);
		void flipCurrentShip();
		void drawBoard(sf::RenderWindow* window);

	private:
		int placedShips;
};