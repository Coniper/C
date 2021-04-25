/*******************************************************
	> File Name: zuidazhi.c
	> Author:Coniper
	> Describe:求10个整数的最大值 
	> Created Time: 2021年04月05日 星期一 18时31分55秒
 *******************************************************/
#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int max = arr[0];//最大值 假设其中某一个是最大值
    int sz = sizeof(arr)/sizeof(arr[0]);//求arr数组的元素个数
    int i = 0;
    for(i=0;i<sz; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("max = %d\n", max);

    return 0;
}

