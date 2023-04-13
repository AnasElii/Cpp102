#include "Board.h"
#include "Game.h"
#include "IRuleEngine.hpp"
#include "RuleEngine.h"


int main()
{
	Board board(3);
	RuleEngine ruleEngine;

	Game game(board, ruleEngine);
	game.Run();

	return 0;
}