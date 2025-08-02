#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"functii.h"

int main()
{
	srand(time(NULL));
	char board[3][3];
	char player,computer;
	printf("\nChoose your symbol (X/O): ");		// Asks the player what symbol he/she wants to play with
	scanf(" %c",&player);
	while(player!='X'&&player!='O')				// Checks their choice
	{
		printf("Invalid choice!!!\n");
		printf("Choose a symbol (X/O): ");
		scanf(" %c",&player);
	}
	if(player=='X')
		computer='O';
	else
		computer='X';
	printf("\nChoose your difficulty:\n\n");	// Asks the player what difficulty they want to play
	printf("1) Easy\n");
	printf("2) Normal\n");
	printf("3) Hard\n");
	printf("your choice --> ");
	int choice;
	scanf(" %d",&choice);
	getchar();
	while(choice!=1&&choice!=2&&choice!=3)
	{
		printf("Invalid choice!!!!\n");
		printf("\nChoose your difficulty:\n\n");
		printf("1) Easy\n");
		printf("2) Normal\n");
		printf("3) Hard\n");
		printf("your choice --> ");
		scanf(" %d",&choice);
		getchar();
	}
	printf("\n\n");

	gameItself(board,player,computer,choice);

	return 0;
}
