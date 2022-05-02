/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : The ship is the visible body on the tiles
* ******************************************************************************************/
#include "Ship.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Ship::Ship()
* Last Updated : July 25th, 2021
* Description : Default constructor 
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
Ship::Ship()
{
	size = 0;
	direction = Direction::VERTICAL;
	ship = new Object;
}


/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Ship::Ship(int setSize, Direction dir)
* Last Updated : July 25th, 2021
* Description : Constuctor that sets the ship size
* inputs: Size of ship and its facing direction
* outputs: Nothing
*******************************************************************************************/
Ship::Ship(int setSize, Direction dir)
{
	// sets private variables
	size = setSize;
	direction = dir;

	// new texture and data varaibles
	Texture newTexture;
	float width = ship->getSprite().getGlobalBounds().width;

	// Sets a texture based on the ship size
	switch (size)
	{
		case 2: // 2 tiles
			newTexture.loadFromFile("Images/Ship_1.png");
			ship->setTexture(newTexture);
			break;
		case 3: // 3 tiles
			newTexture.loadFromFile("Images/Ship_2.png");
			ship->setTexture(newTexture);
			break;
		case 4: // 4 tiles
			newTexture.loadFromFile("Images/Ship_3.png");
			ship->setTexture(newTexture);
			break;
		case 5: // 5 tiles
			newTexture.loadFromFile("Images/Ship_4.png");
			ship->setTexture(newTexture);
			break;
	}

	// Rotates it if necessary
	if (direction == Direction::HORIZONTAL)
	{
		ship->setRotation(90);
	}
}

Ship::Ship(Ship* copy)
{
	size = copy->size;
	Texture newTexture = *copy->ship->getSprite().getTexture();
	ship->setTexture(newTexture);
	direction = copy->direction;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Ship::Ship(int setSize, int xPos, int yPos, float xSize, float ySize)
* Last Updated : July 25th, 2021
* Description : Constuctor that sets the ship size as well as positioning and scale
* inputs: Size of ship, its direction, x and y pos, and the x and y size
* outputs: Nothing
*******************************************************************************************/
Ship::Ship(int setSize, Direction dir, int xPos, int yPos, float xSize, float ySize)
{
	// Sets private varaibles
	size = setSize;
	direction = dir;

	// Sets the object directory based on the size
	string directory;
	switch (size)
	{
		case 2:
			directory = "Images/Ship_1.png";
			break;
		case 3:
			directory = "Images/Ship_2.png";
			break;
		case 4:
			directory = "Images/Ship_3.png";
			break;
		case 5:
			directory = "Images/Ship_4.png";
			break;
	}

	// Creates a new ship
	ship = new Object(directory, xPos, yPos, xSize, ySize);
	
	// Rotates it if necessary
	if (direction == Direction::HORIZONTAL)
	{
		ship->setRotation(90);
	}
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Object Ship::getShip()
* Last Updated : July 25th, 2021
* Description : Getter for the ship
* inputs: Nothing
* outputs: Ship object
*******************************************************************************************/
Object *Ship::getShip()
{
	return ship;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: int Ship::getSize()
* Last Updated : July 25th, 2021
* Description : Getter for the ship size
* inputs: Nothing
* outputs: Ship size
*******************************************************************************************/
int Ship::getSize()
{
	return size;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Direction Ship::getDirection()
* Last Updated : July 25th, 2021
* Description : Getter for the ship direction
* inputs: Nothing
* outputs: Ship direction
*******************************************************************************************/
Direction Ship::getDirection()
{
	return direction;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Ship::setDirection(Direction dir)
* Last Updated : July 25th, 2021
* Description : Setter for the direction
* inputs: The direction to change to
* outputs: Nothing
*******************************************************************************************/
void Ship::setDirection(Direction dir)
{
	direction = dir;
	if (dir == Direction::HORIZONTAL)
	{
		ship->setRotation(90);
	}
	else
	{
		ship->setRotation(0);
	}
}