/*******************************************************
	> File Name: hanshu_1.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年04月15日 星期四 22时44分26秒
 *******************************************************/
#include <stdio.h>
#include <math.h>

int is_prime(int n);

int main()
{
    int su = 0;
    scanf("%d", &su);
    int ret = is_prime(su);
    if(ret == 1)
        printf("是素数\n");
    else
        printf("不是素数\n");
    return 0;
}

int is_prime(int n)
{
    int i;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

