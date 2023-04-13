#include "Game.h"

Game::Game(Board& board, IRuleEngine& iRuleEngine) : _board(board), _iRuleEngine(iRuleEngine) {}
Game::~Game(){}

WinningPlayer::E Game::Run()
{
	WinningPlayer::E winningPlayer, currentPlayer = WinningPlayer::X;
	while ((winningPlayer = _iRuleEngine.GetWinnerPlayer(_board)) == WinningPlayer::None)
	{
		Render();

		int input;
		cout << "Move for " << (currentPlayer == WinningPlayer::X ? 'X' : 'O') << " : ";
		cin >> input;
		cin.ignore();

		input -= 1;
		if (input < 0 || input > _board.GetTotalSquares() || _board.GetSquare(input) != BoardSquare::Empty)
		{
			cout << "Invalid Move \n";
			continue;
		}

		_board.SetSquare(input, currentPlayer == WinningPlayer::X ? BoardSquare::X : BoardSquare::O);
		currentPlayer = currentPlayer == WinningPlayer::X ? WinningPlayer::O : WinningPlayer::X;
	}

	return winningPlayer;
}

void Game::Render()
{
	for (int i = 1; i <= _board.GetTotalSquares(); i++)
	{
		cout << GetSquareChar(i, _board.GetSquare(i - 1)) << " ";
		if ((i % _board.GetWidth()) == 0)
			std::cout << "\n";
	}
}

char Game::GetSquareChar(int index, BoardSquare::E square)
{
	switch (square)
	{
	case BoardSquare::X: return 'X';
	case BoardSquare::O: return 'O';
	}

	return index + '0';
}

