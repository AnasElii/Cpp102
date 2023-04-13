#include "RuleEngine.h"

using namespace BoardShare;
using namespace WinningPlayer;	

int RuleEngine::GetIndex(int x, int y, int width)
{
	return width * y + x;
}


bool RuleEngine::checkStaleMate(Board& board)
{
	for (int i = 0; i < board.GetTotalSquares(); i++)
	{
		if (board.GetSquare(i) == BoardSquare::Empty)
		{
			return true;
		}
	}

	return false;
}

WinningPlayer::E RuleEngine::GetWinnerPlayer(Board& board)
{
	// cheeking Stalemate
	if (!checkStaleMate(board))
		return WinningPlayer::Stalemate;

	// Row to win		
	for (int y = 0; y < board.GetWidth(); y++)
	{
		BoardSquare::E allOffType;

		auto firstPlayer = GetIndex(0, y, board.GetWidth());
		allOffType = board.GetSquare(firstPlayer);

		if (allOffType == BoardSquare::Empty)
			continue;

		WinningPlayer::E winningPlayer = allOffType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

		for (int x = 0; x < board.GetWidth(); x++)
		{
			if (allOffType != board.GetSquare(GetIndex(x, y, board.GetWidth())))
			{
				winningPlayer = WinningPlayer::None;
				break;
			}
		}

		if (winningPlayer != WinningPlayer::None)
			return winningPlayer;
	}

	// Column to win
	for (int x = 0; x < board.GetWidth(); x++)
	{
		BoardSquare::E allOffType;

		auto firstPlayer = GetIndex(x, 0, board.GetWidth());
		allOffType = board.GetSquare(firstPlayer);

		if (allOffType == BoardSquare::Empty)
			continue;

		WinningPlayer::E winningPlayer = allOffType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

		for (int y = 0; y < board.GetWidth(); y++)
		{
			if (allOffType != board.GetSquare(GetIndex(x, y, board.GetWidth())))
			{
				winningPlayer = WinningPlayer::None;
				break;
			}
		}

		if (winningPlayer != WinningPlayer::None)
			return winningPlayer;
	}

	//Across to win

	{
		BoardSquare::E allOffType = board.GetSquare(GetIndex(0, 0, board.GetWidth()));

		if (allOffType != BoardSquare::Empty)
		{
			WinningPlayer::E winningPlayer = allOffType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

			for (int x = 1; x < board.GetWidth(); x++)
			{

				for (int y = 1; y < board.GetWidth(); y++)
				{
					if (x != y)
						continue;

					if (allOffType != board.GetSquare(GetIndex(x, y, board.GetWidth())))
					{
						winningPlayer = WinningPlayer::None;
						break;
					}
				}

				if (winningPlayer == WinningPlayer::None)
					break;
			}

			if (winningPlayer != WinningPlayer::None)
				return winningPlayer;
		}
	}

	BoardSquare::E allOffType = board.GetSquare(GetIndex((board.GetWidth() - 1), 0, board.GetWidth()));
	if (allOffType != BoardSquare::Empty)
	{
		WinningPlayer::E winningPlayer = allOffType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

		for (int x = (board.GetWidth() - 2); x >= 0; x--)
		{

			for (int y = 1; y < board.GetWidth(); y++)
			{
				if ((board.GetWidth() - 1) - x != y)
					continue;

				if (allOffType != board.GetSquare(GetIndex(x, y, board.GetWidth())))
				{
					winningPlayer = WinningPlayer::None;
					break;
				}
			}

			if (winningPlayer == WinningPlayer::None)
				break;
		}

		if (winningPlayer != WinningPlayer::None)
			return winningPlayer;
	}

	return WinningPlayer::None;
}

