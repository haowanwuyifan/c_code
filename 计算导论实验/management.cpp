#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <cstdlib>
#define LEN 15
#define N 15

struct student//ѧ����Ϣ��ʽ
{
	char snumber[LEN];
	char name[LEN];
	char sex[3];
	float score[3];
}st[N];

int k = 1, n = 0, m = 0;//kλ���ƿ��ص�ֵ��n��¼���ѧ����������m��Ҫ���ӵ�����
void insert();//������Ϣ
void erase();//ɾ����Ϣ
void seek();//������Ϣ
void modify();//������Ϣ
void statistic();//ͳ�Ƴɼ�
void outfile();//������Ϣ
void menu();//�˵�����
void fresh();//ˢ����Ϣ��ȷ��n��ֵ

int main()
{
	//fresh();
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}

void menu()//�˵����棬����ѡ��
{
	printf("*******************************************\n");
	printf("**************�ɼ�����ϵͳ*****************\n");
	printf("*******1.������Ϣ*****2.������Ϣ***********\n");
	printf("*******3.ɾ����Ϣ*****4.�޸���Ϣ***********\n");
	printf("*******5.��ѯ��Ϣ*****6.ͳ�Ƴɼ�***********\n");
	printf("*******7.�˳�ϵͳ*****8.ˢ����Ϣ***********\n");
	printf("please input your options:");
	int num;
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		outfile();
		break;
	case 2:
		insert();
		break;
	case 3:
		fresh();
		erase();
		break;
	case 4:
		fresh();
		modify();
		break;
	case 5:
		fresh();
		seek();
		break;
	case 6:
		fresh();
		statistic();
		break;
	case 7:
		k = 0;
		break;
	case 8:
		fresh();
		break;
	default:
		printf("����������");
	}
}

void outfile()//¼����Ϣ��ÿ�β������Ϣд���ļ�
{
	int i;
	FILE * fp;
	fp = fopen("D:/test/student.txt", "w");
	for (i = 0; i<n; i++)
	{
		fprintf(fp, "%s %s %s %3.1f %3.1f %3.1f \n", st[i].snumber, st[i].name, st[i].sex, st[i].score[0], st[i].score[1], st[i].score[2]);
	}
	fclose(fp);
}

void insert()//������Ϣ
{
	int j = m;
	printf("����Ҫ���ӵ�����:");
	scanf("%d", &m);
	if (m == 0)
	{
		return;
	}
	do
	{
		printf("����ѧ����ѧ�ţ�");
		scanf("%s", st[j].snumber);
		printf("����ѧ����������");
		scanf("%s", st[j].name);
		printf("����ѧ�����Ա�");
		scanf("%s", &st[j].sex);
		printf("����ѧ����������۵ĳɼ���");
		scanf("%f", &st[j].score[0]);
		printf("����ѧ���ߵ���ѧ�ĳɼ���");
		scanf("%f", &st[j].score[1]);
		printf("����ѧ����ѧӢ��ĳɼ���");
		scanf("%f", &st[j].score[2]);
		j++;
	}
	while (j<n + m);
	n += m;
	printf("��Ϣ������");
}

void seek()//����ѧ������Ϣ
{
	char store[LEN];
	printf("����Ҫ���ҵ�ѧ��:");
	scanf("%s", &store);
	FILE* fp;
	fp = fopen("D:/test/student.txt", "r");
	char buff[LEN];
	char output[100];
	int tag = 0;					//���
	for (int i = 0; i < n; i++)
	{
		memset(buff, 0, LEN);
		fgets(output, 100, fp);		//��һ����Ϣд��һ��������
		int j = 0;
		while (output[j] != ' ')	//��������Ϣ��ѧ�Ų����ó���
		{
			buff[j] = output[j];
			j++;
		}
		buff[j] = '\0';
		//fseek(fp, (i * 37), SEEK_SET);
		//fscanf(fp, "%s", &buff);
		if (strcmp(store, buff) == 0)//�ж�ѧ���Ƿ���ͬ
		{
			//fgets(output, 53, (FILE*)fp);
			printf("    ѧ��    ���� �Ա� ��������� �ߵ���ѧ ��ѧӢ��\n");
			printf("%s", output);
			tag = 1;			//�ҵ�������Ϊ1
		}
	}
	if (tag == 0)		//�����ǲ��䣬��û��Ҫ�ҵ�ѧ��
	{
		printf_s("ѧ�Ų�����",sizeof("ѧ�Ų�����"));
	}
	fclose(fp);
}

void erase()
{
	char store[LEN];
	printf("����Ҫɾ����ѧ��:");
	scanf("%s", &store);
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("D:/test/student.txt", "r");
	fp2 = fopen("D:/test/temp.txt", "w+");//������ʱ�ļ�
	char buff[LEN];
	char output[100];
	for (int i = 0; i < n; i++)
	{
		//fseek(fp1, (i * 37), SEEK_SET);
		memset(buff, 0, LEN);
		fgets(output, 100, fp1);
		/*strncpy(buff, output, 12);
		buff[12] = '\0';*/
		int j = 0;
		while (output[j] != ' ')
		{
			buff[j] = output[j];
			j++;
		}
		buff[j] = '\0';
		if (strcmp(store, buff) != 0)
		{
			//fseek(fp1, (i * 37), SEEK_SET);
			//fgets(output, 100, fp1);
			fprintf(fp2, output);		//���ѧ�Ų���Ҫɾ���ģ����ַ���д����ʱ�ļ�
		}
		else
		{
			continue;
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("D:/test/student.txt");
	rename("D:/test/temp.txt", "D:/test/student.txt");//ɾ�����ļ�������ʱ�ļ�����
	n--;
}

void modify()
{
	char store[LEN];
	printf("����Ҫ�޸ĵ�ѧ��:");
	scanf("%s", &store);
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("D:/test/student.txt", "r");
	fp2 = fopen("D:/test/tep.txt", "w+");
	char buff[LEN];
	char output[100];
	for (int i = 0; i < n; i++)
	{
		memset(buff, 0, LEN);
		fgets(output, 100, fp1);		//��һ����Ϣд��һ��������
		int j = 0;
		while (output[j] != ' ')	//��������Ϣ��ѧ�Ų����ó���
		{
			buff[j] = output[j];
			j++;
		}
		buff[j] = '\0';
		if (strcmp(store, buff) != 0)
		{
			//fseek(fp1, (i * 37), SEEK_SET);
			//fgets(output, 52, fp1);
			fprintf(fp2, output);
		}
		else
		{
			continue;
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("D:/test/student.txt");
	rename("D:/test/tep.txt", "D:/test/student.txt");
	n--;


		strcpy(st[0].snumber, store);
		printf("����ѧ����������");
		scanf("%s", st[0].name);
		printf("����ѧ�����Ա�");
		scanf("%s", &st[0].sex);
		printf("����ѧ����������۵ĳɼ���");
		scanf("%f", &st[0].score[0]);
		printf("����ѧ���ߵ���ѧ�ĳɼ���");
		scanf("%f", &st[0].score[1]);
		printf("����ѧ����ѧӢ��ĳɼ���");
		scanf("%f", &st[0].score[2]);
	    n++;
		FILE * fp;
		fp = fopen("D:/test/student.txt", "a+");
		
			fprintf(fp, "%s %s %s %3.1f %3.1f %3.1f \n", st[0].snumber, st[0].name, st[0].sex, st[0].score[0], st[0].score[1], st[0].score[2]);
		fclose(fp);
	printf_s("��Ϣ���޸�",sizeof("��Ϣ���޸�"));
}

void statistic()
{
	char store[LEN];
	printf("����Ҫͳ��ƽ���ֵ�ѧ��:");
	scanf("%s", &store);
	FILE* fp;
	fp = fopen("D:/test/student.txt", "r");
	char buff[LEN];
	char output[100];
	float avg;
	for (int i = 0; i < n; i++)
	{
		memset(buff, 0, LEN);
		fgets(output, 100, fp);		//��һ����Ϣд��һ��������
		int j = 0;
		while (output[j] != ' ')	//��������Ϣ��ѧ�Ų����ó���
		{
			buff[j] = output[j];
			j++;
		}
		buff[j] = '\0';
		if (strcmp(store, buff) == 0)//���ó�����Ϣ����Ҫͳ�Ƶ�ѧ�ŵ���Ϣ�Ƚϣ�����ͬ������ͳ��
		{
			float a, b, c;
			fseek(fp, -17, SEEK_CUR);
			fscanf(fp, "%f", &a);
			fscanf(fp, "%f", &b);
			fscanf(fp, "%f", &c);
			avg = (a + b + c) / 3;
			printf("%3.1f", avg);
		}
	}
	fclose(fp);
}

void fresh()//ˢ����Ϣ
{
	n = 0;
	FILE* fp;
	int ch;
	fp = fopen("D:/test/student.txt", "r");
	if (fp == NULL)
	{
		exit(0);
		//return;
	}
	else
	{
		ch = fgetc(fp);
		char buff[100];
		if (ch != EOF)//�ж��ļ��Ƿ�Ϊ��
		{
			fseek(fp, 0, SEEK_SET);
			while (1)					//�ļ�ÿ��1�У�n��1
			{
				memset(buff, 0, 100);
				fgets(buff, 100, fp);
				if (buff[0] != '\0')
				{
					n++;
					memset(buff, 0, 100);
				}
				else
				{
					break;
				}
			}
		}
	}
	fclose(fp);
}




