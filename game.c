#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h"
#include "steps.h"
#include "board.h"

void printMenu()
{
	printf("\nPlease choose one of the following options:\n");
	printf("N/n - New Game\n");
	printf("R/r - Move Right\n");
	printf("L/l - Move Left\n");
	printf("U/u - Move Up\n");
	printf("D/d - Move Down\n");
	printf("E/e - Exit\n");
}

int getRandNum()
{
	float prob;
	prob = (float)rand() / RAND_MAX;
	if (prob <= 0.3)
		return 4;
	else
		return 2;
}

void addRanNum(int *board, int size)
{
	int num1;
	int loc1;

	num1 = getRandNum();
	do
	{
		loc1 = rand() % ((size) * (size));
	} while (*(board + loc1) != 0);

	*(board + loc1) = num1;
}

int currScore(int *board, int size)
{
	int i, j;
	int temp = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (*((board + i * size) + j) > temp)
			{
				temp = *((board + i * size) + j);
			}
		}
	}
	return temp;
}

void playGame(int *board, int size, int scoreToWin)
{
	char ans;
	int currS = 0;
	int maxScore = 0;
	int flagStart = 0;
	int validCommand = 1;
	int gameOver = 0;
	int flagShowBoard = 1;

	clearBoard(board, size);
	printBoard(board, size);

	do
	{
		if (validCommand && flagStart && !gameOver && flagShowBoard)
		{
			printf("Score %d  Best %d\n", currS, maxScore);
			printBoard(board, size);
		}

		if (gameOver)
		{
			printMenu();
			scanf(" %c", &ans);

			if (tolower(ans) == 'n')
			{
				currS = 0;
				clearBoard(board, size);
				gameInit(board, size, scoreToWin);
				gameOver = 0;
				flagStart = 1;
			}
			else if (tolower(ans) == 'e')
			{
				break;
			}
			else
			{
				printf("please enter a valid input\n\n");
			}
			continue;
		}

		if (flagStart)
		{
			int i, won = 0;
			for (i = 0; i < size * size; i++)
			{
				if (*(board + i) >= scoreToWin)
				{
					won = 1;
					break;
				}
			}
			if (won)
			{
				printf("\nYou won %d! - Ending game \n", scoreToWin);
				gameOver = 1;
				continue;
			}
			if (canMove(board, size) == 0)
			{
				printf("\nGAME OVER your score is %d\n", currS);
				gameOver = 1;
				continue;
			}
		}

		printMenu();
		scanf(" %c", &ans);
		validCommand = 1;

		if (tolower(ans) == 'n')
		{
			currS = 0;
			clearBoard(board, size);
			gameInit(board, size, scoreToWin);
			flagStart = 1;
			gameOver = 0;
		}
		else if (tolower(ans) == 'l' || tolower(ans) == 'r' ||
				 tolower(ans) == 'u' || tolower(ans) == 'd')
		{
			if (!flagStart)
			{
				printf("Need to start game first\n\n");
				validCommand = 0;
			}
			else
			{
				switch (tolower(ans))
				{
				case 'l':
					flagShowBoard = moveLeft(board, size, &currS);
					break;

				case 'r':
					flagShowBoard = moveRight(board, size, &currS);
					break;

				case 'u':
					flagShowBoard = moveUp(board, size, &currS);
					break;

				case 'd':
					flagShowBoard = moveDown(board, size, &currS);
					break;
				}
				if (currS > maxScore)
					maxScore = currS;
			}
		}
		else if (tolower(ans) == 'e')
		{
			break;
		}
		else
		{
			printf("Please enter a valid input\n\n");
			validCommand = 0;
		}

	} while (ans != 'e' && ans != 'E');
	flagStart = 0;
	printf("Ending previous game - your score %d best score %d \n", currS, maxScore);
	printf("Bye bye :) \n");
}
