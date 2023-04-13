#include "Board.h"

Board::Board(int width) : _width(width)
{
	_squares = new BoardSquare::E[width * width];
	for (auto i = 0; i < GetTotalSquares(); i++)
		_squares[i] = BoardSquare::Empty;
}

Board::~Board()
{
	delete[] _squares;
}

BoardSquare::E Board::GetSquare(int index)
{
	return _squares[index];
}

void Board::SetSquare(int index, BoardSquare::E square)
{
	this->_squares[index] = square;
}

