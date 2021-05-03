/*******************************************************
  > File Name: game.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年05月02日
 *******************************************************/
#include "game.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;//'0''*'
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    //打印列号
    printf("-----------------------------\n");
    for(i = 0; i <= col; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    for(i = 1; i <= row; i++)
    {
        printf("%d ", i);//打印行号
        for(j = 1; j <= col; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

//'1'-'0' = 1, ASCII '0' = 48
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y -1] +
        mine[x - 1][y] +
        mine[x - 1][y + 1] +
        mine[x][y + 1] +
        mine[x + 1][y + 1] +
        mine[x + 1][y] +
        mine[x + 1][y - 1] +
        mine[x][y - 1] - 
        8 * '0';
}

void ret(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    int count = get_mine_count(mine, x, y);
    if(count == 0)
    {
        show[x][y] = ' ';
        if(show[x - 1][y - 1] == '#')
        {
            ret(mine, show, x - 1, y - 1);
        }
        if(show[x - 1][y] == '#')
        {
            ret(mine, show, x - 1, y);
        }
        if(show[x - 1][y + 1] == '#')
        {
            ret(mine, show, x - 1, y + 1);
        }
        if(show[x][y + 1] == '#')
        {
            ret(mine, show, x, y + 1);
        }
        if(show[x + 1][y + 1] == '#')
        {
            ret(mine, show, x + 1, y + 1);
        }
        if(show[x + 1][y] == '#')
        {
            ret(mine, show, x + 1, y);
        }
        if(show[x + 1][y - 1] == '#')
        {
            ret(mine, show, x + 1, y - 1);
        }
        if(show[x][y - 1] == '#')
        {
            ret(mine, show, x, y - 1);
        }
    }
    else
    {
        show[x][y] = count + 48;
    }
}

void last(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("-----------------------------\n");
    for(i = 0; i <= col; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    for(i = 1; i <= row; i++)
    {
        printf("%d ", i);//打印行号
        for(j = 1; j <= col; j++)
        {
            //printf(" %c ", board[i][j]);
            if(board[i][j] == '1')
                printf(" * ");
            if(board[i][j] == '0')
                printf("   ");
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;//一个数模9产生0-8，+1即为1-9
        int y = rand() % col + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    //9*9-10 = 71
    while (win<row*col-EASY_COUNT)
    {
        printf("请输入排查的坐标>: ");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            //坐标合法
            //1.踩雷
            if (mine[x][y] == '1')
            {
                printf("很遗憾，排雷失败\n");
                last(mine, row, col);
                break;
            }
            else //非雷
            {
                //计算x,y周围的雷数
                int count = get_mine_count(mine, x, y);
                show[x][y] = count + 48;
                if(show[x][y] == '0')
                    ret(mine, show, x, y);
                DisplayBoard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("请输入合法坐标-> 1~9\n");
        }
    }
    if(win == row*col-EASY_COUNT)
    {
        printf("恭喜你\n");
        last(mine, row, col);
    }
}

