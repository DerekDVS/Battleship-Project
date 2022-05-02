#include "Board.h"

// tests if object loads an image
void test1()
{
	Object o("Images/Ship_1.png", 5, 5, 1.0f, 1.0f);
	sf::Texture t;
	if (t.loadFromFile("Images/Ship_1.png"))
	{
		std::cout << "succesfully loaded a texture" << std::endl;
		
		if (o.getSprite().getTexture() != nullptr)
		{
			std::cout << "Sprite exists" << std::endl;
		}
		else
		{
			std::cout << "Sprite failed to load" << std::endl;
		}
	}
}

// tests if objects within board are created
void test2()
{
	Board b;

	for (int i = 0; i < 5; i++)
	{
		if (b.getShip()->getShip() != nullptr)
		{
			std::cout << "Boat exists" << std::endl;
		}
		else
		{
			std::cout << "Error boat needs to be created" << std::endl;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (b.getTile() != nullptr)
		{
			std::cout << "Tile exists" << std::endl;
		}
		else
		{
			std::cout << "Error tile needs to be created" << std::endl;
		}
	}
}

void test3()
{
	// set window size
	sf::RenderWindow window(sf::VideoMode(800, 600), "Battleship (Derek Sadler)");
	sf::Event event;
	Object o("Images/Ship_1.png", 5, 5, 1.0f, 1.0f);

	// Play game by opening window
	while (window.isOpen())
	{
		// gets position relative to window
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

		// Game events
		while (window.pollEvent(event))
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

			// Mouse Button
			if (event.type == sf::Event::MouseButtonPressed)
			{
				// Left Button
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "Button pressed" << std::endl;
					if (o.checkMousePos(window.mapPixelToCoords(pixelPos)))
					{
						std::cout << "Mouse is in the object" << std::endl;
					}
					else
					{
						std::cout << "MOuse is outsdie the object" << std::endl;
					}
				}
			}
			// Game Close
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draws window
		window.clear(sf::Color(0, 0, 0));
		window.draw(o.getSprite());
		window.display();
	}
}

// Testing ship direction
void test4()
{
	Ship s(2, Direction::VERTICAL, 1, 1, 1.0f, 1.0f);
	
	// Testing the direction Vertical
	if (s.getDirection() == Direction::HORIZONTAL)
	{
		std::cout << "Horizontal" << std::endl;
	}
	else
	{
		std::cout << "Vertical" << std::endl;
	}
	std::cout << s.getShip()->getSprite().getRotation() << std::endl;
	
	// Testing the direction horizontal
	s.setDirection(Direction::HORIZONTAL);
	if (s.getDirection() == Direction::HORIZONTAL)
	{
		std::cout << "Horizontal" << std::endl;
	}
	else
	{
		std::cout << "Vertical" << std::endl;
	}

	// Testing the degree
	std::cout << s.getShip()->getSprite().getRotation() << std::endl;
	if (s.getShip()->getSprite().getRotation() == 0)
	{
		std::cout << "Vertical" << std::endl;
	}
	else
	{
		std::cout << "Horizontal" << std::endl;
	}

}

// copy constructor test
void test5()
{
	Tile tile1;
	Tile copy(tile1);
	bool success = false;

	
	if(copy.getState() == tile1.getState())
	{
		std::cout << "State equal" << std::endl;
	}
	else
	{
		success = false;
	}

	if (copy.getX() == tile1.getX())
	{
		std::cout << "X equal" << std::endl;
	}
	else
	{
		success = false;
	}

	if (copy.getY() == tile1.getY())
	{
		std::cout << "Y equal" << std::endl;
	}
	else
	{
		success = false;
	}

	if (&copy == &tile1)
	{
		std::cout << "Error same address" << std::endl;
		success = false;
	}
}