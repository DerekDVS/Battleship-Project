#pragma once
#include "Board.h"
#include "SetBoard.h"

class PlayBoard : public Board
{
	public:
		// Constructor
		PlayBoard() : Board() {};
		PlayBoard(SetBoard *newBoard);
	
		// Unique Functions
		bool hitTarget(int tileNum);
		void highlightTiles(sf::Vector2f worldPos);
		void drawBoard(sf::RenderWindow* window);
		bool checkWinner();
	private:
};