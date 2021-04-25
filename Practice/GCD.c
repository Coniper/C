/*******************************************************
	> File Name: gongyushu.c
	> Author:Coniper
	> Describe:求两个数的最大公约数 
	> Created Time: 2021年04月05日 星期一 16时23分08秒
 *******************************************************/
#include <stdio.h>

int main()
{
    int m = 0;
    int n = 0;
    int r = 0;
    scanf("%d%d", &m, &n);
    while(r=m%n)
    {
        m = n;
        n = r;
    }
    printf("%d\n", n);

    return 0;
}

