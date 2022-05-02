#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using std::string;
using sf::Sprite;
using sf::Texture;
using sf::CircleShape;
using sf::Color;

class Object
{
	public:
		// Constructor
		Object();
		Object(string img);
		Object(string img, int xPos, int yPos, float xSize, float ySize);

		// Game Checks
		bool checkMousePos(sf::Vector2f worldPos);
		
		// Getter
		Sprite getSprite();
		Texture getTexture();

		// Setters
		void setSprite(Sprite newSprite);
		void setTexture(Texture newTexture);
		void setPos(float x, float y);
		void setRotation(float degree);
		void setColor(sf::Color color);
	protected:
		Texture texture;
		Sprite sprite;
		
};