#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n ;					//动态创建一个长度为n的二维数组
    scanf_s("%d",&n);
	char** a = (char**)malloc(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (char*)malloc(n);
	}
	for (int i = 0; i<n; i++)		//初始化，全部设为空
	{
		for (int j = 0; j<n; j++)
		{
			a[i][j] = ' ';
		}
	}
    int m;				//取中间位置
	if (n % 2)			//n为奇数，可以建立菱形
	{
		m = n / 2;
		for (int i = 0; i <= m; i++)	//在上半部分对应的位置输出“*”表示菱形的边
		{
			a[i][m - i] = '*';
			a[i][m + i] = '*';
		}
		for (int i = m + 1; i<n; i++)//在下半部分对应的位置输出“*”表示菱形的边
		{
			a[i][i - m] = '*';
			a[i][n - i + m - 1] = '*';
		}
	}
	else
	{									//偶数不能建立菱形，将其转化为n-1的菱形
		n = n - 1;
		m = n / 2;
		for (int i = 0; i <= m; i++)	//在上半部分对应的位置输出“*”表示菱形的边
		{
			a[i][m - i] = '*';
			a[i][m + i] = '*';
		}
		for (int i = m + 1; i<n; i++)//在下半部分对应的位置输出“*”表示菱形的边
		{
			a[i][i - m] = '*';
			a[i][n - i + m - 1] = '*';
		}
	}
	for (int i = 0; i<n; i++)		//输出二维数组
	{
		for (int j = 0; j<n; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
    return 0;
}
