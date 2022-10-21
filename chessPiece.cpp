#include <iostream>
#include "chessPiece.h"

chessPiece::chessPiece(bool color)
{
	this->color = color;
}

bool chessPiece::getPlayerType() const
{
	return color;
}

chessPiece::~chessPiece()
{
	std::cout << "Piece removed from board.\n";
}
