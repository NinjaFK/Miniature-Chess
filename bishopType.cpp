#include "bishopType.h"
#include <cmath>
#include <iostream>
// calls parent class constuctor and sets color
bishopType::bishopType(bool color) : chessPiece(color)
{
}
// returns a bool if allowed
bool bishopType::move(char startRow, int startCol, char endRow,
					  int endCol, chessPiece ***board)
{
	int endR = endRow - 'A';
	int endC = endCol - 1;
	int startR = startRow - 'A';
	int startC = startCol - 1;
	int difR = startR - endR;
	int difc = startC - endC;
	// checks if end pos is not null or if has a piece of the same color
	if (board[endR][endC] != nullptr)
	{
		if (board[endR][endC]->getPlayerType() ==
			this->getPlayerType())
		{
			return false;
		}
	}
	// check if move possible
	if (abs(difR) != abs(difc))
	{
		return false;
	}
	// check if along the way is not null
	for (int i = 1; i < abs(difR); i++)
	{
		if (board[startR + (-i * ((difR) / abs(difR)))]
				 [startC + (-i * ((difc) / abs(difc)))] != nullptr)
		{
			return false;
		}
	}

	std::cout << "line 49\n";

	return true;
}
// when piece is deleted cout that it was taken
bishopType::~bishopType()
{
	std::cout << "Bishop Taken.\n";
}
