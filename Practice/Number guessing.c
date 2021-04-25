/*******************************************************
  > File Name: shuzigame.c
  > Author:Coniper
  > Describe: 猜数字游戏
  > Created Time: 2021年04月12日 星期一 21时07分05秒
 *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
void game();

int main()
{
    int input = 0;
    srand((unsigned)time(NULL));//拿时间戳来设置随机数的生成起点
    do
    {
        menu();
        printf("请选择>: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                game();//猜数字游戏
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("选择错误\n");
                break;
        }
    } while(input);

    return 0;
}

void menu()
{
    printf("********************************\n");
    printf("*********猜****数****字*********\n");
    printf("*****   1.play    0.exit   *****\n");
    printf("********************************\n");

}

void game()
{
    //1.生成随机数
    int ret = 0;
    int guess = 0;
    ret = rand()%100+1;
    //rand的范围是0-32767，生成1-100之间的随机，那么模上100就是0-99加1即可
    //printf("%d\n", ret);
    //2.猜数字
    while(1)
    {
        printf("请猜数字：> ");
        scanf("%d", &guess);
        if(guess > ret)
        {
            printf("猜大了\n\n");
        }
        else if(guess < ret)
        {
            printf("猜小了\n\n");
        }
        else
        {
            printf("恭喜你，猜对了\n\n");
            break;
        }
    }
}
