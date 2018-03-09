#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <cstdlib>
#define LEN 15
#define N 15

struct student//学生信息格式
{
	char snumber[LEN];
	char name[LEN];
	char sex[3];
	float score[3];
}st[N];

int k = 1, n = 0, m = 0;//k位控制开关的值，n是录入的学生的数量，m是要增加的数量
void insert();//插入信息
void erase();//删除信息
void seek();//查找信息
void modify();//更改信息
void statistic();//统计成绩
void outfile();//保存信息
void menu();//菜单界面
void fresh();//刷新信息，确定n的值

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

void menu()//菜单界面，包含选项
{
	printf("*******************************************\n");
	printf("**************成绩管理系统*****************\n");
	printf("*******1.保存信息*****2.插入信息***********\n");
	printf("*******3.删除信息*****4.修改信息***********\n");
	printf("*******5.查询信息*****6.统计成绩***********\n");
	printf("*******7.退出系统*****8.刷新信息***********\n");
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
		printf("请重新输入");
	}
}

void outfile()//录入信息，每次插入后将信息写入文件
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

void insert()//插入信息
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
		printf("输入学生大学英语的成绩：");
		scanf("%f", &st[j].score[2]);
		j++;
	}
	while (j<n + m);
	n += m;
	printf("信息已增加");
}

void seek()//查找学生的信息
{
	char store[LEN];
	printf("输入要查找的学号:");
	scanf("%s", &store);
	FILE* fp;
	fp = fopen("D:/test/student.txt", "r");
	char buff[LEN];
	char output[100];
	int tag = 0;					//标记
	for (int i = 0; i < n; i++)
	{
		memset(buff, 0, LEN);
		fgets(output, 100, fp);		//将一行信息写入一个数组中
		int j = 0;
		while (output[j] != ' ')	//将这行信息的学号部分拿出来
		{
			buff[j] = output[j];
			j++;
		}
		buff[j] = '\0';
		//fseek(fp, (i * 37), SEEK_SET);
		//fscanf(fp, "%s", &buff);
		if (strcmp(store, buff) == 0)//判断学号是否相同
		{
			//fgets(output, 53, (FILE*)fp);
			printf("    学号    姓名 性别 计算机导论 高等数学 大学英语\n");
			printf("%s", output);
			tag = 1;			//找到后标记设为1
		}
	}
	if (tag == 0)		//如果标记不变，则没有要找的学生
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
	fp2 = fopen("D:/test/temp.txt", "w+");//创建临时文件
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
			fprintf(fp2, output);		//如果学号不是要删除的，将字符串写入临时文件
		}
		else
		{
			continue;
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("D:/test/student.txt");
	rename("D:/test/temp.txt", "D:/test/student.txt");//删除旧文件，将临时文件更名
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
	fp2 = fopen("D:/test/tep.txt", "w+");
	char buff[LEN];
	char output[100];
	for (int i = 0; i < n; i++)
	{
		memset(buff, 0, LEN);
		fgets(output, 100, fp1);		//将一行信息写入一个数组中
		int j = 0;
		while (output[j] != ' ')	//将这行信息的学号部分拿出来
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
		printf("输入学生的姓名：");
		scanf("%s", st[0].name);
		printf("输入学生的性别：");
		scanf("%s", &st[0].sex);
		printf("输入学生计算机导论的成绩：");
		scanf("%f", &st[0].score[0]);
		printf("输入学生高等数学的成绩：");
		scanf("%f", &st[0].score[1]);
		printf("输入学生大学英语的成绩：");
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
	char output[100];
	float avg;
	for (int i = 0; i < n; i++)
	{
		memset(buff, 0, LEN);
		fgets(output, 100, fp);		//将一行信息写入一个数组中
		int j = 0;
		while (output[j] != ' ')	//将这行信息的学号部分拿出来
		{
			buff[j] = output[j];
			j++;
		}
		buff[j] = '\0';
		if (strcmp(store, buff) == 0)//将拿出的信息和需要统计的学号的信息比较，若相同，进行统计
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

void fresh()//刷新信息
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
		if (ch != EOF)//判断文件是否为空
		{
			fseek(fp, 0, SEEK_SET);
			while (1)					//文件每有1行，n加1
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




