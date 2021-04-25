/*******************************************************
	> File Name: memset.c
	> Author:Coniper
	> Describe: 
	> Created Time: 2021年04月13日 星期二 21时48分04秒
 *******************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    //memory(内存) set(设置)
    char str[] = "hello world";
    memset(str, '*', 5); //地址指向的内存块， value(要设置的值,一个int类型 字符的话是ascii码值)， 个数
    printf("%s\n", str);

    return 0;
}

