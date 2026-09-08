#include <iostream>
#include <cstdlib>
#include "connect4.h"

//  Template to receive any size of array
template <size_t rows, size_t cols>

// We print out the status of the board after each move
void displayBoard(int (&board)[rows][cols])
{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){                
            std::cout << board[i][j] << "|";
        }
        std::cout << std::endl;
    }
}

//  We insert the coin from the player_choice using referenceRow to 
//  determine how many coins are already in the column for the height
//  then increment the referenceRow index. If max height is reached
//  the program will not insert the coin into the board.
bool insertCoin(int (&board)[][7], int choice, int turn_player)
{
    if(turn_player != 1 && turn_player != 2){
        std::cout << "[Invalid turn_player. We must have 1 or 2 as input.]" << std::endl;
        return false;
    }

    if(choice < 0 || choice > 6){
        std::cout << "[Column choice is out of bounds.]" << std::endl;
        return false;  
    }

    if(referenceRow[choice] != 6){
        board[5-referenceRow[choice]][choice] = turn_player;
        referenceRow[choice]++;
        return true;
    }else{
        std::cout << "[This is not a valid move!]" << std::endl;
        return false;
    }
}

bool checkWin(int (&board)[][7])
{
//  Check for a horizontal win
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            int coin = board[i][j];
            if(coin == 1 || coin == 2){
                if(board[i][j+1] == coin && 
                   board[i][j+2] == coin && 
                   board[i][j+3] == coin){
                    return true;
                }
            }
        }
    }
//  Check for a vertical win
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 7; j++){
            int coin = board[i][j];
            if(coin == 1 || coin == 2){
                if(board[i+1][j] == coin &&
                   board[i+2][j] == coin && 
                   board[i+3][j] == coin){
                    return true;
                }
            }
        }
    }
//  Check for a diagonal win [\]
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            int coin = board[i][j];
            if(coin == 1 || coin == 2){
                if(board[i+1][j+1] == coin &&
                   board[i+2][j+2] == coin && 
                   board[i+3][j+3] == coin){
                    return true;
                }
            }
        }
    }
//  Check for a diagonal win [/]
    for(int i = 3; i < 6; i++){
        for(int j = 0; j < 4; j++){
            int coin = board[i][j];
            if(coin == 1 || coin == 2){
                if(board[i-1][j+1] == coin &&
                   board[i-2][j+2] == coin && 
                   board[i-3][j+3] == coin){
                    return true;
                }
            }
        }
    }   
    return false;
}

//Check for a draw by scanning the top row for any zeros.
//If the top row has no zeros, then the board is full and 
//can be used to determine if there is a draw.
bool checkDraw (int (&board)[][7])
{
    for(int i = 0; i < 7; i++){
        if(board[0][i] == 0){
            return false;
        }
    }
    return true;
}

int main(){

    int bot_choice;
    int player_choice;
    int turn_player = 1;

    player_choice = 0;

    displayBoard(board);

    while(true){

//      Take in user input for their turn
        std::cout << "Please input 99 to exit or type a row between 1 and 7 to select a column to drop a piece: ";
        std::cin >> player_choice;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10,'\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        if(player_choice == 99){
            break;
        }

        std::cout << "You chose: " << player_choice << std::endl;

        if(!insertCoin(board, player_choice - 1, turn_player)){
            continue;
        }

        displayBoard(board);

        if(checkWin(board)){
            std::cout << "You won!" << std::endl;
            break;
        }

        if(checkDraw(board)){
            std::cout << "This game is a draw!" << std::endl;
            break;
        }

        //Bot turn logic: The bot must pick a valid move within the bounds of the board.
        //If it chooses outside of the bounds, the loop will restart to ensure input is valid.
        bool bot_insert = false;    
        while(!bot_insert){
            bot_choice = rand() % 7;
            bot_insert = insertCoin(board, bot_choice, 2);
        }

        std::cout << "The bot chooses: "<< bot_choice + 1 << std::endl;
        displayBoard(board);

        if(checkWin(board)){
            std::cout << "The bot won!" << std::endl;
            break;
        }

        if(checkDraw(board)){
            std::cout << "This game is a draw" << std::endl;
            break;
        }  
    }

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}