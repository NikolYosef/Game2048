#ifndef GAME_H_
#define GAME_H_

void printMenu();
int getRandNum();
void playGame(int* board, int size, int scoreToWin);
void addRanNum(int *board, int size);
int currScore(int *board, int size);

#endif
