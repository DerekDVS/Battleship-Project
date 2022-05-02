#include "Board.h"
#include "SetBoard.h"
#include "PlayBoard.h"

enum class Turn
{
	PLAYER_1, PLAYER_2
};

class BattleShip
{
public:
	// Constructors
	BattleShip(sf::RenderWindow* w, sf::Event* e);
	~BattleShip();

	// functions
	void playGame();
	void draw();

private:
	// Game Variables
	SetBoard setPlayer1;
	SetBoard setPlayer2;

	PlayBoard *playPlayer1;
	PlayBoard *playPlayer2;

	Turn turn;
	int shots = 1;

	// Event/Screen Variables
	sf::RenderWindow* window;
	sf::Event* event;

	// private events
	Turn switchTurn();
	void placeShips(SetBoard* player);
	void hitTarget(PlayBoard* player);
};