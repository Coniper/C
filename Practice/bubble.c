/*******************************************************
  > File Name: bubble.c
  > Author:Coniper
  > Describe: 冒泡排序
  > Created Time: 2021年04月13日 星期二 14时00分34秒
 *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

void Srand(int* );
void Bubble_sort(int* );

int main()
{
    int i, x;
    int arr[NUM] = {0};

    printf("请输入1、输入10个值\t2、随机产生10个值\n");
    scanf("%d", &x);

    if(x == 2)
        Srand(arr);
    else if(x == 1)
        for(i=0; i < NUM; i++)
            scanf("%d", &arr[i]); //键盘输入
    else
    {
        printf("输入错误，程序已退出\n");
        return 0;
    }

    printf("原数组>: ");
    for(i=0; i < NUM; i++) //打印原数组
        printf("%-3d", arr[i]);
    puts(" ");

    Bubble_sort(arr);

    printf("排序后>: ");
    for(i=0; i < NUM; i++) //打印
        printf("%-3d", arr[i]);
    puts(" ");

    return 0;
}

void Srand(int* arr)
{
    int i = 0;
    srand((unsigned)time(NULL)); //随机值
    for(i=0; i < NUM; i++)
        arr[i] = rand()%100; //产生两位随机数

    return ;
}

void Bubble_sort(int *arr)
{
    int i = 0, j = 0;
    for(i=0; i < NUM-1; i++) //趟数
    {
        int flag = 1; //重置flag，       flag的作用为假设有序 直接退出 省略后面趟数的判断 (每一趟都会遍历数组)
        for(j=0; j < NUM-1-i; j++) //次数
        {
            if(arr[j] > arr[j+1])
            {
                arr[j] ^= arr[j+1];
                arr[j+1] ^= arr[j];
                arr[j] ^= arr[j+1];
                /*
                   int temp = arr[j+1];
                   arr[j+1] = arr[j];
                   arr[j] = temp;
                   */
                flag = 0; //flag设0， 说明本次排序的数据 并不完全有序
            }
        }
        if(flag) //如果一次都没交换直接退出循环
            break;
    }

    return ;
}
