#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <cstdlib>
#define LEN 15
#define N 15

struct student
{
	char snumber[LEN];
	char name[LEN];
	char sex[3];
	float score[3];
}st[N];

int k = 1, n = 0, m = 0;
void insert();//插入信息
void erase();//删除信息
void seek();//查找信息
void modify();//更改信息
void statistic();//统计成绩
void outfile();//保存信息
void menu();//菜单界面

int main()
{
	while (k)
	{
		menu();
	}
	system("pause");
	return 0;
}

void menu()
{
	printf("*******************************************\n");
	printf("**************成绩管理系统*****************\n");
	printf("*******1.保存信息*****2.插入信息***********\n");
	printf("*******3.删除信息*****4.修改信息***********\n");
	printf("*******5.查询信息*****6.统计成绩***********\n");
	printf("**************7.退出系统*******************\n");
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
		erase();
		break;
	case 4:
		modify();
		break;
	case 5:
		seek();
		break;
	case 6:
		statistic();
		break;
	case 7:
		k = 0;
		break;
	default:
		printf("请重新输入");
	}
}

void outfile()
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

void insert()
{
	int j = m;
	printf("输入要增加的数量:");
	scanf("%d", &m);
	if (m == 0)
	{
		return;
	}
	do
	{
		printf("输入学生的学号：");
		scanf("%s", st[j].snumber);
		printf("输入学生的姓名：");
		scanf("%s", st[j].name);
		printf("输入学生的性别：");
		scanf("%s", &st[j].sex);
		printf("输入学生计算机导论的成绩：");
		scanf("%f", &st[j].score[0]);
		printf("输入学生高等数学的成绩：");
		scanf("%f", &st[j].score[1]);
		printf("输入学生线性代数的成绩：");
		scanf("%f", &st[j].score[2]);
		j++;
	}
	while (j<n + m);
	n += m;
	printf("信息已增加");
}

void seek()
{
	char store[LEN];
	printf("输入要查找的学号:");
	scanf("%s", &store);
	FILE* fp;
	fp = fopen("D:/test/student.txt", "r");
	char buff[LEN];
	char output[53];
	int tag = 0;
	for (int i = 0; i < n; i++)
	{
		fseek(fp, (i * 37), SEEK_SET);
		fscanf(fp, "%s", &buff);
		if (strcmp(store, buff) == 0)
		{
			fgets(output, 53, (FILE*)fp);
			printf("%s", output);
			tag = 1;
		}
	}
	if (tag == 0)
	{
		printf_s("学号不存在",sizeof("学号不存在"));
	}
	fclose(fp);
}

void erase()
{
	char store[LEN];
	printf("输入要删除的学号:");
	scanf("%s", &store);
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("D:/test/student.txt", "r");
	fp2 = fopen("D:/test/temp.txt", "w+");
	char buff[LEN];
	char output[52];
	for (int i = 0; i < n; i++)
	{
		fseek(fp1, (i * 37), SEEK_SET);
		fgets(buff, 13, fp1);
		if (strcmp(store, buff) != 0)
		{
			fseek(fp1, (i * 37), SEEK_SET);
			fgets(output, 52, fp1);
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
	rename("D:/test/temp.txt", "D:/test/student.txt");
	n--;
}

void modify()
{
	char store[LEN];
	printf("输入要修改的学号:");
	scanf("%s", &store);
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("D:/test/student.txt", "r");
	fp2 = fopen("D:/test/tep.txt", "w");
	char buff[LEN];
	char output[52];
	for (int i = 0; i < n; i++)
	{
		fseek(fp1, (i * 37), SEEK_SET);
		fgets(buff, 13, fp1);
		if (strcmp(store, buff) != 0)
		{
			fseek(fp1, (i * 37), SEEK_SET);
			fgets(output, 52, fp1);
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


		printf("输入学生的学号：");
		scanf("%s", st[0].snumber);
		printf("输入学生的姓名：");
		scanf("%s", st[0].name);
		printf("输入学生的性别：");
		scanf("%s", &st[0].sex);
		printf("输入学生计算机导论的成绩：");
		scanf("%f", &st[0].score[0]);
		printf("输入学生高等数学的成绩：");
		scanf("%f", &st[0].score[1]);
		printf("输入学生线性代数的成绩：");
		scanf("%f", &st[0].score[2]);
	    n++;
		FILE * fp;
		fp = fopen("D:/test/student.txt", "a+");
		
			fprintf(fp, "%s %s %s %3.1f %3.1f %3.1f \n", st[0].snumber, st[0].name, st[0].sex, st[0].score[0], st[0].score[1], st[0].score[2]);
		fclose(fp);
	printf_s("信息已修改",sizeof("信息已修改"));
}

void statistic()
{
	char store[LEN];
	printf("输入要统计平均分的学号:");
	scanf("%s", &store);
	FILE* fp;
	fp = fopen("D:/test/student.txt", "r");
	char buff[LEN];
	float avg;
	for (int i = 0; i < n; i++)
	{
		fseek(fp, i * 37, SEEK_SET);
		fscanf(fp, "%s", &buff);
		if (strcmp(store, buff) == 0)
		{
			float a, b, c;
			fseek(fp, (i * 37 + 20), SEEK_SET);
			fscanf(fp, "%f", &a);
			fscanf(fp, "%f", &b);
			fscanf(fp, "%f", &c);
			avg = (a + b + c) / 3;
			printf("%3.1f", avg);
		}
	}
	fclose(fp);
}




