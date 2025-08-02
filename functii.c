#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"functii.h"

void initBoard(char board[][3])						// Initializes the board with empty spaces
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			board[i][j]=' ';
}

void displayBoard(char board[][3])					// Displays the board on the screen
{
	printf(" \t1\t\t2\t\t3\n\n");
	for(int i=0;i<3;++i)
	{
		printf("%c\t",'1'+i);
		for(int j=0;j<3;++j)
		{
			printf("%c\t",board[i][j]);
			if(j<2)
				printf("|\t");
		}
		printf("\n");
		if(i<2)
			printf("   ___________________________________________\n\n");
	}
}

char verifyWin(char board[][3])					// Checks the conditions of winning
{	
	//	WIN ON DIAGONAL
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
		return board[1][1];
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
		return board[1][1];

	//	WIN ON LINE
	for(int i=0;i<3;++i)
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
			return board[i][1];

	//	WIN ON COLLUMN
	for(int j=0;j<3;++j)
	{
		if(board[0][j]==board[1][j] && board[1][j]==board[2][j] && board[0][j]!=' ')
			return board[1][j];
	}
	return '-';
}

int isBoardFull(char board[][3])					// Checks if the board is fully occupied
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]==' ')
				return 0;
	return 1;
}

int firstOpenPos(char board[][3])					// Searches for the first unoccupied position
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]==' ')
				return 3*i+j;
	return -1;	
}

int getPlayerMove(char board[][3])					// Reads the coordinates chosen by the player and occupies the position
{
	int x, y;
	printf("\nChoose a position (line,column): ");
	scanf("(%d,%d)", &x, &y);
	getchar();

	while(x<1 || x>3 || y<1 || y>3 || board[x-1][y-1]!=' ')
	{
		if(x<1 || x>3 || y<1 || y>3)
			printf("\nInvalid coordinates! Use values between 1-3.\n");
		else
			printf("\nThis position already has a symbol on it.\n");
		printf("Choose somewhere else (x,y): ");
		scanf("(%d,%d)",&x,&y);
		getchar();
	}
	return 3*(x-1)+(y-1);			// -1 for 1-based display
}

int EasyMode(char board[][3])		// In easy mode the AI occupies just random positions
{
	int pos=rand()%9;
	while(board[pos/3][pos%3]!=' ')
		pos=rand()%9;
	return pos;
}

int MediumMode(char board[][3], char player, char computer)

	// The medium mode just tries to play by the "orthodox" rules: to prioritize the middle and to try winning by the common sense and to block the player if he is close to win

{

	// At first, the AI is trying to win

	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]==' ')
			{
				board[i][j]=computer;
				if(verifyWin(board)==computer)
				{
					board[i][j]=' ';
					return 3*i+j;
				}
				
					board[i][j]=' ';
			}

	// If it doesn't succed, the AI tries to block the player in case he/she wins with the next move

	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]==' ')
			{
				board[i][j]=player;
				if(verifyWin(board)==player)
				{
					board[i][j]=' ';
					return 3*i+j;
				}
				
					board[i][j]=' ';
			}

	// Now it tries to take over the middle since it is a very advantageous position

	if(board[1][1]==' ') return 4;

	// Finally he tries the corners

	for(int i=0;i<3;i+=2)
		for(int j=0;j<3;j+=2)
			if(board[i][j]==' ')
				return 3*i+j;

	return firstOpenPos(board);
}

int HardMode(char board[][3], char player, char computer)
{
	// First try to win
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]==' ')
			{
				board[i][j]=computer;
				if(verifyWin(board)==computer)
				{
					board[i][j]=' ';
					return 3*i+j;
				}
				board[i][j]=' ';
			}

	// Then try to block player
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]==' ')
			{
				board[i][j]=player;
				if(verifyWin(board)==player)
				{
					board[i][j]=' ';
					return 3*i+j;
				}
				board[i][j]=' ';
			}
	
	// Now, it begins "the corners" strategy where, the AI prioritizes
	// to occupy a random corner, then to occupy the opposite corner, forming 2
	// adiacent sides with them formed being auto-win
	 
	int occPos=0;					// Counts how many occupied positions there are, to determine the game phase
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(board[i][j]!=' ')
				occPos++;

	if(occPos==0)					// If there are no occupied positions, the AI tries to occupy a random corner
	{
		int corners[]={0,2,6,8};	// Top-left, top-right, bottom-left, bottom-right
		return corners[rand()%4];	// Random
	}

	if(occPos==2 && board[1][1]==player)	// If the game began and the middle is occupied by the player, the AI tries to find a corner occupied by itself, and to occupy the opposite corner
	{
		int ai=-1;							
		int corners[]={0,2,6,8};			
		for(int i=0;i<4;++i)
			if(board[corners[i]/3][corners[i]%3]==computer)	// Same thing as above	
			{
				ai=corners[i];
				break;
			}

		if(ai==0 && board[2][2]==' ') return 8;
		else if(ai==2 && board[2][0]==' ') return 6;
		else if(ai==6 && board[0][2]==' ') return 2;
		else if(ai==8 && board[0][0]==' ') return 0;
	}

	if(occPos==2)						// If the player didn't choose to occupy the middle, now the AI tries to find an unoccupied corner
	{
		int ai=-1;
		int corners[]={0,2,6,8};
		for(int i=0;i<4;++i)
			if(board[corners[i]/3][corners[i]%3]==computer)
			{
				ai=corners[i];
				break;
			}

		if(ai==0)						// Now it begins to form the opposites corners or the adiacent sides, preventing the player from creating a "fork"
		{
			if(board[2][2]==' ') return 8;
			if(board[0][1]==' ') return 1;
			if(board[1][0]==' ') return 3;
		}
		if(ai==2)
		{
			if(board[2][0]==' ') return 6;
			if(board[0][1]==' ') return 1;
			if(board[1][2]==' ') return 5;
		}
		if(ai==6)
		{
			if(board[0][2]==' ') return 2;
			if(board[1][0]==' ') return 3;
			if(board[2][1]==' ') return 7;
		}
		if(ai==8)
		{
			if(board[0][0]==' ') return 0;
			if(board[2][1]==' ') return 7;
			if(board[1][2]==' ') return 5;
		}
	}

	if(board[1][1]==' ') return 4;				// If the middle is free why not take it? 

	int corners[]={0,2,6,8};					// Finally he tries the first free corner just to be there
	for(int i=0;i<4;++i)
	{
		if(board[corners[i]/3][corners[i]%3]==' ')
			return corners[i];
	}

	return firstOpenPos(board);					// Random position just to put something at the end of the search
}

void insertSym(char board[][3], char symbol, int position)		// Occupies the chosen position
{
	board[position/3][position%3]=symbol;
}

void gameItself(char board[][3], char player, char computer, int difficulty)		// The GAME
{
	printf("\n\nBEGIN!!!\n\n");
	initBoard(board);
	displayBoard(board);

	char currentPlayer='X';  // X always begins first
	
	while(verifyWin(board)=='-' && !isBoardFull(board))
	{
		int position;
		
		if(currentPlayer==player)
		{
			// Player's move
			position=getPlayerMove(board);
		}
		else
		{
			// AI's move
			switch(difficulty)
			{
				case 1:
					position=EasyMode(board);
					break;
				case 2:
					position=MediumMode(board,player,computer);
					break;
				case 3:
					position=HardMode(board,player,computer);
					break;
			}
			printf("\nComputer chose position: (%d,%d)\n",position/3+1,position%3+1);	// +1 for 1-based display
			printf("\n\n");
		}
		
		insertSym(board,currentPlayer,position);
		displayBoard(board);
		
		// Switch player
		if(currentPlayer=='X')
			currentPlayer='O';
		else
			currentPlayer='X';
	}

	// Check the result
	char winner=verifyWin(board);
	if(winner=='-')
	{
		printf("\nIT IS A DRAW!!!\nIt was a very good match<3\nGG!!!\n");
	}
	else
	if(winner==player)
	{
		printf("\nCONGRATULATIONS!!!\nYOU WON<3\nGG!!!\n");
	}
	else
	{
		printf("\nCOMPUTER WINS!!!\nBetter luck next time!\nGG!!!\n");
	}
}
