#include <iostream>
#include "chessPiece.h"
#include "queenType.h"
#include "rookType.h"
#include "bishopType.h"
#include "knightType.h"

#define RESET "\033[0m"
#define RED "\033[31m"

void outputBoard(chessPiece***);
void clearBoard(chessPiece***);

int main()
{
	chessPiece *** board;

	board = new chessPiece**[8];

	for (int i = 0; i < 8; i++)
		board[i] = new chessPiece*[8];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;


	//place the black chess pieces onto
	//the board
	board[0][3] = new knightType(false);
	board[1][0] = new rookType(false);
	board[1][2] = new bishopType(false);
	board[1][3] = new queenType(false);
	board[1][4] = new bishopType(false);
	board[1][6] = new rookType(false);
	board[2][3] = new knightType(false);

	//place the red chess pieces onto
	//the board
	board[5][4] = new knightType(true);
	board[6][1] = new rookType(true);
	board[6][3] = new bishopType(true);
	board[6][4] = new queenType(true);
	board[6][5] = new bishopType(true);
	board[6][7] = new rookType(true);
	board[7][4] = new knightType(true);	

	outputBoard(board);

	char row1, row2;
	int col1, col2;

	int redPieces = 7;
	int blackPieces = 7;

	bool turn = true;

	while (redPieces > 0 && blackPieces > 0)
	{
		//Your Code Goes here	
	}

	clearBoard(board);

	return 0;
}

void outputBoard(chessPiece *** board)
{
	
}


void clearBoard(chessPiece *** board)
{
	
}