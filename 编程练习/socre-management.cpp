#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 15
#define N 15

struct Student
{
    char snumber[LEN];
    char name[LEN];
    char sex[3];
    float score[3];
}St[N];

int k=1,n=0,m=0;
void outfile();
void insert();
void erase();
void change();
void seek();
void statistic();
void display();
void menu();

int main()
{
    while(k)
    {
        menu();
    }
    system("pause");
    return 0;
}

void outfile()/*存储信息*/
{
    int i;
    FILE * fp;
    fp=fopen("D:/test/student.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s %s %s %10.1f %10.1f %10.1f \n",St[i].snumber,St[i].name,St[i].sex,St[i].score[0],St[i].score[1],St[i].score[2]);
    }
    fclose(fp);
}

void sort()/*按学号排序*/
{
    char store[LEN];
    int w=0;
    for(int i=0;i<n-1;i++)
    {
        strcpy(store,St[i].snumber);
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(store,St[j].snumber)>0)
            {
                strcpy(store,St[j].snumber);
                w=j;
            }
        }
        strcpy(St[w].snumber,St[i].snumber);
        strcpy(St[i].snumber,store);
        w=0;
    }
}


void insert()/*插入信息*/
{
    int j=n;
    printf("输入要增加的学生的数量");
    scanf("%d",&m);
    if(m==0)
    {
        return;
    }
    do
    {
        printf("输入学生的学号：");
        scanf("%s",St[j].snumber);
        printf("输入学生的姓名：");
        scanf("%s",St[j].name);
        printf("输入学生的性别：");
        scanf("%s",&St[j].sex);
        printf("输入学生计算机导论的成绩：");
        scanf("%f",&St[j].score[0]);
        printf("输入学生高等数学的成绩：");
        scanf("%f",&St[j].score[1]);
        printf("输入学生线性代数的成绩：");
        scanf("%f",&St[j].score[2]);
        j++;
    }
    while(j<n+m);
    n+=m;
    printf("信息已增加");
    sort();
}

void erase()
{

}

void change()
{

}

void seek()
{
    while(1)
    {
        int sign=0;
        printf("输入要查找的学号：");
        char temp[LEN];
        scanf("%s",&temp);
        for(int i=0;i<n;i++)
        {
            if(strcmp(temp,St[i].snumber)==0)
            {
                printf("学号  姓名  性别  计算导论成绩  高等数学成绩  线性代数成绩\n");
                printf("%s %7s %7s %10.1f %10.1f %10.1f \n",St[i].snumber,St[i].name,St[i].sex,St[i].score[0],St[i].score[1],St[i].score[2]);
                sign=1;
            }
        }
        if(sign==0)
            {
                printf("学号不存在");
                break;
            }
    }
    char fy;
    printf("是否退出（y/n）?");
    scanf("%c",&fy);
    if(fy=='y')
    {
        return;
    }
    if(fy=='n')
    {
        seek();
    }
}

void statistic()
{

}

void display()
{

}


void menu()/*菜单界面*/
{
    printf("*******************************************\n");
    printf("**************成绩管理系统*****************\n");
    printf("*******1.保存信息*****2.插入信息***********\n");
    printf("*******3.删除信息*****4.修改信息***********\n");
    printf("*******5.查询信息*****6.统计成绩***********\n");
    printf("**************7.退出系统*******************\n");
    printf("please input your options:");
    int num;
    scanf("%d",&num);
    switch(num)
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
            change();
            break;
        case 5:
            seek();
            break;
        case 6:
            statistic();
            break;
        case 7:
            k=0;
            break;
        default:
            printf("error!please input again:");
            scanf("%d",&num);
    }
}
