#include "rookType.h"
#include <iostream>
// calls parent class constuctor and sets color
rookType::rookType(bool color) : chessPiece(color)
{
}
// returns a bool if allowed
bool rookType::move(char startRow, int startCol, char endRow,
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
	std::cout << "line 26\n";
	std::cout << startR << '\n'
			  << startC << '\n'
			  << endR << '\n'
			  << endC << '\n'
			  << difR << '\n'
			  << difc << '\n'
			  << '\n';
	// check if move possible
	if (startR != endR && startC != endC)
	{
		return false;
	}
	// check if along the way is not null
	std::cout << "line 40\n";
	for (int i = 1; i < abs(difR) || i < abs(difc); i++)
	{
		std::cout << "Line 42" << '\n'
				  << (difR) / abs(difR) << '\n'
				  << (difc) / abs(difc) << '\n'
				  << '\n'
				  << startR + (-i * ((difR) / abs(difR))) << '\n'
				  << startC + (-i * ((difc) / abs(difc))) << '\n';
		if (board[startR + (-i * ((difR) / abs(difR)))]
				 [startC + (-i * ((difc) / abs(difc)))] != nullptr)
		{
			return false;
		}
	}
	return true;
}
// when piece is deleted cout that it was taken
rookType::~rookType()
{
	std::cout << "Rook Taken.\n";
}
