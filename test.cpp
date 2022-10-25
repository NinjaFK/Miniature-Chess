#include <iostream>
#include "knightType.h"
#include "chessPiece.h"
#include "rookType.h"
#include "bishopType.h"
#include "queenType.h"

#define RESET "\033[0m"
#define RED "\033[31m"

void outputBoard(chessPiece ***);
void clearBoard(chessPiece ***);

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
    // board[6][6] = new rookType(false);
    // board[5][6] = new rookType(false);
    // board[6][3] = new rookType(false);
    board[6][6] = new queenType(false);
    // board[5][6] = new queenType(false);
    // board[6][3] = new queenType(false);
    // board[2][2] = new queenType(false);

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
    /* std::cout << board[6][6]->move('G', 7, 'F', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'G', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'G', 6, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'F', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'E', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'A', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'G', 1, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 3, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'E', 4, board) << '\n'; */

    // queen
    // rook like moves
    /* std::cout << board[6][6]->move('G', 7, 'F', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'G', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'G', 6, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'F', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'E', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'A', 7, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'G', 1, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 3, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'E', 4, board) << '\n'; */
    //  bishoop like moves
    /* std::cout << board[6][6]->move('G', 7, 'F', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 8, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 6, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'F', 6, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'D', 4, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'A', 1, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'B', 2, board) << '\n'; */
    // random tests should be all zeros
    /* std::cout << board[6][6]->move('G', 7, 'E', 6, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 5, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 4, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'H', 1, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 4, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'B', 5, board) << '\n';
    std::cout << board[6][6]->move('G', 7, 'C', 8, board) << '\n'; */

    outputBoard(board);

    clearBoard(board);
    return 0;
}

void outputBoard(chessPiece ***board)
{
    std::cout << " ";
    for (int i = 1; i < 9; i++)
    {
        std::cout << "  " << i;
    }
    std::cout << '\n';
    for (int i = 0; i < 8; i++)
    {
        std::cout << static_cast<char>('A' + i);
        for (int j = 0; j < 8; j++)
        {
            if (dynamic_cast<queenType *>(board[i][j]))
            {
                std::cout << "  Q";
            }
            else if (dynamic_cast<knightType *>(board[i][j]))
            {
                std::cout << "  K";
            }
            else if (dynamic_cast<bishopType *>(board[i][j]))
            {
                std::cout << "  B";
            }
            else if (dynamic_cast<rookType *>(board[i][j]))
            {
                std::cout << "  R";
            }
            else
            {
                std::cout << "  -";
            }
        }
        std::cout << '\n';
    }
}

void clearBoard(chessPiece ***board)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j] != nullptr)
            {
                delete board[i][j];
            }
}