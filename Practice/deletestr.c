/*******************************************************
	> File Name: del.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年04月27日 星期二 12时42分29秒
 *******************************************************/
#include <stdio.h>

#define N 15

void del(char *p);
int add(char *p);

int main()
{
    char str[N] = {0};
    char *p = str;
    char *q = str+1;
    int count = 0;

    printf("please enter 15 char\n>: ");
    fgets(str, N ,stdin);
    getchar();
    //aaabbbccc
    while(*p)
    {
        if((*p == *q) && ((*p >= 'A' && *p <= 'Z')||(*p >= 'a' && *p <= 'z')))
        {
            del(q);
        }
        else
        {
            p++;
            q = p+1;

        }
    }
    int ret = add(str);
    printf("数组内数字之和为>: %d\n压缩后>:%s\n", ret, str);
    //puts(str);

    return 0;
}

void del(char *p)
{
    while(*p)
    {
        *p = *(p+1);
        p++;
    }
    return ;
}

int add(char *p)
{
    int sum = 0;
    while(*p)
    {
        if(*p >= '0' && *p <= '9')
        {
            sum += *p - 48;
        }
        p++;
    }
    return sum;
}
