/*
    Name: Brian Nieh, 5008139573, 1005, 5
    Description: Miniature Chess
    Input: Sequence of moves
    Output: Game of chess
*/
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
    int endR = endRow - 'A';
    int endC = endCol - 1;
    int startR = startRow - 'A';
    int startC = startCol - 1;
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
    if (!((abs((startR) - (endR)) == 2 &&
           abs((startC) - (endC)) == 1) ||
          (abs((startR) - (endR)) == 1 &&
           abs((startC) - (endC)) == 2)))
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
