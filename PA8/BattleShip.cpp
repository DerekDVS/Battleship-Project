/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : The game of battleship to be played
* ******************************************************************************************/
#include "BattleShip.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: BattleShip::BattleShip(sf::RenderWindow* w, sf::Event* e)
* Last Updated : July 25th, 2021
* Description : Constructor for the Battleship
* inputs: The window and the event tracker
* outputs: Nothing
*******************************************************************************************/
BattleShip::BattleShip(sf::RenderWindow* w, sf::Event* e)
{
	setPlayer1 = SetBoard(200, 100, 1.5f, 1.5f);
	setPlayer2 = SetBoard(200, 100, 1.5f, 1.5f);

	turn = Turn::PLAYER_1;

	window = w;
	event = e;

}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: BattleShip::~BattleShip()
* Last Updated : July 25th, 2021
* Description : Deletes all object in battleship
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
BattleShip::~BattleShip()
{
	delete playPlayer1;
	delete playPlayer2;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Turn BattleShip::switchTurn()
* Last Updated : July 25th, 2021
* Description : Switches a player turn
* inputs: Nothing
* outputs: New player turn
*******************************************************************************************/
Turn BattleShip::switchTurn()
{
	if (turn == Turn::PLAYER_1)
	{
		turn = Turn::PLAYER_2;
	}
	else
	{
		turn = Turn::PLAYER_1;
	}
	return turn;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void BattleShip::playGame()
* Last Updated : July 25th, 2021
* Description : Plays the game of battleship
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
void BattleShip::playGame()
{
	// If the player needs to place pieces
	if (setPlayer1.getStage() == Stage::PLACE_PIECE || setPlayer2.getStage() == Stage::PLACE_PIECE)
	{
		// place ships for each player
		if (turn == Turn::PLAYER_1)
		{
			placeShips(&setPlayer1);
			if (setPlayer1.getStage() == Stage::SELECT_TARGET)
			{
				playPlayer1 = new PlayBoard(&setPlayer1);
			}
		}
		else
		{
			placeShips(&setPlayer2);
			if (setPlayer2.getStage() == Stage::SELECT_TARGET)
			{
				playPlayer2 = new PlayBoard(&setPlayer2);
			}
		}
	}
 	else if(playPlayer1->getStage() != Stage::GAME_OVER || playPlayer2->getStage() != Stage::GAME_OVER)// player hits targets
	{
		// hit target
		if (turn == Turn::PLAYER_1)
		{
			hitTarget(playPlayer1);
		}
		else
		{
			hitTarget(playPlayer2);
		}
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void BattleShip::placeShips(SetBoard* player)
* Last Updated : July 25th, 2021
* Description : Places the ships to start the game of battleship
* inputs: The players board
* outputs: Nothing
*******************************************************************************************/
void BattleShip::placeShips(SetBoard* player)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition((*window));

	// Mouse Button
	if (event->type == sf::Event::MouseButtonPressed)
	{
		// Left Button
		if (event->mouseButton.button == sf::Mouse::Left)
		{
			// checks every tile
			int i = 0;
			bool stop = false;
			while (i < 100 && stop == false && player->getStage() == Stage::PLACE_PIECE)
			{
				// Checks mouse position
				if (player->getTile()[i].checkMousePos(window->mapPixelToCoords(pixelPos)))
				{
					if (!player->placeShips(i))
					{
						stop = true;
					}
					else if (player->getStage() == Stage::SELECT_TARGET)
					{
						switchTurn();
					}
				}
				i++;
			}
		}
		// Right Button
		if (event->mouseButton.button == sf::Mouse::Right)
		{
			if (player->getStage() == Stage::PLACE_PIECE)
			{
				player->flipCurrentShip();
			}
		}
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void BattleShip::hitTarget(PlayBoard* player)
* Last Updated : July 25th, 2021
* Description : Has the player pick a target
* inputs: The player board
* outputs: Nothing
*******************************************************************************************/
void BattleShip::hitTarget(PlayBoard* player)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition((*window));

	// Mouse Button
	if (event->type == sf::Event::MouseButtonPressed)
	{
		// Left Button
		if (event->mouseButton.button == sf::Mouse::Left)
		{
			// checks every tile
			int i = 0;
			bool stop = false;
			while (i < 100)
			{
				// Checks mouse position
				if (player->getTile()[i].checkMousePos(window->mapPixelToCoords(pixelPos)))
				{
					// Hits target and switches turn
					if (player->hitTarget(i))
					{
						if (!player->checkWinner())
						{
							switchTurn();
							if (turn == Turn::PLAYER_1)
							{
								shots++;
							}
						}
						else
						{
							// Set the players game to over
							playPlayer1->setStage(Stage::GAME_OVER);
							playPlayer2->setStage(Stage::GAME_OVER);
						}
						
					}
				}
				i++;
			}
		}
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void BattleShip::draw()
* Last Updated : July 25th, 2021
* Description : Draws everything needed for battleship
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
void BattleShip::draw()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition((*window));

	// Init font
	sf::Font MyFont;
	MyFont.loadFromFile("arial.ttf");
	sf::Text playerText;
	int size = 15;
	string text;

	// Decoration
	sf::RectangleShape rectangle(sf::Vector2f(600, 600));
	rectangle.setPosition(100, 0);
	rectangle.setFillColor(Color(50, 50, 50));
	window->draw(rectangle);
	
	// Checks player turn
	if (turn == Turn::PLAYER_1)
	{

		// checks stage
		if (setPlayer1.getStage() == Stage::PLACE_PIECE)
		{
			setPlayer1.drawBoard(window);
			setPlayer1.highlightTiles(window->mapPixelToCoords(pixelPos));
			text = "Player 1\nPlace Ships";
		}
		else if(playPlayer1->getStage() == Stage::SELECT_TARGET)
		{
			text = "Player 2\nSelect Target\nShots: " + std::to_string(shots);
			playPlayer1->drawBoard(window);
			playPlayer1->highlightTiles(window->mapPixelToCoords(pixelPos));
		}
		else
		{
			text = "Player 2\nWins!";
			playPlayer1->drawBoard(window);
		}
		
	}
	else
	{
		// checks stage
		if (setPlayer2.getStage() == Stage::PLACE_PIECE)
		{
			text = "Player 2\nPlace Ships";
			setPlayer2.drawBoard(window);
			setPlayer2.highlightTiles(window->mapPixelToCoords(pixelPos));
		}
		else if (playPlayer2->getStage() == Stage::SELECT_TARGET)
		{
			text = "Player 1\nSelect Target\nShots: " + std::to_string(shots);
			playPlayer2->drawBoard(window);
			playPlayer2->highlightTiles(window->mapPixelToCoords(pixelPos));
		}
		else
		{
			text = "Player 1\nWins!";
			playPlayer2->drawBoard(window);
		}

	}

	playerText = sf::Text(text, MyFont, size);
	playerText.setPosition(0, 0);

	window->draw(playerText);
}