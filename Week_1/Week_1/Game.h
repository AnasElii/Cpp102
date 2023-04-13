#pragma once
#include <iostream>

#include "IRuleEngine.hpp"
#include "Board.h"

using namespace BoardShare;
using namespace WinningPlayer;
using namespace std;

class Board;

class Game
{
	Board& _board;
	IRuleEngine& _iRuleEngine;

public:
	Game(Board& board, IRuleEngine& iRuleEngine);
	~Game();
	WinningPlayer::E Run();
	

private:
	void Render();
	char GetSquareChar(int index, BoardSquare::E square);
};
