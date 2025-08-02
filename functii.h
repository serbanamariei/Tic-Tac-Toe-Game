#ifndef FUNCTII_H_
#define FUNCTII_H_

void initBoard(char board[][3]);	// Initializes the board with empty spaces
void displayBoard(char board[][3]);	// Displays the current state of the board

char verifyWin(char board[][3]);	// Checks if there is a winner on the board

int firstOpenPos(char board[][3]);	// Finds the first available position

int isBoardFull(char board[][3]);	// Checks if the board is completely filled

int getPlayerMove(char board[][3]);	// Gets and validates the player's move

int EasyMode(char board[][3]);		// Makes completely random moves
int MediumMode(char board[][3], char player, char computer);	// Uses basic strategy (win > block > center > corners)
int HardMode(char board[][3], char player, char computer);		// Uses advanced corner strategy and all medium strategies

void insertSym(char board[][3], char symbol, int position);		// Places a symbol at the specified position on the board

void gameItself(char board[][3], char player, char computer, int difficulty);	// Runs the complete tic-tac-toe game loop

#endif
