#include <iostream>
#include "connect4.h"
#include "testConnect4.h"

//Pull test data from testConnect.h in order to show funtionality of
//checkWin and checkDraw. 
void runTestBoards()
{
    std::cout << "===[THIS IS THE TEST DATA CHOICE]===" << std::endl;
    
    displayBoard(testBoard1);
    std::cout << "Test Board 1: ";
    if (checkWin(testBoard1))  std::cout << "You won! ";
    if (checkDraw(testBoard1)) std::cout << "This game is a draw! ";
    std::cout << std::endl;

    displayBoard(testBoard2);
    std::cout << "Test Board 2: ";
    if (checkWin(testBoard2))  std::cout << "You won! ";
    if (checkDraw(testBoard2)) std::cout << "This game is a draw! ";
    std::cout << std::endl;

    displayBoard(testBoard3);
    std::cout << "Test Board 3: ";
    if (checkWin(testBoard3))  std::cout << "The bot won! ";
    if (checkDraw(testBoard3)) std::cout << "This game is a draw! ";
    std::cout << std::endl;

    displayBoard(testBoard4);
    std::cout << "Test Board 4: ";
    if (checkWin(testBoard4))  std::cout << "You won! ";
    if (checkDraw(testBoard4)) std::cout << "This game is a draw! ";
    std::cout << std::endl;

    displayBoard(testBoard5);
    std::cout << "Test Board 5: ";
    if (checkWin(testBoard5))  std::cout << "The bot won! ";
    if (checkDraw(testBoard5)) std::cout << "This game is a draw! ";
    std::cout << std::endl;
    return;
}