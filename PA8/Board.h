#pragma once
#include "Tile.h"
#include "Object.h"
#include "Ship.h"
#include <SFML/Graphics.hpp>

// The stage of the game used to check if the player is placing pieces or trying to find a target
enum class Stage
{
	PLACE_PIECE, SELECT_TARGET, GAME_OVER
};

// Used as a players individual board in battleship
class Board
{
	public:
		// constructors
		Board();
		Board(int x, int y, float xScale, float yScale);

		// Game functions
		void drawBoard(sf::RenderWindow* window);

		// Getters
		Tile* getTile();
		Stage getStage();
		float getBoardSize();
		Ship* getShip();

		// setters 
		void setStage(Stage s);

	protected:
		// Tiles and ships
		Tile* tile = new Tile[100];
		Ship* ship = new Ship[5];

		// Tile Pos
		int xPos;
		int yPos;

		// Tile Size
		float boardSize;
	
		// Current stage in the game
		Stage stage;

	private:
		// private functions
		void createShips();
};