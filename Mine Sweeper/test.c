/*******************************************************
  > File Name: test.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年05月02日
 *******************************************************/
#include "game.h"

void menu(void)
{
    printf("*************************************\n");
    printf("************   1.play   *************\n");
    printf("************   0.exit   *************\n");
    printf("*************************************\n");

    return ;
}

void game()
{
    printf("\n\tmine sweeper\n\n");
    //雷的信息存储
    //1.布置好的雷的信息
    char mine[ROWS][COLS] = {0};//11*11
    //2.排查出的雷的信息
    char show[ROWS][COLS] = {0};
    //初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '#');
    //打印棋盘
    DisplayBoard(show, ROW, COL);
    //布置雷
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);
    //扫雷
    FindMine(mine, show, ROW, COL);
}

void test()
{
    int input = 0;
    srand((unsigned)time(NULL));

    do
    {
        menu();
        printf("请选择>: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("\t    退出游戏\n");
                break;
            default:
                printf("\t 选择错误,重新选择\n");
                break;
        }
    }while(input);

}

int main()
{
    test();

    return 0;
}
