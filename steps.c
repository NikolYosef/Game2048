#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "steps.h"
#include "game.h"

int moveLeft(int *board, int size, int *score)
{
	int i, j;
	int target;
	int flagMerge;
	int flag = 0;
	for (i = 0; i < size; i++)
	{
		flagMerge = 0;
		target = 0;
		for (j = 0; j < size; j++)
		{
			if (*((board + i * size) + j) != 0)
			{
				if (target > 0 && *((board + i * size) + target - 1) == *((board + i * size) + j) && flagMerge == 0)
				{
					*((board + i * size) + target - 1) *= 2;
					*score += *((board + i * size) + target - 1);
					*((board + i * size) + j) = 0;
					flag = 1;
					flagMerge = 1;
				}
				else
				{
					if (target != j)
					{
						*((board + i * size) + target) = *((board + i * size) + j);
						*((board + i * size) + j) = 0;
						flag = 1;
					}
					target++;
					flagMerge = 0;
				}
			}
		}
	}
	if (flag == 0)
	{
		printf("Nothing to move in this direction, choose another option\n");
		printf("\n\n");
		return 0;
	}
	else
	{
		addRanNum(board, size);
		return 1;
	}
}

int moveRight(int *board, int size, int *score)
{
	int i, j;
	int target;
	int flagMerge;
	int flag = 0;
	for (i = 0; i < size; i++)
	{
		flagMerge = 0;
		target = size - 1;
		for (j = size - 1; j >= 0; j--)
		{
			if (*((board + i * size) + j) != 0)
			{
				if (target < size - 1 && *((board + i * size) + target + 1) == *((board + i * size) + j) && flagMerge == 0)
				{
					*((board + i * size) + target + 1) *= 2;
					*score += *((board + i * size) + target + 1);
					*((board + i * size) + j) = 0;
					flag = 1;
				}
				else
				{
					if (target != j)
					{
						*((board + i * size) + target) = *((board + i * size) + j);
						*((board + i * size) + j) = 0;
						flag = 1;
					}
					target--;
					flagMerge = 0;
				}
			}
		}
	}
	if (flag == 0)
	{
		printf("Nothing to move in this direction, choose another option\n");
		printf("\n\n");
		return 0;
	}
	else
	{
		addRanNum(board, size);
		return 1;
	}
}

int moveUp(int *board, int size, int *score)
{
	int i, j;
	int target;
	int flagMerge = 0;
	int flag = 0;
	for (j = 0; j < size; j++)
	{
		target = 0;
		flagMerge = 0;
		for (i = 0; i < size; i++)
		{
			if (*((board + i * size) + j) != 0)
			{
				if (target > 0 && *((board + (target - 1) * size) + j) == *((board + i * size) + j) && flagMerge == 0)
				{
					*((board + (target - 1) * size) + j) *= 2;
					*score += *((board + (target - 1) * size) + j);
					*((board + i * size) + j) = 0;
					flag = 1;
					flagMerge = 1;
				}
				else
				{
					if (target != i)
					{
						*((board + target * size) + j) = *((board + i * size) + j);
						*((board + i * size) + j) = 0;
						flag = 1;
					}
					target++;
					flagMerge = 0;
				}
			}
		}
	}
	if (flag == 0)
	{
		printf("Nothing to move in this direction, choose another option\n");
		printf("\n\n");
		return 0;
	}
	else
	{
		addRanNum(board, size);
		return 1;
	}
}

int moveDown(int *board, int size, int *score)
{
	int i, j;
	int target;
	int flag = 0;
	int flagMerge;
	for (j = 0; j < size; j++)
	{
		flagMerge = 0;
		target = size - 1;
		for (i = size - 1; i >= 0; i--)
		{
			if (*((board + i * size) + j) != 0)
			{
				if (target < size - 1 && *((board + (target + 1) * size) + j) == *((board + i * size) + j) && flagMerge == 0)
				{
					*((board + (target + 1) * size) + j) *= 2;
					*score += *((board + (target + 1) * size) + j);
					*((board + i * size) + j) = 0;
					flag = 1;
					flagMerge = 1;
				}
				else
				{
					if (target != i)
					{
						*((board + target * size) + j) = *((board + i * size) + j);
						*((board + i * size) + j) = 0;
						flag = 1;
					}
					target--;
					flagMerge = 0;
				}
			}
		}
	}
	if (flag == 0)
	{
		printf("Nothing to move in this direction, choose another option\n");
		printf("\n\n");
		return 0;
	}
	else
	{
		addRanNum(board, size);
		return 1;
	}
}

int canMove(int *board, int size)
{
	int i, j;
	for (i = 0; i < (size * size); i++)
	{
		if (*(board + i) == 0)
		{
			return 1;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((j < size - 1) && (*((board + i * size) + j) == *((board + i * size) + j + 1)))
				return 1;
			if ((j < size - 1) && (*((board + i * size) + j) == *((board + i * size) + j + size)))
				return 1;
		}
	}
	return 0;
}
