#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using std::string;
using sf::Sprite;
using sf::Texture;
using sf::CircleShape;
using sf::Color;


class Menu
{
	public:
		Menu(sf::RenderWindow* w, sf::Event* e);
		void draw();
		bool leftClick();
		
		void setClose(bool c);
		bool getClose();
	private:
		// Event/Screen Variables
		sf::RenderWindow* window;
		sf::Event* event;
		bool close = false;
};