#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[101];		//存储1到100自然数
	int b[99];		//存储合数
	int c[99];		//存储质数
	for (int i = 2; i < 101; i++)	//对第一个数组赋值
	{
		a[i] = i;
	}
	//int i = 2;
	int j = 0;	//记录合数的个数
	for (int i = 2; i <= 10; i++)
	{
		if (a[i] == 0)		//如果当前位置的数值是0，跳过
		{
			continue;
		}
		else      //否则，从下一个数开始，如果是当前数的倍数，则存到合数数组中，并且令其位置为0
		{
			for(int m=i+1;m<101;m++)
			{	
				if (a[m] == 0)
				{
					continue;
				}
				else
				{
					if (a[m] % i == 0)
					{
						b[j] = a[m];
						a[m] = 0;
						j++;

					}
					else
					{
						//i++;
						continue;
					}
				}
			}
		}
	}
	int m = 0;		//质数的个数
	for (int i = 2; i < 101; i++)
	{
		if (a[i] != 0)			//如果当前的位置的数值不是0，把这个数存到质数数组中
		{
			c[m] = a[i];
			m++;
		}
		else
		{
			continue;
		}
	}
	/*for (int i = 0; i < m; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	for (int i = 0; i < j; i++)
	{
		printf("%d ", b[i]);
	}*/
	int store[99];				//将质数数组和合数数组合并到一个数组中
	for (int i = 0; i < 99; i++)
	{
		if (i < 25)
		{
			store[i] = c[i];
		}
		else
		{
			store[i] = b[i - 25];
		}
	}
	for (int i = 0; i < 25; i++)//输出数组
	{
		printf("%d ", store[i]);
	}
	printf("\n");
	for (int i = 25; i < 99; i++)//输出数组
	{
		printf("%d ", store[i]);
	}
	system("pause");
	return 0;
}