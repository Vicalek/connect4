#pragma once

#include <iostream>

inline int referenceRow[7]; //  Tracks the amount of coins in each column

inline int board [6][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

bool checkDraw(int (&board)[][7]);
bool checkWin(int (&board)[][7]);
bool insertCoin(int (&board)[][7], int choice, int turn_player);

void runGame();
void runTestBoards();

// We print out the status of the board after each move
// Template to receive any size of array
template <size_t rows, size_t cols>
void displayBoard(int (&board)[rows][cols])
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){                
            std::cout << board[i][j] << "|";
        }
        std::cout << std::endl;
    }
}