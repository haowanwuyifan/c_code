#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[101];		//�洢1��100��Ȼ��
	int b[99];		//�洢����
	int c[99];		//�洢����
	for (int i = 2; i < 101; i++)	//�Ե�һ�����鸳ֵ
	{
		a[i] = i;
	}
	//int i = 2;
	int j = 0;	//��¼�����ĸ���
	for (int i = 2; i <= 10; i++)
	{
		if (a[i] == 0)		//�����ǰλ�õ���ֵ��0������
		{
			continue;
		}
		else      //���򣬴���һ������ʼ������ǵ�ǰ���ı�������浽���������У���������λ��Ϊ0
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
	int m = 0;		//�����ĸ���
	for (int i = 2; i < 101; i++)
	{
		if (a[i] != 0)			//�����ǰ��λ�õ���ֵ����0����������浽����������
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
	int store[99];				//����������ͺ�������ϲ���һ��������
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
	for (int i = 0; i < 25; i++)//�������
	{
		printf("%d ", store[i]);
	}
	printf("\n");
	for (int i = 25; i < 99; i++)//�������
	{
		printf("%d ", store[i]);
	}
	system("pause");
	return 0;
}