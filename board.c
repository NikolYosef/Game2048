#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"
#include "game.h"

void printBoard(int *board, int size)
{
    int i, j;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("-------");
        }
        printf("-\n");
        for (j = 0; j < size; j++)
        {
            if (*((board + i * size) + j) == 0)
            {
                printf("|      ");
            }
            else
            {
                printf("| %4d ", *((board + i * size) + j));
            }
        }
        printf("|\n");
    }
    for (j = 0; j < size; j++)
    {
        printf("-------");
    }
    printf("-\n\n");
}

void clearBoard(int *board, int size)
{
    int i;
    for (i = 0; i < (size * size); i++)
    {
        *(board + i) = 0;
    }
}

void gameInit(int *board, int size, int maxNum)
{
    int i;
    int num1, num2;
    int loc1, loc2;

    printf("\n-----------STARTING A GAME -------------\n");
    printf("          Highest tile for a win %d \n", maxNum);
    printf("----------------------------------------\n");

    for (i = 0; i < (size * size); i++)
    {
        *(board + i) = 0;
    }
    num1 = getRandNum();
    num2 = getRandNum();

    loc1 = rand() % ((size) * (size));
    do
    {
        loc2 = rand() % ((size) * (size));
    } while (loc1 == loc2);
    *(board + loc1) = num1;
    *(board + loc2) = num2;
}
