/*******************************************************
  > File Name: game.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年04月19日 星期一 23时40分45秒
 *******************************************************/
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

/*void DisplayBoard(char board[ROW][COL], int row, int col)
 *{
 *    int i = 0;
 *    for(i = 0; i < row; i++)
 *    {
 *        //1.打印一行的数据
 *        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][0]);
 *        //2.打印分割行
 *        if(i < row-1)
 *            printf("---|---|---\n");
 *    }
 *}
 */

void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        //1.打印一行的数据
        for(j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col-1)
                printf("|");
        }
        printf("\n");
        //2.打印分割行
        if(i < row -1)
        {
            for(j = 0; j < col; j++)
            {
                printf("---");
                if(j < col-1)
                    printf("|");

            }
            printf("\n");
        }
    }
}

void PlayerMove(char board[ROW][COL], int row ,int col)
{
    int x = 0, y = 0;

    printf("请玩家落子\n");
    //判断坐标合法性
    while(1)
    {
        printf("请输入要下的坐标\n");
        scanf("%d%d", &x, &y);
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else
            {
                printf("落子勿动\n");
            }

        }
        else
        {
            printf("非法落子，请重新输入\n");
        }
    }
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0, y = 0;
    printf("电脑走:>\n");
    while(1)
    {
        x = rand() % row;
        y = rand() % col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//返回1，表示满了       返回0，表示棋盘未满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //三行
    for(i = 0; i < row; i++)
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
            return board[i][1];
    //三列
    for(i = 0; i < col; i++)
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[1][i];
    //两天对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
            return board[1][1];
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
            return board[1][1];
    //判断是否平局
    if(1 == IsFull(board, ROW, COL))
    {
        return 'Q';
    }
    else
    {
        return 'C';
    }
}