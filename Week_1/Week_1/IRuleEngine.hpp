#pragma once

class Board;

namespace BoardShare
{
	struct BoardSquare
	{
		enum E
		{
			X,
			O,
			Empty
		};
	};

}

namespace WinningPlayer
{
	enum E
	{
		X,
		O,
		Stalemate,
		None
	};
}

class IRuleEngine
{
	virtual bool checkStaleMate(Board& board) = 0;
public:
	virtual WinningPlayer::E GetWinnerPlayer(Board& board) = 0;
};
