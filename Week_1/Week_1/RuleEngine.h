#pragma once
#include "IRuleEngine.hpp"
#include "Board.h"

class RuleEngine : public IRuleEngine
{
	int GetIndex(int x, int y, int width);

	bool checkStaleMate(Board& board);

public:
	WinningPlayer::E GetWinnerPlayer(Board& board);
};
