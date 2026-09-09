# connect4

## **Prerequisites I used on my system for running this program:**
    -cmake version 3.28.3
    -g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0
    -GNU Make 4.3

    Command I ran within Ubuntu(running in WSL:Ubuntu on VSCode) to get
    the assignments environment:
    sudo apt-get update
    sudo apt-get install build-essential

    Commands used at top level of repo to run the game:
    cmake .
    make
    ./connect4

## **Some additional instructions**
When running this program, if you would like to access test boards
used to check for win conditions or draw states, type in "365" when asked
to select a column to place a coin. The program will display the boards 
being used and show whether a human won, a bot won, or a draw has occured.

## **Statistics for this assignment:**
```
**Time spent:** ~6 hours
**Bugs:*
    -For the functions where the bot must make a move, its turn_player
     value is hard coded while I have a variable used to store that data.
     I would like the turn_player value to change its data as the player
     and bot swap betweem their turns in the program.
    -There is a bug I see if the game receives a board whos input
     contains a full top row (a row with no zeroes) where the program
     will deem this as a full board when there could be all zeros 
     contained in the row below. Therefore a different check may have 
     to be used to account for the zeroes below a full row at the top
     of the board.
**Features/Improvements I would like to make:**
    -Create a GUI for usage on a desktop
    -If the game remains in a terminal, I would like different colored text
    -In the functions of checkDraw(), checkWin(), and insertCoin()
     I would have liked to be able to have them take in an array of
     any size. That way I can always check for any sized array for
     a connect four. This would also need the usage of modulo for finding
     the halfway point with the logic used in the current program 
     for finding where to begin searching for the winning setups of 
     the game 
```
