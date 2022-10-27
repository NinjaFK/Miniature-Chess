/*
	Name: Brian Nieh, 5008139573, 1005, 5
	Description: Miniature Chess
	Input: Sequence of moves
	Output: Game of chess
*/
#include <iostream>
#include "chessPiece.h"
#include "queenType.h"
#include "rookType.h"
#include "bishopType.h"
#include "knightType.h"
#define RESET "\033[0m"
#define RED "\033[31m"
void outputBoard(chessPiece ***);
void clearBoard(chessPiece ***);
int main(){
	chessPiece ***board;
	board = new chessPiece **[8];
	for (int i = 0; i < 8; i++)
		board[i] = new chessPiece *[8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;
	// place the black chess pieces onto
	// the board
	board[0][3] = new knightType(false);
	board[1][0] = new rookType(false);
	board[1][2] = new bishopType(false);
	board[1][3] = new queenType(false);
	board[1][4] = new bishopType(false);
	board[1][6] = new rookType(false);
	board[2][3] = new knightType(false);
	// place the red chess pieces onto
	// the board
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
	// while there are pieces ask for a move
	while (redPieces > 0 && blackPieces > 0){
		std::cout << "\nEnter starting coordinates (";
		// Based on turn print the turn
		if (turn){
			std::cout << "red turn";
		}
		else{
			std::cout << "black turn";
		}
		std::cout << "): ";
		// input from user
		std::cin >> row1 >> col1;
		col1--;
		// if starting coordinate is empty try again
		if (board[row1 - 'A'][col1] == nullptr){
			std::cout << "Starting coordinate is empty!\n";
			continue;
		}
		// if the choosen piece is another color print invalid and try again
		if (board[row1 - 'A'][col1]->getPlayerType() != turn){
			std::cout << "Invalid piece selected.\n";
			continue;
		}
		// asking for end coordinates
		std::cout << "Enter ending coordinates: ";
		std::cin >> row2 >> col2;
		col2--;
		// if the move is vaild
		if (board[row1 - 'A'][col1]->move(row1, col1 + 1, row2, col2 + 1, board)){
			// if there is a piece there remove it
			if (board[row2 - 'A'][col2] != nullptr){
				delete board[row2 - 'A'][col2];
				board[row2 - 'A'][col2] = nullptr;
				// remove other players piece if based on turn
				if (turn){
					blackPieces--;
				}
				else{
					redPieces--;
				}
			}
			// soft copy
			board[row2 - 'A'][col2] = board[row1 - 'A'][col1];
			// then set old coordinate to null
			board[row1 - 'A'][col1] = nullptr;
			// print the board
			outputBoard(board);
			// change turn
			turn = !turn;
		}
		// if the move is invaild
		else if (board[row1 - 'A'][col1]->move(row1, col1 + 1, row2, col2 + 1, board) == false){
			std::cout << "Invalid move!\n";
		}
	}
	// when one player's pieces reach 0 it breaks out of loop then prints who wins
	if (blackPieces == 0){
		std::cout << "Red wins!\n";
	}
	else{
		std::cout << "Black wins\n";
	}
	clearBoard(board);
	return 0;
}
// outputs the current board
void outputBoard(chessPiece ***board){
	// print 1 through 8
	std::cout << "\n ";
	for (int i = 1; i < 9; i++){
		std::cout << "  " << i;
	}
	std::cout << '\n';
	// print rest of the board
	for (int i = 0; i < 8; i++){
		// prints the letter
		std::cout << static_cast<char>('A' + i);
		std::cout << " ";
		// prints the pieces in a row
		for (int j = 0; j < 8; j++){
			// if the piece is red change cout to red
			if (board[i][j] != nullptr){
				if (board[i][j]->getPlayerType() == true){
					std::cout << RED;
				}
			}
			// using dynamic casting to check if a piece could be the correct one
			if (dynamic_cast<queenType *>(board[i][j])){
				std::cout << " Q ";
			}
			else if (dynamic_cast<knightType *>(board[i][j])){
				std::cout << " K ";
			}
			else if (dynamic_cast<bishopType *>(board[i][j])){
				std::cout << " B ";
			}
			else if (dynamic_cast<rookType *>(board[i][j])){
				std::cout << " R ";
			}
			// if it is not any piece print a dash
			else{
				std::cout << " - ";
			}
			// reset after each piece
			std::cout << RESET;
		}
		// reset after each row
		std::cout << RESET;
		std::cout << '\n';
	}
}
// deallocates board in a nested for loop
void clearBoard(chessPiece ***board){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (board[i][j] != nullptr){
				delete board[i][j];
			}
		}
		delete[] board[i];
	}
	delete[] board;
}