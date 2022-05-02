/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : The menu which gives the game instructions
* ******************************************************************************************/
#include "Menu.h"


/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Menu::Menu(sf::RenderWindow* w, sf::Event* e)
* Last Updated : July 25th, 2021
* Description : Constructor for the menu
* inputs: The window and the event tracker
* outputs: Nothing
*******************************************************************************************/
Menu::Menu(sf::RenderWindow* w, sf::Event* e)
{
	// set a reference to the menu
	window = w;
	event = e;

}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Menu::draw()
* Last Updated : July 25th, 2021
* Description : Draws the info to the screen
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
void Menu::draw()
{
	// Player font
	sf::Font MyFont;
	MyFont.loadFromFile("arial.ttf");
	
	// Text

	// Title
	int size = 50;
	sf::Text title("Battle Ship", MyFont, size);
	sf::FloatRect spriteSize = title.getGlobalBounds();
	title.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
	title.setPosition(400, 20);

	// Start Game
	sf::Text start("Press Left Click to Start!", MyFont, size);
	spriteSize = start.getGlobalBounds();
	start.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
	start.setPosition(400, 560);

	// Directions
	string dir = "Battle Ship is a game where two players fight in a navel battle.\n";
	dir.append("The game starts when each player places their five ships down ranging from 2-5 tiles long for each ship.\n");
	dir.append("The ships are placed on the board tiles, when you hover over them you will see the ships location highlighted in black\n");
	dir.append("If you wish to flip the ship press the 'right mouse' button. Once you are ready to place a ship press 'left mouse' button.\n");
	dir.append("Once every player places their ships down each player while attempt to locate the opposing players ships.\n");
	dir.append("On the top left of the screen you will see who's turn it is. When it is your turn choose a tile to shoot at.\n");
	dir.append("If the hit is light green you missed the ship, if it is dark green you hit the ship\n");
	dir.append("To hit press the 'left mouse' key. Each player will continue to hit the tiles until one sides ships have all been sunk.\n");
	dir.append("Whoever sunk all the ships first wins!");
	sf::Text directions(dir, MyFont, 15);
	spriteSize = directions.getGlobalBounds();
	directions.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
	directions.setPosition(400, 200);

	window->draw(title);
	window->draw(directions);
	window->draw(start);
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: bool Menu::leftClick()
* Last Updated : July 25th, 2021
* Description : Checks for a left mouse press
* inputs: Nothing
* outputs: If a left click happens
*******************************************************************************************/
bool Menu::leftClick()
{
	// Mouse Button
	if (event->type == sf::Event::MouseButtonPressed)
	{
		// Left Button
		if (event->mouseButton.button == sf::Mouse::Left)
		{
			return true;
		}
	}
	return false;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: bool Menu::getClose()
* Last Updated : July 25th, 2021
* Description : Getter for close
* inputs: Nothing
* outputs: Boolean of close
*******************************************************************************************/
bool Menu::getClose()
{
	return close;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Menu::setClose(bool c)
* Last Updated : July 25th, 2021
* Description : Setter for close
* inputs: The new close
* outputs: Nothing
*******************************************************************************************/
void Menu::setClose(bool c)
{
	close = c;
}