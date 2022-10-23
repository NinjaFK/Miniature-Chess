#include "queenType.h"
#include <iostream>
// calls parent class constuctor and sets color
queenType::queenType(bool color) : chessPiece(color)
{
}

bool queenType::move(char startRow, int startCol, char endRow,
                     int endCol, chessPiece ***board)
{
}

queenType::~queenType()
{
}
