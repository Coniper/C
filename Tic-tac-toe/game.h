/*******************************************************
	> File Name: game.h
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年04月19日 星期一 23时33分28秒
 *******************************************************/
#ifndef _GAME_H
#define _GAME_H
#define ROW 3 //行
#define COL 3 //列
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//能告诉我们四种游戏状态
//玩家'*'、电脑'#'、平局'Q'、未结束'C'
char IsWin(char boardp[ROW][COL], int row, int col);

#endif
