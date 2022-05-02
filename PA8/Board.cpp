/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : Board functions
* ******************************************************************************************/
#include "Board.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Board::Board()
* Last Updated : July 25th, 2021
* Description : Default constructor
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
Board::Board()
{
	// Total instances (100 total)
	int i = 0;

	// Set the width and height of the board
	for (int l = 0; l < 10; l++)
	{
		for (int h = 0; h < 10; h++)
		{
			Tile* newTile = new Tile();

			// Scalling
			sf::Sprite sprite = (*newTile).getSprite();
			sprite.setScale(1.0f, 1.0f);
			newTile->setSprite(sprite);

			// Setting Pos
			float width = sprite.getGlobalBounds().width;
			float height = sprite.getGlobalBounds().height;
			newTile->setPos(width / 2 + width * l, height / 2 + height * h);
			newTile->setX(l + 1);
			newTile->setY(h + 1);

			// Setting new tile
			tile[i] = *newTile;
			i++;
		}
	}
	// base pos of board
	xPos = 0;
	yPos = 0;

	createShips();
	stage = Stage::PLACE_PIECE;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Board::Board(int x, int y, float xScale, float yScale)
* Last Updated : July 25th, 2021
* Description : Constructor that sets the position and scale of the board
* inputs: X and Y position, and the x and y scale
* outputs: Nothing
*******************************************************************************************/
Board::Board(int x, int y, float xScale, float yScale)
{
	// Total instances (100 total)
	int i = 0;

	// Creating a template of a tile and set its scale
	Tile* newTile = new Tile();
	sf::Sprite sprite = (*newTile).getSprite();
	sprite.setScale(xScale, yScale);
	newTile->setSprite(sprite);

	// Setting Width
	float width = sprite.getGlobalBounds().width;
	float height = sprite.getGlobalBounds().height;
	boardSize = width;

	// Set the width and height of the board
	for (int l = 0; l < 10; l++)
	{
		for (int h = 0; h < 10; h++)
		{
			// Set the pos
			newTile->setPos(x + width / 2 + width * l, y + height / 2 + height * h);
			newTile->setX(l + 1);
			newTile->setY(h + 1);

			// Setting new tile
			tile[i] = *newTile;
			i++;
		}
	}

	// Board Pos
	xPos = x;
	yPos = y;

	createShips();
	stage = Stage::PLACE_PIECE;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Board::drawBoard(sf::RenderWindow* window)
* Last Updated : July 25th, 2021
* Description : Draws a board
* inputs: The render window
* outputs: Nothing
*******************************************************************************************/
void Board::drawBoard(sf::RenderWindow* window)
{
	// Displayed values
	char x = 'A';
	int y = 1;

	// Init font
	sf::Font MyFont;
	MyFont.loadFromFile("arial.ttf");

	// init string
	sf::Text xText(string(1, x), MyFont, boardSize);
	sf::Text yText(std::to_string(y), MyFont, boardSize);

	// Set Rect
	sf::FloatRect textRectX = xText.getLocalBounds();
	sf::FloatRect textRectY = yText.getLocalBounds();


	// Print Characters to the screen
	for (int i = 0; i < 10; i++)
	{
		// Set String
		xText.setString(string(1, x));
		yText.setString(std::to_string(y));

		// Set Rect
		textRectX = xText.getLocalBounds();
		textRectY = yText.getLocalBounds();

		// set origin
		xText.setOrigin(textRectX.width / 2, textRectX.height / 2);
		yText.setOrigin(textRectY.width / 2, textRectY.height / 2);

		// set pos
		xText.setPosition(xPos + boardSize / 2 + boardSize * i, yPos - boardSize * 1.5);
		yText.setPosition(xPos - boardSize * 1.5, yPos + boardSize / 3 + boardSize * i);

		// draw text
		(*window).draw(xText);
		(*window).draw(yText);

		// increment variables
		x++;
		y++;
	}

	// Draws the tile into the window
	for (int i = 0; i < 100; i++)
	{
		window->draw(tile[i].getSprite());
	}

	// Prints every ship
	for (int i = 0; i < 5; i++)
	{
		window->draw(ship[i].getShip()->getSprite());
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Board::createShips()
* Last Updated : July 25th, 2021
* Description : Creates every ship needed for the board
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
void Board::createShips()
{
	int x = 50;
	int y = 300;
	Direction direction = Direction::VERTICAL;
	Ship* s = nullptr;

	// Creates each ship
	for (int i = 0; i < 5; i++)
	{
		// Creates a ship
		switch (i)
		{
			case 0: // two tile ship
				s = new Ship(2, direction, x, y, 1.5f, 1.5f);
				break;
			case 1: // 3 tile ship
				s = new Ship(3, direction, x, y, 1.5f, 1.5f);
				break;
			case 2: // 3 tile ship
				s = new Ship(3, direction, x, y, 1.5f, 1.5f);
				break;
			case 3: // 4 tile ship
				s = new Ship(4, direction, x, y, 1.5f, 1.5f);
				break;
			case 4: // 5 tile ship
				s = new Ship(5, direction, x, y, 1.5f, 1.5f);
				break;
		}
		ship[i] = *s;
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Tile* Board::getTile()
* Last Updated : July 25th, 2021
* Description : Getter for the tile
* inputs: Nothing
* outputs: Tile
*******************************************************************************************/
Tile* Board::getTile()
{
	return tile;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Stage Board::getStage()
* Last Updated : July 25th, 2021
* Description : Geter for the stage
* inputs: Nothing
* outputs: Stage
*******************************************************************************************/
Stage Board::getStage()
{
	return stage;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: float Board::getBoardSize()
* Last Updated : July 25th, 2021
* Description : Geter for the boardSize
* inputs: Nothing
* outputs: boardSize
*******************************************************************************************/
float Board::getBoardSize()
{
	return boardSize;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Ship* Board::getShip()
* Last Updated : July 25th, 2021
* Description : Geter for the ship
* inputs: Nothing
* outputs: Object ship
*******************************************************************************************/
Ship* Board::getShip()
{
	return ship;
}

void Board::setStage(Stage s)
{
	stage = s;
}