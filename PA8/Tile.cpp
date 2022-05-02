	/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : Tile is the game tiles that user can interact with while playing battleship
* ******************************************************************************************/
#include "Tile.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Tile::Tile():Object("Images/Tile.png")
* Last Updated : July 25th, 2021
* Description : Default constructor using the object constructor
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
Tile::Tile() :Object("Images/Tile.png")
{
	// status
	state = Status::EMPTY;
	x = 0;
	y = 0;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Tile::Tile(int xPos, int yPos, float xSize, float ySize) : Object("Images/Tile.png", xPos, yPos, xSize, ySize)
* Last Updated : July 25th, 2021
* Description : Tile constructor which uses the object constructor and sets the tiles properties as well
* inputs: The x and y position, and the x and y scale
* outputs: Nothing
*******************************************************************************************/
Tile::Tile(int xPos, int yPos, float xSize, float ySize) : Object("Images/Tile.png", xPos, yPos, xSize, ySize)
{
	state = Status::EMPTY;
	x = 0;
	y = 0;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Tile::Tile(Tile& copy) : Object("Images/Tile.png", copy.getSprite().getPosition().x, copy.getSprite().getPosition().y, copy.getSprite().getScale().x, copy.getSprite().getScale().y)
* Last Updated : July 25th, 2021
* Description : Tile  copy constructor
* inputs: The tile to copy
* outputs: Nothing
*******************************************************************************************/
Tile::Tile(Tile& copy) : Object("Images/Tile.png", copy.getSprite().getPosition().x, copy.getSprite().getPosition().y, copy.getSprite().getScale().x, copy.getSprite().getScale().y)
{
	state = copy.getState();
	x = copy.getX();
	y = copy.getY();
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Tile::setState(Status newState)
* Last Updated : July 25th, 2021
* Description : Setter for the object state
* inputs: The new status
* outputs: Nothing
*******************************************************************************************/
void Tile::setState(Status newState)
{
	state = newState;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Tile::setX(int newX)
* Last Updated : July 25th, 2021
* Description : Setter for the x
* inputs: The new x pos
* outputs: Nothing
*******************************************************************************************/
void Tile::setX(int newX)
{
	x = newX;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Tile::setY(int newY)
* Last Updated : July 25th, 2021
* Description : Setter for the Y
* inputs: The new y pos
* outputs: Nothing
*******************************************************************************************/
void Tile::setY(int newY)
{
	y = newY;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Status int Tile::getY()
* Last Updated : July 25th, 2021
* Description : Getter for the x position
* inputs: Nothing
* outputs: Object x
*******************************************************************************************/
int Tile::getX()
{
	return x;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Status int Tile::getY()
* Last Updated : July 25th, 2021
* Description : Getter for the y position
* inputs: Nothing
* outputs: Object y
*******************************************************************************************/
int Tile::getY()
{
	return y;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Status Tile::getState()
* Last Updated : July 25th, 2021
* Description : Getter for the tile state
* inputs: Nothing
* outputs: Object status
*******************************************************************************************/
Status Tile::getState()
{
	return state;
}