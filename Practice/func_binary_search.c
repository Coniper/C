/*******************************************************
  > File Name: funs_binary_search.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年04月15日 星期四 23时21分54秒
 *******************************************************/
#include <stdio.h>
#include <string.h>

int binary_search(int arr[], int k, int sz);


int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 0;
    printf("请输入查找的值\n>: ");
    scanf("%d", &k);
    int sz = sizeof(arr)/sizeof(arr[0]);//求数组大小

    int ret = binary_search(arr, k, sz);//获取函数返回值，且把数组，目标和数组长度传过去

    if(ret == -1)
        printf("没找到\n");
    else
        printf("找到了，下标为：%d\n", ret);

    return 0;
}

int binary_search(int arr[], int x, int sz)
{
    int left = 0;//数组左下标
    int right = sz-1;//数组右下标
    //int right = sizeof(arr)/sizeof(arr[0])-1; 太浪费空间，所以只传过来了首元素的地址
    while(left <= right)//只有交错才会没有找到 且相等也可能正是目标
    {
        int mid = (left+right)/2;//数组中间下标
        if(arr[mid] < x)//查找目标大于中间值
        {
            left = mid+1;//左下标移动到中间的后面
        }
        else if(arr[mid] > x)//查找目标小于中间值
        {
            right = mid-1;//右下标移动值中间值前面
        }
        else//如果等于中间值 说明找到了
            return mid;//返回下标
    }
    return -1;//没有找到
}

