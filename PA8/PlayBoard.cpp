/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : Playing the board functions
* ******************************************************************************************/
#include "PlayBoard.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: PlayBoard::PlayBoard(SetBoard* newBoard)
* Last Updated : July 25th, 2021
* Description : Play board constructor
* inputs: The board to play on
* outputs: Nothing
*******************************************************************************************/
PlayBoard::PlayBoard(SetBoard* newBoard)
{
	ship = newBoard->getShip();
	tile = newBoard->getTile();

	stage = Stage::SELECT_TARGET;
	boardSize = newBoard->getBoardSize();
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: bool PlayBoard::hitTarget(int tileNum)
* Last Updated : July 25th, 2021
* Description : Hits a target on the board and hits it if it is occupied and misses otherwise
* inputs: The tile to hit
* outputs: If a hit is succesful
*******************************************************************************************/
bool PlayBoard::hitTarget(int tileNum)
{
	bool success = false;
	switch (tile[tileNum].getState())
	{
		case Status::EMPTY:
			tile[tileNum].setState(Status::MISSED);
			success = true;
			break;
		case Status::OCCUPIED:
			tile[tileNum].setState(Status::HIT);
			success = true;
			break;
	}
	return success;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void PlayBoard::highlightTiles(sf::Vector2f worldPos)
* Last Updated : July 25th, 2021
* Description : Highlights the tile the mouse is on and other tiles
* inputs: The position on the map
* outputs: Nothing
*******************************************************************************************/
void PlayBoard::highlightTiles(sf::Vector2f worldPos)
{
	int i = 0;
	// checks tiles
	while (i < 100)
	{
		// Checks the stage
		switch (getTile()[i].getState())
		{
			case Status::HIT:
				tile[i].setColor(sf::Color(0, 50, 0));
				break;
			case Status::MISSED:
				tile[i].setColor(sf::Color(0, 255, 0));
				break;
			// Highlights a target
			case Status::EMPTY:
			case Status::OCCUPIED:
				if (getTile()[i].checkMousePos(worldPos))
				{
					tile[i].setColor(sf::Color(255, 0, 0));
				}
				else
				{
					tile[i].setColor(sf::Color::White);
				}
				break;
			}
			i++;
	}
}


/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void PlayBoard::drawBoard(sf::RenderWindow* window)
* Last Updated : July 25th, 2021
* Description : Draws a players board
* inputs: The window to draw
* outputs: Nothing
*******************************************************************************************/
void PlayBoard::drawBoard(sf::RenderWindow* window)
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

	// Draws ship if the game is over
	if (getStage() == Stage::GAME_OVER)
	{
		for (int i = 0; i < 5; i++)
		{
			window->draw(ship[i].getShip()->getSprite());
		}
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: bool PlayBoard::checkWinner()
* Last Updated : July 25th, 2021
* Description : Checks to see if there is a winner in the game
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
bool PlayBoard::checkWinner()
{
	bool winner = true;

	// checks every tile
	for (int i = 0; i < 100 && winner == true; i++)
	{
		if (tile[i].getState() == Status::OCCUPIED)
		{
			winner = false;
		}

	}
	return winner;
}