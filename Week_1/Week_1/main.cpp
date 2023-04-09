#include <iostream>
#include <string>

using namespace std;

struct BoardSquare
{
	enum E
	{
		X,
		O,
		Empty
	};
};

class Board
{
	int _width;
	BoardSquare::E* _squares;
public:
	Board(int width) : _width(width)
	{
		_squares = new BoardSquare::E[width * width];
		for (auto i = 0; i < GetTotalSquares(); i++)
			_squares[i] = BoardSquare::Empty;
	}

	~Board()
	{
		delete[] _squares;
	}

	int GetWidth() { return _width; }
	int GetTotalSquares() { return _width * _width; }

	BoardSquare::E GetSquare(int index)
	{
		return _squares[index];
	}
	void SetSquare(int index, BoardSquare::E square)
	{
		this->_squares[index] = square;
	}
};

class IRuleEngine
{
public:
	virtual BoardSquare::E HasWon(Board board) = 0;
};

class Game
{
	Board& _board;
	IRuleEngine& _iRuleEngine;
public:
	Game( Board& board, IRuleEngine& iRuleEngine): _board(board), _iRuleEngine(iRuleEngine)
	{		
	}
	BoardSquare::E Run()
	{		
	}

private:
	void Render()
	{
		for(int i = 1; i < _board.GetTotalSquares(); i++)
		{
			cout << GetSquareChar(i, _board.GetSquare(i - 1)) << " ";
			if ((i % _board.GetWidth()) == 0)
				cout << "\n";
		}
	}

	char GetSquareChar(int index, BoardSquare::E square)
	{
		switch(square)
		{
		case BoardSquare::X: return 'X';
		case BoardSquare::O: return 'O';
		}

		return index + '0';
	}

};

int main()
{


	return 0;
}