#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n ;					//��̬����һ������Ϊn�Ķ�ά����
    scanf_s("%d",&n);
	char** a = (char**)malloc(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (char*)malloc(n);
	}
	for (int i = 0; i<n; i++)		//��ʼ����ȫ����Ϊ��
	{
		for (int j = 0; j<n; j++)
		{
			a[i][j] = ' ';
		}
	}
    int m;				//ȡ�м�λ��
	if (n % 2)			//nΪ���������Խ�������
	{
		m = n / 2;
		for (int i = 0; i <= m; i++)	//���ϰ벿�ֶ�Ӧ��λ�������*����ʾ���εı�
		{
			a[i][m - i] = '*';
			a[i][m + i] = '*';
		}
		for (int i = m + 1; i<n; i++)//���°벿�ֶ�Ӧ��λ�������*����ʾ���εı�
		{
			a[i][i - m] = '*';
			a[i][n - i + m - 1] = '*';
		}
	}
	else
	{									//ż�����ܽ������Σ�����ת��Ϊn-1������
		n = n - 1;
		m = n / 2;
		for (int i = 0; i <= m; i++)	//���ϰ벿�ֶ�Ӧ��λ�������*����ʾ���εı�
		{
			a[i][m - i] = '*';
			a[i][m + i] = '*';
		}
		for (int i = m + 1; i<n; i++)//���°벿�ֶ�Ӧ��λ�������*����ʾ���εı�
		{
			a[i][i - m] = '*';
			a[i][n - i + m - 1] = '*';
		}
	}
	for (int i = 0; i<n; i++)		//�����ά����
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
