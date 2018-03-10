#include<stdio.h>   /*I/O函数*/
#include<stdlib.h>  /*其它说明*/
#include<string.h>  /*字符串函数*/
#define LEN 15      /* 学号和姓名最大字符数,实际请更改*/
#define N 50        /* 最大学生人数,实际请更改*/
struct Student
{
 char code[LEN];    /* 学号*/
 char name[LEN];    /* 姓名*/
 int age;           /* 年龄*/
 char sex[3];       /* 性别*/
 float score[3];     /* 3门课程成绩*/
}Stud[N];


int k=1,n=0, m=0;/* n代表当前记录的学生人数*/
void seek();  /*查找*/
void modify();  /*修改信息*/
void insert();  /*插入函数*/
void del();    /*删除函数*/
void outfile(); /*存储信息*/
void freshen(); /*刷新信息*/
void display(); /*显示信息*/
void menu();   /*主界面*/
int main()
{
    while(k)
    {
        menu();
    }
    system("pause");
    return 0;
}

void outfile() /*存储当前信息*/
{
    int i;
    FILE *fp;
    fp=fopen("Studdent.txt","w");    /*用fopen函数打开数据文件*/
    for(i=0;i<n;i++)
     {
        fprintf(fp,"%7s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,Stud[i].name,Stud[i].age,
                        Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
     }
     fclose(fp);      /*用fclose函数关闭数据文件*/
}

void help()  /*帮助菜单*/
{
    printf("\n0.欢迎使用系统帮助！\n");
    printf("\n1.初次进入系统后,请先选择增加学生信息;\n");
    printf("\n2.按照菜单提示键入数字代号;\n");
    printf("\n3.增加学生信息后,切记保存;\n");
    printf("\n4.谢谢您的使用！\n");
}


void seek() /*查找*/
{
    int i,item,flag;
    char s1[21]; /* 以姓名和学号最长长度+1为准*/
    printf("------------------\n");
    printf("-----1.按学号查询-----\n");
    printf("-----2.按姓名查询-----\n");
    printf("-----3.退出本菜单-----\n");
    printf("------------------\n");
    while(1)
    {
        printf("请选择子菜单编号:");
        scanf("%d",&item);
        flag=0;
        switch(item)
        {
        case 1:
            printf("请输入要查询的学生的学号:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(Stud[i].code,s1)==0)
                {
                    flag=1;
                    printf("学生学号    学生姓名  年龄   性别  C语言成绩  高等数学  大学英语成绩\n");
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,Stud[i].name,Stud[i].age,
                        Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
                }
                if(0==flag)
                    printf("该学号不存在！\n"); break;
        case 2:
            printf("请输入要查询的学生的姓名:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(Stud[i].name,s1)==0)
                {
                    flag=1;
                    printf("学生学号    学生姓名  年龄   性别  C语言成绩  高等数学  大学英语成绩\n");
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,Stud[i].name,Stud[i].age,
                        Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
                }
                    if(0==flag)
                        printf("该姓名不存在！\n"); break;
        case 3:return;
        default:printf("请在1-3之间选择\n");
        }
    }
}


void modify() /*修改信息*/
{
    int i,item,num;
    char sex1[3],s1[LEN+1],s2[LEN+1]; /* 以姓名和学号最长长度+1为准*/
    float score1;
    printf("请输入要要修改的学生的学号:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(Stud[i].code,s1)==0) /*比较字符串是否相等*/
            num=i;
        printf("------------------\n");
        printf("1.修改姓名\n");
        printf("2.修改年龄\n");
        printf("3.修改性别\n");
        printf("4.修改C语言成绩\n");
        printf("5.修改高等数学成绩\n");
        printf("6.修改大学英语成绩\n");
        printf("7.退出本菜单\n");
        printf("------------------\n");
        while(1)
        {
            printf("请选择子菜单编号:");
            scanf("%d",&item);
            switch(item)
            {
            case 1:
                printf("请输入新的姓名:\n");
                scanf("%s",s2);
                strcpy(Stud[num].name,s2); break;
            case 2:
                printf("请输入新的年龄:\n");
                scanf("%d",Stud[num].age);break;
            case 3:
                printf("请输入新的性别:\n");
                scanf("%c",&sex1);
                strcpy(Stud[num].sex,sex1); break;
            case 4:
                printf("请输入新的C语言成绩:\n");
                scanf("%f",&score1);
                Stud[num].score[0]=score1; break;
            case 5:
                printf("请输入新的高等数学成绩:\n");
                scanf("%f",&score1);
                Stud[num].score[1]=score1; break;
            case 6:
                printf("请输入新的大学英语成绩:\n");
                scanf("%f",&score1);
                Stud[num].score[2]=score1; break;
            case 7: return;
            default:printf("请在1-7之间选择\n");
            }
        }
}


void sort()/*按学号排序*/
{
    int i,j,k,*p,*q,s;
    char temp[LEN+1];
    float ftemp;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
            if(strcmp(Stud[j-1].code,Stud[j].code)>0)
            {
                strcpy(temp,Stud[j-1].code);
                strcpy(Stud[j-1].code,Stud[j].code);
                strcpy(Stud[j].code,temp);
                strcpy(temp,Stud[j-1].name);
                strcpy(Stud[j-1].name,Stud[j].name);
                strcpy(Stud[j].name,temp);
                strcpy(temp,Stud[j-1].sex);
                strcpy(Stud[j].sex,temp);
                p=&Stud[j-1].age;
                q=&Stud[j].age;
                s=*q;
                *q=*p;
                *p=s;
                for(k=0;k<3;k++)
                {
                    ftemp=Stud[j-1].score[k];
                    Stud[j-1].score[k]=Stud[j].score[k];
                    Stud[j].score[k]=ftemp;
                }
            }
    }
}

void insert() /*插入函数*/
{
    int j=n;

    printf("请输入待增加的学生数:\n");
    scanf("%d",&m);
    do
    {

        printf("请输入第%d 个学生的学号:\n",j-n+1);
        scanf("%s",Stud[j].code);
        printf("请输入第%d 个学生的姓名:\n",j-n+1);
        scanf("%s",Stud[j].name);
        printf("请输入第%d 个学生的年龄:\n",j-n+1);
        scanf("%d",&Stud[j].age);
        printf("请输入第%d 个学生的性别:\n",j-n+1);
        scanf(" %s",&Stud[j].sex);
        printf("请输入第%d 个学生的C语言成绩\n",j-n+1);
        scanf("%f",&Stud[j].score[0]);
        printf("请输入第%d 个学生的高等数学成绩:\n",j-n+1);
        scanf("%f",&Stud[j].score[1]);
        printf("请输入第%d 个学生的大学英语成绩:\n",j-n+1);
        scanf("%f",&Stud[j].score[2]);

    j++;
    }while(j<n+m);
    n+=m;
    printf("信息增加完毕！\n\n");
    sort();
}

void del()  /*删除函数*/
{
    int i,j,flag=0;
    char s1[LEN+1];
    printf("请输入要删除学生的学号:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(Stud[i].code,s1)==0)
        {
            flag=1;
            for(j=i;j<n-1;j++)
            Stud[j]=Stud[j+1];

        }
        if(flag==0)
            printf("该学号不存在！\n");
        if(flag==1)
        {
            printf("删除成功,显示结果请选择菜单\n");
            n--;
        }
}


void display()  /*显示当前信息*/
{
    int i;
    printf("共有%d位学生的信息:\n",n);
    if(0!=n)
    {
        printf("学生学号  学生姓名 年龄  性别  C语言成绩  高等数学  大学英语成绩\n");
        printf("--------------------------------------------------------------------\n");
        for(i=0;i<n;i++)
        {
            printf("%7s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,
        Stud[i].name,Stud[i].age,Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
        }
    }
}




void freshen() /*刷新信息*/
{
}


void menu()/* 界面*/
{
    int num;
    printf(" \n\n                    \n\n");
    printf("  ******************************************************\n\n");
    printf("  *                学生信息管理系统                    *\n \n");
    printf("  ******************************************************\n\n");
    printf("*********************系统功能菜单*************************       \n");
    printf("     ----------------------   ----------------------   \n");
    printf("     *********************************************     \n");
    printf("     * 0.系统帮助及说明  * *  1.刷新学生信息   *     \n");
    printf("     *********************************************     \n");
    printf("     * 2.查询学生信息    * *  3.修改学生信息   *     \n");
    printf("     *********************************************     \n");
    printf("     * 4.增加学生信息    * *  5.按学号删除信息 *     \n");
    printf("     *********************************************     \n");
    printf("     * 6.显示当前信息    * *  7.保存当前学生信息*     \n");
    printf("     ********************** **********************     \n");
    printf("     * 8.退出系统        *                            \n");
    printf("     **********************                            \n");
    printf("     ----------------------   ----------------------                           \n");
    printf("请选择菜单编号:");
    scanf("%d",&num);
    switch(num)
    {
    case 0:help();break;
    case 1:freshen();break;
    case 2:seek();break;
    case 3:modify();break;
    case 4:insert();break;
    case 5:del();break;
    case 6:display();break;
    case 7:outfile();break;
    case 8:k=0;break;
    default:printf("请在0-8之间选择\n");
    }
}
