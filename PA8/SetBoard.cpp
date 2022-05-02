/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : Setting the board functions
* ******************************************************************************************/
#include "SetBoard.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: SetBoard::SetBoard() : Board()
* Last Updated : July 25th, 2021
* Description : Inherits the board constructor and sets placed ships to zero
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
SetBoard::SetBoard() : Board()
{
	placedShips = 0;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: SetBoard::SetBoard() : Board()
* Last Updated : July 25th, 2021
* Description : Inherits the board constructor and sets placed ships to zero
* inputs: X and Y pos and x and y scale
* outputs: Nothing
*******************************************************************************************/
SetBoard::SetBoard(int x, int y, float xScale, float yScale) : Board(x, y, xScale, yScale)
{
	placedShips = 0;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: bool Board::placeShips(int shipNum, int tileNum)
* Last Updated : July 25th, 2021
* Description : Places a ship on the board if it is possible
* Precondition: Stage must be PLACE_PIECES
* inputs: The ship type and the tile being checked
* outputs: If a ship is placed or not
*******************************************************************************************/
bool SetBoard::placeShips(int tileNum)
{

	// If the ship was succesfully placed
	bool success = false;

	// A new ship and the size of the ship and the pointing direction
	Direction direction = Direction::HORIZONTAL;
	int size;

	// X and Y of the ship
	int x = tile[tileNum].getSprite().getPosition().x;
	int y = tile[tileNum].getSprite().getPosition().y;

	// Updates the ship
	size = ship[placedShips].getSize();

	double add = (tile[tileNum].getSprite().getGlobalBounds().width * size / 2) - tile[tileNum].getSprite().getGlobalBounds().width / 2;

	// Checks if ship can fit in a horizontal space
	if (ship[placedShips].getDirection() == Direction::HORIZONTAL
		&& tile[tileNum].getX() + size - 1 <= 10)
	{
		// checks if the space surrounding the object is placable
		bool empty = true;
		for (int i = 0; i < size && empty == true; i++)
		{
			// if the space is occupied
			if (tile[tileNum + i * 10].getState() == Status::OCCUPIED)
			{
				// ship cannot be placed
				empty = false;
			}
		}

		// The space is not empty
		if (empty == true)
		{
			// place the ship into the tiles
			for (int i = 0; i < size; i++)
			{
				tile[tileNum + i * 10].setColor(sf::Color(255, 0, 0));
				tile[tileNum + i * 10].setState(Status::OCCUPIED);
			}

			// updates ship position
			ship[placedShips].getShip()->setPos(x + add, y);
			placedShips++;
			success = true;
		}
	}
	// checks if a ship can fit in a vertical space
	else if (ship[placedShips].getDirection() == Direction::VERTICAL
		&& tile[tileNum].getY() + size - 1 <= 10)
	{
		// checks if the space surrounding the object is placable
		bool empty = true;
		for (int i = 0; i < size && empty == true; i++)
		{
			// if the space is occupied
			if (tile[tileNum + i].getState() == Status::OCCUPIED)
			{
				// ship cannot be placed
				empty = false;
			}
		}

		// The space is not empty
		if (empty == true)
		{
			// place the ship into the tiles
			for (int i = 0; i < size; i++)
			{
				tile[tileNum + i].setColor(sf::Color(255, 0, 0));
				tile[tileNum + i].setState(Status::OCCUPIED);
			}
			ship[placedShips].getShip()->setPos(x, y + add);
			placedShips++;
			success = true;
		}
	}

	// updates stage if things are set
	if (placedShips == 5)
	{
		stage = Stage::SELECT_TARGET;
	}

	return success;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void SetBoard::highlightTiles(sf::Vector2f worldPos)
* Last Updated : July 25th, 2021
* Description : Highlights all the possible moves when placing a ship
* inputs: The world position
* outputs: Nothing
*******************************************************************************************/
void SetBoard::highlightTiles(sf::Vector2f worldPos)
{
	int i = 0;
	// checks tiles
	while (i < 100)
	{
		// Checks the mouse position
		if (getTile()[i].checkMousePos(worldPos)) // meets a tile
		{
			// set the tile color
			tile[i].setColor(sf::Color(255, 0, 0));

			// Displays a vertical ship placement
			if (ship[placedShips].getDirection() == Direction::VERTICAL)
			{
				for (int p = 0; p < ship[placedShips].getSize(); p++)
				{
					int highlight = i + p;
					if (highlight < 100)
					{
						tile[highlight].setColor(sf::Color(255, 0, 0));
						if (tile[highlight].getState() == Status::EMPTY)
						{
							tile[highlight].setState(Status::HIGHLIGHTED);
						}
					}
				}
			}
			else // displays a horizontal ship placement
			{
				for (int p = 0; p < ship[placedShips].getSize(); p++)
				{
					int highlight = i + (p * 10);
					if (highlight < 100)
					{
						tile[highlight].setColor(sf::Color(255, 0, 0));
						if (tile[highlight].getState() == Status::EMPTY)
						{
							tile[highlight].setState(Status::HIGHLIGHTED);
						}
					}
				}
			}
		}
		// If the tile is a highlighted one
		else if (tile[i].getState() == Status::EMPTY || tile[i].getState() == Status::HIGHLIGHTED)
		{
			// set the tile to empty or set it to white if it is empty
			if (tile[i].getState() == Status::HIGHLIGHTED)
			{
				tile[i].setState(Status::EMPTY);
			}
			else
			{
				tile[i].setColor(sf::Color::White);
			}
		}
		i++;
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void SetBoard::flipCurrentShip()
* Last Updated : July 25th, 2021
* Description : Flips a ship position
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
void SetBoard::flipCurrentShip()
{
	if (ship[placedShips].getDirection() == Direction::VERTICAL)
	{
		ship[placedShips].setDirection(Direction::HORIZONTAL);
	}
	else
	{
		ship[placedShips].setDirection(Direction::VERTICAL);
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void SetBoard::drawBoard(sf::RenderWindow* window)
* Last Updated : July 25th, 2021
* Description : Draws a board
* inputs: The window to draw
* outputs: Nothing
*******************************************************************************************/
void SetBoard::drawBoard(sf::RenderWindow* window)
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
		(*window).draw(tile[i].getSprite());
	}
	
	int i = 0;

	// Draws every ship placed
	for (i = 0; i < placedShips; i++)
	{
		(*window).draw(ship[i].getShip()->getSprite());
	}

	// Draws a display ship
	if (i < 5)
	{
		// Set direction
		string d;
		if (ship[i].getDirection() == Direction::VERTICAL)
		{
			d = "Vertical";
		}
		else
		{
			d = "Horizontal";
		}

		// Display Direction
		sf::Text dirText("Direction: \n" + d, MyFont, 20);
		sf::FloatRect dirRect = dirText.getLocalBounds();
		dirText.setOrigin(dirRect.width / 2, dirRect.height / 2);
		dirText.setPosition(50, 100);
		(*window).draw(dirText);

		// Ship Text
		sf::Text nextText("Next Ship", MyFont, 20);
		sf::FloatRect nextRect = nextText.getLocalBounds();
		nextText.setOrigin(nextRect.width / 2, nextRect.height / 2);
		nextText.setPosition(50, 150);
		(*window).draw(nextText);


		// Create a ship that is set vertically
		Ship s(ship[i].getSize(), Direction::VERTICAL, 50, 300, 1.5f, 1.5f);
		(*window).draw(s.getShip()->getSprite());

	}
}