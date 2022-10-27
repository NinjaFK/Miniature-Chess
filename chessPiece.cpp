/*
	Name: Brian Nieh, 5008139573, 1005, 5
	Description: Miniature Chess
	Input: Sequence of moves
	Output: Game of chess
*/
#include <iostream>
#include "chessPiece.h"
// sets the color based into base class color
chessPiece::chessPiece(bool color)
{
	this->color = color;
}
// returns the color of player
bool chessPiece::getPlayerType() const
{
	return color;
}
// deallocates the chess pieces and sends a message
chessPiece::~chessPiece()
{
	std::cout << "Piece removed from board.\n";
}
