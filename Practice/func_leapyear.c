/*******************************************************
	> File Name: funs_runnian.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年04月15日 星期四 23时09分55秒
 *******************************************************/
#include <stdio.h>

int is_leap_year(int x);

int main()
{
    int year = 0;
    int count = 0;
    for(year=1000; year<=2000; year++)
    {
        if(1 == is_leap_year(year))
        {
            printf("%-5d", year);
            count++;
        }
    }
    printf("\n共有：%d个闰年\n", count);

    return 0;
}

int is_leap_year(int x)
{   
    if(((x%4==0) && (x!=0)) || (x%400==0))
        return 1;
    else
        return 0;
}

