#include <iostream>
#include "knightType.h"
#include "chessPiece.h"
#include "rookType.h"
#include "bishopType.h"

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

    // board[6][6] = new knightType(false);
    // board[5][4] = new knightType(true);
    // board[4][4] = new bishopType(false);
    // board[3][5] = new bishopType(false);
    board[6][6] = new rookType(false);
    board[5][6] = new rookType(false);

    // knight moves
    // std::cout << board[6][6]->move('G', 7, 'E', 6, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'F', 5, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'E', 6, board) << '\n';

    // bishop
    /* std::cout << "line 37\n";
        std::cout << startR << '\n'
                  << startC << '\n'
                  << endR << '\n'
                  << endC << '\n'
                  << difR << '\n'
                  << difc << '\n'
                  << '\n'; */
    /* std::cout
            << (difR) / abs(difR) << '\n'
            << (difc) / abs(difc) << '\n'
            << '\n'
            << startR + (-i * ((difR) / abs(difR))) << '\n'
            << startC + (-i * ((difc) / abs(difc))) << '\n'; */
    // std::cout << board[4][4]->move('E', 5, 'C', 7, board) << '\n';

    // rook
    // std::cout << board[6][6]->move('G', 7, 'F', 7, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'G', 8, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'H', 7, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'G', 6, board) << '\n';
    // std::cout << board[6][6]->move('G', 7, 'F', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 7, board) << '\n';
    return 0;
}
