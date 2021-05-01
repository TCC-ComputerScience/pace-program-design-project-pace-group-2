#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int GRID_SIZE = 10;

struct BoardType{
    char GridSpace[GRID_SIZE][GRID_SIZE];
    int spaceCount = GRID_SIZE;
    int shipSpaces = 0; // Win condition
};

// Currently sets every space to the ocean character and unguessed
// Pre: Board is a BoardType that has been declared
// Post: Board.GridSpace is filled with ~
void InitBoard(/* INOUT */ BoardType &Board);

// Currently just sets a random spaces on the board to have isShip = true
// Still makes sure there are a certain amount of ship spaces (maxShipSpaces)
// Pre: Board.GridSpace is a 10 by 10 array filled with ~
// Post: Board.GrideSpace contains 8 ships
//       That are not overlapping
//       '#' represents where the ships have been placed
void PlaceShips(/* INOUT */ BoardType &Board);

// Determines if the guess was a hit or not and updates userBoard / computerBoard
// Pre: computerBoard and userBoard have been declared and initialized
//      computerBoard holds the position of the ships
//      col holds the col guessed by the user
//      row holds the row guessed by the user
// Post: computerBoard is updated to reflect whether the ship was hit or not
//       userBoard guess position is H if a hit
//       userBoard guess position is . if it is a miss
//       hitCounter is incremented if it was a hit
void DetermineGuess(/* INOUT */ BoardType &computerBoard, /* INOUT */ BoardType &userBoard, /* IN */ int col, /* IN */ int row, /* INOUT */ int &hitCounter);

// Prints out the userBoard for the user
// Pre: userBoard holds the positions of the guesses by the user and whether they were a hit or not
// Post: userBoard has been printed out to the user
void PrintBoard(/* IN */ BoardType const userBoard);

int main()
{
    int hitCounter;   // counter for the number of hits
    int col;          // col for user guess
    int row;          // row for user guess
    int guessCounter;  // counter for the number of guesses
    BoardType computerBoard;   // board for the computer to store data
    BoardType userBoard;       // board to be printed out to the user

    InitBoard(userBoard);
    InitBoard(computerBoard);
    PlaceShips(computerBoard);

    cout << "vvv Users POV vvv" << endl; //Debug, will be removed later
    for (int column = 0; column < GRID_SIZE; column++){
      for (int row = 0; row < GRID_SIZE; row++){
        cout << userBoard.GridSpace[column][row] << " ";
      }
      cout << endl;
    }

    cout << endl << endl << endl; // Spacing

    cout << "vvv Computer POV vvv" << endl; // Also Debug
    for (int column = 0; column < GRID_SIZE; column++){
      for (int row = 0; row < GRID_SIZE; row++){
        cout << computerBoard.GridSpace[column][row] << " ";
      }
      cout << endl;
    }

    // do while loop for while the user wants to play the game
      // set hitCounter and guessCounter to zero
      // call to the InitBoard function to initialize computerBoard
      // call to the InitBoard function to initialize userBoard

      // call to the PlaceShips function to place ships on computerBoard

      // call function to print the userBoard

      // while the counter for number of hits is less that 17
            // prompt the user for their next guess
            // call DetermineGuess function to find if it was a hit or not and update userBoard / computerBoard
            // call function to print the updated userBoard
            // increment guess counter



      // print out message saying that the user has won the game
      // print out message with the amount of guesses used
      // prompt the user for if they would like to play again

    return 0;
}

// Currently sets every space to the ocean character and unguessed
// Pre: Board is a BoardType that has been declared
// Post: Board.GridSpace is filled with ~
void InitBoard(/* INOUT */ BoardType &Board){
  for (int column = 0; column < GRID_SIZE; column++){
    for (int row = 0; row < GRID_SIZE; row++){
      Board.GridSpace[column][row] = '~'; // Sets every element in the array to be a '~'
    }
  }
}

// Currently just sets a random spaces on the board to have isShip = true
// Still makes sure there are a certain amount of ship spaces (maxShipSpaces)
// Pre: Board.GridSpace is a 10 by 10 array filled with ~
// Post: Board.GrideSpace contains 8 ships
//       That are not overlapping
//       '#' represents where the ships have been placed
void PlaceShips(/* INOUT */ BoardType &Board){
  srand(time(NULL)); // Generates random seed

  for (int ships = 0; ships < 8; ships++){
    //Get random coordinate variables
    int posX = rand() % 10;
    int posY = rand() % 10;

    if (Board.GridSpace[posX][posY] != '#') // If position doesn't already have a ship
      Board.GridSpace[posX][posY] = '#'; // Make a new ship
    else // Otherwise if position matched that of another pre-existing ship
      ships--; // generate a new random number and try the iteration again
  }
}
