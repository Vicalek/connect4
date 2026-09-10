#include <iostream>
#include <cstdlib>
#include <ctime>
#include "connect4.h"

int main(){

    runGame();

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
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

//Main logic to determine a win. We scan for the four types
//of win conditions for either player here.
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

//Initialize and set variables for game start.
//All game logic starts and is contained here.
void runGame(){

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    int bot_choice;
    int player_choice = 0;
    int turn_player = 1;

    displayBoard(board);

    while(true){

//      Take in user input for their turn
        std::cout << "Please input 99 to exit or type a row between 1 and 7 to select a column to drop a piece: ";
        std::cin >> player_choice;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(999,'\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        //If user inputs 99, they exit the game. If user inputs the secret 365 choice then
        //we use testing data from external boards to show how the script checks for wins.
        if(player_choice == 99){
            break;
        }else if(player_choice == 365){
            runTestBoards();
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

    return;

}