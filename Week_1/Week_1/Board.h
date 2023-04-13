#pragma once
#include "IRuleEngine.hpp"

using namespace BoardShare;

class Board
{
	int _width;
	BoardSquare::E* _squares;
public:
	Board(int width);
	~Board();


	int GetWidth() { return _width; }
	int GetTotalSquares() { return _width * _width; }

	BoardSquare::E GetSquare(int index);
	void SetSquare(int index, BoardSquare::E square);

};
