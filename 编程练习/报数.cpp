#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[51];			//����һ������Ϊ51�����飬��1��ʼ����
	for (int i = 1; i < 51; i++)		//��ʼ������ÿ��Ԫ�ص��ڶ�Ӧ��λ��
	{
		a[i] = i;
	}
	int count = 0;		//������¼�Ƿ�ﵽ3��
	int erase = 0;		//������¼ɾ����ֵ�ĸ���
	while (erase != 49)//��ɾ��49��Ԫ��֮ǰ
	{
		for (int i = 1; i < 51; i++)
		{
			if (a[i] == 0)		//��������е���ֵ��0������
			{
				//i++;
				continue;
			}
			count++;		//���ǵĻ�����
			if (count == 3)//����������3��ʱ�����Ӧλ�õ���ֵΪ0
			{
				a[i] = 0;
				count = 0;
				erase++;
			}
		}
	}
	printf("the sequence is:");//�����Ϊ0����ֵ����Ϊ��Ӧλ��
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