#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[51];			//创建一个长度为51的数组，从1开始计数
	for (int i = 1; i < 51; i++)		//初始化，令每个元素等于对应的位置
	{
		a[i] = i;
	}
	int count = 0;		//用来记录是否达到3个
	int erase = 0;		//用来记录删除的值的个数
	while (erase != 49)//在删除49个元素之前
	{
		for (int i = 1; i < 51; i++)
		{
			if (a[i] == 0)		//如果数组中的数值是0，跳过
			{
				//i++;
				continue;
			}
			count++;		//不是的话计数
			if (count == 3)//当计数到达3个时，令对应位置的数值为0
			{
				a[i] = 0;
				count = 0;
				erase++;
			}
		}
	}
	printf("the sequence is:");//输出不为0的数值，即为对应位置
	for (int i = 1; i < 51; i++)
	{
		if (a[i] != 0)
		{
			printf("%d", a[i]);
			printf("\n");
		}
	}
	system("pause");
	return 0;
}