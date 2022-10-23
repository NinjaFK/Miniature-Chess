#include <iostream>
#include "knightType.h"
#include "chessPiece.h"

#define RESET "\033[0m"
#define RED "\033[31m"

int main()
{
    chessPiece ***board;

    board = new chessPiece **[8];

    for (int i = 0; i < 8; i++)
        board[i] = new chessPiece *[8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = nullptr;

    board[6][6] = new knightType(false);
    board[5][4] = new knightType(true);

    // std::cout << board[6][6]->move('G', 7, 'E', 6, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'F', 5, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'E', 9, board) << '\n';
    return 0;
}
