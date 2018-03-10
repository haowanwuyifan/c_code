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

void outfile()/*�洢��Ϣ*/
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

void sort()/*��ѧ������*/
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


void insert()/*������Ϣ*/
{
    int j=n;
    printf("����Ҫ���ӵ�ѧ��������");
    scanf("%d",&m);
    if(m==0)
    {
        return;
    }
    do
    {
        printf("����ѧ����ѧ�ţ�");
        scanf("%s",St[j].snumber);
        printf("����ѧ����������");
        scanf("%s",St[j].name);
        printf("����ѧ�����Ա�");
        scanf("%s",&St[j].sex);
        printf("����ѧ����������۵ĳɼ���");
        scanf("%f",&St[j].score[0]);
        printf("����ѧ���ߵ���ѧ�ĳɼ���");
        scanf("%f",&St[j].score[1]);
        printf("����ѧ�����Դ����ĳɼ���");
        scanf("%f",&St[j].score[2]);
        j++;
    }
    while(j<n+m);
    n+=m;
    printf("��Ϣ������");
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
        printf("����Ҫ���ҵ�ѧ�ţ�");
        char temp[LEN];
        scanf("%s",&temp);
        for(int i=0;i<n;i++)
        {
            if(strcmp(temp,St[i].snumber)==0)
            {
                printf("ѧ��  ����  �Ա�  ���㵼�۳ɼ�  �ߵ���ѧ�ɼ�  ���Դ����ɼ�\n");
                printf("%s %7s %7s %10.1f %10.1f %10.1f \n",St[i].snumber,St[i].name,St[i].sex,St[i].score[0],St[i].score[1],St[i].score[2]);
                sign=1;
            }
        }
        if(sign==0)
            {
                printf("ѧ�Ų�����");
                break;
            }
    }
    char fy;
    printf("�Ƿ��˳���y/n��?");
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


void menu()/*�˵�����*/
{
    printf("*******************************************\n");
    printf("**************�ɼ�����ϵͳ*****************\n");
    printf("*******1.������Ϣ*****2.������Ϣ***********\n");
    printf("*******3.ɾ����Ϣ*****4.�޸���Ϣ***********\n");
    printf("*******5.��ѯ��Ϣ*****6.ͳ�Ƴɼ�***********\n");
    printf("**************7.�˳�ϵͳ*******************\n");
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
