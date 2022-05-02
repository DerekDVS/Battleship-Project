#include "BattleShip.h"
#include "Board.h"
#include "SetBoard.h"
#include "Ship.h"
#include "Menu.h"

int main()
{
	// set window size
	sf::RenderWindow window(sf::VideoMode(800, 600), "Battleship (Derek Sadler)");
	sf::Event event;
	BattleShip battleship(&window, &event);
	Menu menu(&window, &event);

	// Play game by opening window
	while (window.isOpen())
	{
		// gets position relative to window
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

		// Game events
		while (window.pollEvent(event))
		{
			if (menu.getClose() == true)
			{
				battleship.playGame();
			}
			else
			{
				menu.setClose(menu.leftClick());
			}
			

			// Game Close
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		// draws window
		
		if (menu.getClose() == true)
		{
			window.clear(sf::Color(0, 0, 0));
			battleship.draw();
		}
		else
		{
			window.clear(sf::Color(50, 50, 50));
			menu.draw();
		}
		
		window.display();
	}

	return 0;
}