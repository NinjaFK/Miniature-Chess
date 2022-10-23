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
	// checks if end pos is not null or if has a piece of the same color
	if (board[endRow - 'A'][endCol - 1] != nullptr)
	{
		if (board[endRow - 'A'][endCol - 1]->getPlayerType() ==
			this->getPlayerType())
		{
			return false;
		}
	}
	// check if move possible

	// check if along the way is not null
}
// when piece is deleted cout that it was taken
bishopType::~bishopType()
{
	std::cout << "Bishop Taken.\n";
}
