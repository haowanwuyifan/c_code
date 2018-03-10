#include<stdio.h>   /*I/O����*/
#include<stdlib.h>  /*����˵��*/
#include<string.h>  /*�ַ�������*/
#define LEN 15      /* ѧ�ź���������ַ���,ʵ�������*/
#define N 50        /* ���ѧ������,ʵ�������*/
struct Student
{
 char code[LEN];    /* ѧ��*/
 char name[LEN];    /* ����*/
 int age;           /* ����*/
 char sex[3];       /* �Ա�*/
 float score[3];     /* 3�ſγ̳ɼ�*/
}Stud[N];


int k=1,n=0, m=0;/* n����ǰ��¼��ѧ������*/
void seek();  /*����*/
void modify();  /*�޸���Ϣ*/
void insert();  /*���뺯��*/
void del();    /*ɾ������*/
void outfile(); /*�洢��Ϣ*/
void freshen(); /*ˢ����Ϣ*/
void display(); /*��ʾ��Ϣ*/
void menu();   /*������*/
int main()
{
    while(k)
    {
        menu();
    }
    system("pause");
    return 0;
}

void outfile() /*�洢��ǰ��Ϣ*/
{
    int i;
    FILE *fp;
    fp=fopen("Studdent.txt","w");    /*��fopen�����������ļ�*/
    for(i=0;i<n;i++)
     {
        fprintf(fp,"%7s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,Stud[i].name,Stud[i].age,
                        Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
     }
     fclose(fp);      /*��fclose�����ر������ļ�*/
}

void help()  /*�����˵�*/
{
    printf("\n0.��ӭʹ��ϵͳ������\n");
    printf("\n1.���ν���ϵͳ��,����ѡ������ѧ����Ϣ;\n");
    printf("\n2.���ղ˵���ʾ�������ִ���;\n");
    printf("\n3.����ѧ����Ϣ��,�мǱ���;\n");
    printf("\n4.лл����ʹ�ã�\n");
}


void seek() /*����*/
{
    int i,item,flag;
    char s1[21]; /* ��������ѧ�������+1Ϊ׼*/
    printf("------------------\n");
    printf("-----1.��ѧ�Ų�ѯ-----\n");
    printf("-----2.��������ѯ-----\n");
    printf("-----3.�˳����˵�-----\n");
    printf("------------------\n");
    while(1)
    {
        printf("��ѡ���Ӳ˵����:");
        scanf("%d",&item);
        flag=0;
        switch(item)
        {
        case 1:
            printf("������Ҫ��ѯ��ѧ����ѧ��:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(Stud[i].code,s1)==0)
                {
                    flag=1;
                    printf("ѧ��ѧ��    ѧ������  ����   �Ա�  C���Գɼ�  �ߵ���ѧ  ��ѧӢ��ɼ�\n");
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,Stud[i].name,Stud[i].age,
                        Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
                }
                if(0==flag)
                    printf("��ѧ�Ų����ڣ�\n"); break;
        case 2:
            printf("������Ҫ��ѯ��ѧ��������:\n");
            scanf("%s",s1);
            for(i=0;i<n;i++)
                if(strcmp(Stud[i].name,s1)==0)
                {
                    flag=1;
                    printf("ѧ��ѧ��    ѧ������  ����   �Ա�  C���Գɼ�  �ߵ���ѧ  ��ѧӢ��ɼ�\n");
                    printf("--------------------------------------------------------------------\n");
                    printf("%6s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,Stud[i].name,Stud[i].age,
                        Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
                }
                    if(0==flag)
                        printf("�����������ڣ�\n"); break;
        case 3:return;
        default:printf("����1-3֮��ѡ��\n");
        }
    }
}


void modify() /*�޸���Ϣ*/
{
    int i,item,num;
    char sex1[3],s1[LEN+1],s2[LEN+1]; /* ��������ѧ�������+1Ϊ׼*/
    float score1;
    printf("������ҪҪ�޸ĵ�ѧ����ѧ��:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(Stud[i].code,s1)==0) /*�Ƚ��ַ����Ƿ����*/
            num=i;
        printf("------------------\n");
        printf("1.�޸�����\n");
        printf("2.�޸�����\n");
        printf("3.�޸��Ա�\n");
        printf("4.�޸�C���Գɼ�\n");
        printf("5.�޸ĸߵ���ѧ�ɼ�\n");
        printf("6.�޸Ĵ�ѧӢ��ɼ�\n");
        printf("7.�˳����˵�\n");
        printf("------------------\n");
        while(1)
        {
            printf("��ѡ���Ӳ˵����:");
            scanf("%d",&item);
            switch(item)
            {
            case 1:
                printf("�������µ�����:\n");
                scanf("%s",s2);
                strcpy(Stud[num].name,s2); break;
            case 2:
                printf("�������µ�����:\n");
                scanf("%d",Stud[num].age);break;
            case 3:
                printf("�������µ��Ա�:\n");
                scanf("%c",&sex1);
                strcpy(Stud[num].sex,sex1); break;
            case 4:
                printf("�������µ�C���Գɼ�:\n");
                scanf("%f",&score1);
                Stud[num].score[0]=score1; break;
            case 5:
                printf("�������µĸߵ���ѧ�ɼ�:\n");
                scanf("%f",&score1);
                Stud[num].score[1]=score1; break;
            case 6:
                printf("�������µĴ�ѧӢ��ɼ�:\n");
                scanf("%f",&score1);
                Stud[num].score[2]=score1; break;
            case 7: return;
            default:printf("����1-7֮��ѡ��\n");
            }
        }
}


void sort()/*��ѧ������*/
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

void insert() /*���뺯��*/
{
    int j=n;

    printf("����������ӵ�ѧ����:\n");
    scanf("%d",&m);
    do
    {

        printf("�������%d ��ѧ����ѧ��:\n",j-n+1);
        scanf("%s",Stud[j].code);
        printf("�������%d ��ѧ��������:\n",j-n+1);
        scanf("%s",Stud[j].name);
        printf("�������%d ��ѧ��������:\n",j-n+1);
        scanf("%d",&Stud[j].age);
        printf("�������%d ��ѧ�����Ա�:\n",j-n+1);
        scanf(" %s",&Stud[j].sex);
        printf("�������%d ��ѧ����C���Գɼ�\n",j-n+1);
        scanf("%f",&Stud[j].score[0]);
        printf("�������%d ��ѧ���ĸߵ���ѧ�ɼ�:\n",j-n+1);
        scanf("%f",&Stud[j].score[1]);
        printf("�������%d ��ѧ���Ĵ�ѧӢ��ɼ�:\n",j-n+1);
        scanf("%f",&Stud[j].score[2]);

    j++;
    }while(j<n+m);
    n+=m;
    printf("��Ϣ������ϣ�\n\n");
    sort();
}

void del()  /*ɾ������*/
{
    int i,j,flag=0;
    char s1[LEN+1];
    printf("������Ҫɾ��ѧ����ѧ��:\n");
    scanf("%s",s1);
    for(i=0;i<n;i++)
        if(strcmp(Stud[i].code,s1)==0)
        {
            flag=1;
            for(j=i;j<n-1;j++)
            Stud[j]=Stud[j+1];

        }
        if(flag==0)
            printf("��ѧ�Ų����ڣ�\n");
        if(flag==1)
        {
            printf("ɾ���ɹ�,��ʾ�����ѡ��˵�\n");
            n--;
        }
}


void display()  /*��ʾ��ǰ��Ϣ*/
{
    int i;
    printf("����%dλѧ������Ϣ:\n",n);
    if(0!=n)
    {
        printf("ѧ��ѧ��  ѧ������ ����  �Ա�  C���Գɼ�  �ߵ���ѧ  ��ѧӢ��ɼ�\n");
        printf("--------------------------------------------------------------------\n");
        for(i=0;i<n;i++)
        {
            printf("%7s %7s %6d %6s %9.1f %10.1f %10.1f\n",Stud[i].code,
        Stud[i].name,Stud[i].age,Stud[i].sex,Stud[i].score[0],Stud[i].score[1],Stud[i].score[2]);
        }
    }
}




void freshen() /*ˢ����Ϣ*/
{
}


void menu()/* ����*/
{
    int num;
    printf(" \n\n                    \n\n");
    printf("  ******************************************************\n\n");
    printf("  *                ѧ����Ϣ����ϵͳ                    *\n \n");
    printf("  ******************************************************\n\n");
    printf("*********************ϵͳ���ܲ˵�*************************       \n");
    printf("     ----------------------   ----------------------   \n");
    printf("     *********************************************     \n");
    printf("     * 0.ϵͳ������˵��  * *  1.ˢ��ѧ����Ϣ   *     \n");
    printf("     *********************************************     \n");
    printf("     * 2.��ѯѧ����Ϣ    * *  3.�޸�ѧ����Ϣ   *     \n");
    printf("     *********************************************     \n");
    printf("     * 4.����ѧ����Ϣ    * *  5.��ѧ��ɾ����Ϣ *     \n");
    printf("     *********************************************     \n");
    printf("     * 6.��ʾ��ǰ��Ϣ    * *  7.���浱ǰѧ����Ϣ*     \n");
    printf("     ********************** **********************     \n");
    printf("     * 8.�˳�ϵͳ        *                            \n");
    printf("     **********************                            \n");
    printf("     ----------------------   ----------------------                           \n");
    printf("��ѡ��˵����:");
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
    default:printf("����0-8֮��ѡ��\n");
    }
}
