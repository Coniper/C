/*******************************************************
	> File Name: test.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年04月19日 星期一 22时56分29秒
 *******************************************************/
#include "game.h"

void menu()
{
    printf("****************************\n");
    printf("****1.play        0.exit****\n");
    printf("****************************\n");
}

void game()
{
    char ret = 0;
    //棋盘信息
    char board[ROW][COL] = {48};
    //棋盘初始化    (虽然数字0也是不可打印字符，但最好要给他初始化为空格)
    InitBoard(board, ROW, COL); 
    //打印棋盘
    DisplayBoard(board, ROW, COL);
    //下棋
    while(1)
    {
        //玩家
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        
        //判断玩家是否胜利
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
            break;
        //电脑
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        
        //判断电脑是否胜利
        ret = IsWin(board, ROW, COL);
        if(ret != 'C')
                break;

    }
    if(ret == '*')
        printf("玩家获胜\n");
    else if(ret == '#')
        printf("电脑获胜\n");
    else
        printf("平局\n");
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();
                printf("三子棋\n");
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误,请重新选择！\n");
                break;
        }
        
    }while(input);

    return 0;
}

