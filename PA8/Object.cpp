/*******************************************************************************************
* Programmer: Derek Sadler
* Class : CptS 122, Summer 2021; Lab Section 3995
* Programming Assignment : PA 8
* Date : July 25th, 2021
* Description : Object functions a object is anything that is an image from a directly in the project
* files and can be visual seen and modified
* ******************************************************************************************/
#include "Object.h"

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Object::Object()
* Last Updated : July 25th, 2021
* Description : Default constructor
* inputs: Nothing
* outputs: Nothing
*******************************************************************************************/
Object::Object()
{
	// Load Sprite and set texture
	texture.loadFromFile("Images/Tile.png");
	texture.setSmooth(true);
	sprite.setTexture(texture);

	// Center origin
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Object::Object(string img)
* Last Updated : July 25th, 2021
* Description : Object constructor
* inputs: The directory to the image
* outputs: Nothing
*******************************************************************************************/
Object::Object(string img)
{
	// Load Sprite and set texture
	texture.loadFromFile(img);
	texture.setSmooth(true);
	sprite.setTexture(texture);

	// Center origin
	sf::FloatRect spriteSize = sprite.getGlobalBounds();
	sprite.setOrigin(spriteSize.width / 2., spriteSize.height / 2.);
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Object::Object(string img, int xPos, int yPos, float xSize, float ySize)
* Last Updated : July 25th, 2021
* Description : Object constructor that sets the position and scale
* inputs: The directory to the image, the x and y pos, and the x and y scale/size
* outputs: Nothing
*******************************************************************************************/
Object::Object(string img, int xPos, int yPos, float xSize, float ySize)
{
	// Load Texture
	texture.loadFromFile(img);
	texture.setSmooth(true);
	sprite.setTexture(texture);

	// Set Sprite Position and Scale
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setScale(xSize, ySize);
	sprite.setPosition(xPos, yPos);

}


/*Getters*/


/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Sprite Object::getSprite()
* Last Updated : July 25th, 2021
* Description : Gets the sprite of the object
* inputs: Nothing
* outputs: Object sprite and info
*******************************************************************************************/
Sprite Object::getSprite()
{
	return sprite;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: Sprite Object::getTexture()
* Last Updated : July 25th, 2021
* Description : Gets the texture of the object
* inputs: Nothing
* outputs: Object texture and info
*******************************************************************************************/
Texture Object::getTexture()
{
	return texture;
}



/*Setters*/

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Object::setSprite(Sprite new Sprite)
* Last Updated : July 25th, 2021
* Description : Seter for the sprite
* inputs: The new sprite object
* outputs: Nothing
*******************************************************************************************/
void Object::setSprite(Sprite newSprite)
{
	sprite = newSprite;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Object::setTexture(Sprite newTexture)
* Last Updated : July 25th, 2021
* Description : Seter for the texture
* inputs: The new texture object
* outputs: Nothing
*******************************************************************************************/
void Object::setTexture(Texture newTexture)
{
	texture = newTexture;
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Object::setPos(float x, float y)
* Last Updated : July 25th, 2021
* Description : Sets the object position
* inputs: The new x and y pos
* outputs: Nothing
*******************************************************************************************/
void Object::setPos(float x, float y)
{
	sprite.setPosition(x, y);
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Object::setRotation(float degree)
* Last Updated : July 25th, 2021
* Description : Sets the object rotation
* inputs: The new rotation value
* outputs: Nothing
*******************************************************************************************/
void Object::setRotation(float degree)
{
	sprite.setRotation(degree);
}



/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: void Object::setColor(sf::Color color)
* Last Updated : July 25th, 2021
* Description : Sets the object color
* inputs: The new color
* outputs: Nothing
*******************************************************************************************/
void Object::setColor(sf::Color color)
{
	sprite.setColor(color);
}

/*******************************************************************************************
* Programmer: Derek Sadler
* Class: CptS 122, Summer 2021; Lab Section 3995
* Function: bool Object::checkMousePos(sf::Vector2f worldPos)
* Last Updated : July 25th, 2021
* Description : Checks to see if the mouse is in the bounding box of the sprite
* inputs: The pixel position of the mouse relative to the window
* outputs: If the mouse is in the bounds or not
*******************************************************************************************/
bool Object::checkMousePos(sf::Vector2f worldPos)
{
	// Setting the bounds of the object
	int Left = sprite.getPosition().x - ((sprite.getTexture()->getSize().x / 2) * sprite.getScale().x);
	int Right = sprite.getPosition().x + ((sprite.getTexture()->getSize().x / 2) * sprite.getScale().x);
	int Top = sprite.getPosition().y - ((sprite.getTexture()->getSize().y / 2) * sprite.getScale().y);
	int Bottom = sprite.getPosition().y + ((sprite.getTexture()->getSize().y / 2) * sprite.getScale().y);

	// Checking the bounds
	if (Left < worldPos.x &&
		Right > worldPos.x &&
		Top < worldPos.y &&
		Bottom > worldPos.y
		)
	{
		return true;
	}
	return false;

}