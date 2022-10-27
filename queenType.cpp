/*
    Name: Brian Nieh, 5008139573, 1005, 5
    Description: Miniature Chess
    Input: Sequence of moves
    Output: Game of chess
*/
#include "queenType.h"
#include <iostream>
// calls parent class constuctor and sets color
queenType::queenType(bool color) : chessPiece(color){}
// returns a bool if allowed
bool queenType::move(char startRow, int startCol, char endRow,
                     int endCol, chessPiece ***board){
    int endR = endRow - 'A';
    int endC = endCol - 1;
    int startR = startRow - 'A';
    int startC = startCol - 1;
    int difR = startR - endR;
    int difc = startC - endC;
    // checks if end pos is not null or if has a piece of the same color
    if (board[endR][endC] != nullptr){
        if (board[endR][endC]->getPlayerType() ==
            this->getPlayerType())
        {
            return false;
        }
    }
    // check if move possible
    if ((startR != endR && startC != endC) && (abs(difR) != abs(difc))){
        return false;
    }
    // check if along the way is not null
    for (int i = 1; i < abs(difR) || i < abs(difc); i++){
        // if its on the same col check rook like
        if (startR == endR){
            if (board[startR]
                     [startC + (-i * ((difc) / abs(difc)))] != nullptr)
            {
                return false;
            }
        }
        else if (startC == endC){
            if (board[startR + (-i * ((difR) / abs(difR)))]
                     [startC] != nullptr)
            {
                return false;
            }
        }
        // if on diagnal check bishop like
        else{
            if (board[startR + (-i * ((difR) / abs(difR)))]
                     [startC + (-i * ((difc) / abs(difc)))] != nullptr)
            {
                return false;
            }
        }
    }
    return true;
}
// when piece is deleted cout that it was taken
queenType::~queenType(){
    std::cout << "Queen Taken.\n";
}