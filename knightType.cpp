#include "knightType.h"
#include <iostream>
#include <cmath>
// calls parent class constuctor and sets color
knightType::knightType(bool color) : chessPiece(color)
{
}
// returns a bool if allowed
bool knightType::move(char startRow, int startCol, char endRow,
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
    if (!((abs((startRow - 'A') - (endRow - 'A')) == 2 &&
           abs((startCol - 1) - (endCol - 1)) == 1) ||
          (abs((startRow - 'A') - (endRow - 'A')) == 1 &&
           abs((startCol - 1) - (endCol - 1)) == 2)))
    {
        return false;
    }
    return true;
}
// when piece is deleted cout that it was taken
knightType::~knightType()
{
    std::cout << "Knight Taken.\n";
}
