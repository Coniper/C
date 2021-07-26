#include <stdio.h>

int main()
{
	//检测当前机器的字节序是什么
	if (1 == check_sys())
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}

	return 0;
}

int check_sys(void)
{
	int a = 1;

	//返回1，小端
	//返回0，大端
	return *(char *)&a;
}