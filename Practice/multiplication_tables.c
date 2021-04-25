/*******************************************************
  > File Name: 99.c
  > Author:Coniper
  > Describe: 
  > Created Time: 2021年04月12日 星期一 14时24分35秒
 *******************************************************/
#include <stdio.h>

int main()
{
    int i, j, k, l;
    for(i=1; i<=9; i++)
    {
        for(k=9; k>i; k--)
        {
            for(l=0; l<12; l++)
            {
                printf(" ");
            }
        }
        for(j=1; j<=i; j++)
        {
            printf("%d * %d = %2d  ", j, i, i*j);
        }
        puts(" ");
    }

    return 0;
}

