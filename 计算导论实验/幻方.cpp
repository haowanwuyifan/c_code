#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;					//����÷��Ľ�
	printf("please input the size of matrix ");
    scanf_s("%d",&n);
	while (n % 2 != 1)		//����������ż������������
    {
        printf("Error,please input again!");
        scanf_s("%d",&n);
    }
    const int MAX=n*n;
    int** a=new int*[n];		//��̬����n�׻÷�
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++)		//��ʼ����������ֵ��Ϊ0
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    int col=n/2;			
    int row=0;
    a[row][col]=1;				//��һ���м�һ��Ϊ1
    for(int i=2;i<=MAX;i++)		//��2��ʼ��
    {
        int rown=row-1;			//ÿһ������ŵ��б�ǰһ������������1��������1
        int coln=col+1;
        if(row==0)				//�����һ����������Ϊ1������һ����������Ϊn��ָ����һ�У�
        {
            rown=n-1;
        }
        if(col==n-1)			//����һ����������Ϊnʱ����һ����������ӦΪ1��������ȥ1
        {
            coln=0;
        }
        if(a[rown][coln]!=0)	//������������ȷ����λ����������������һ�����ǵ�һ�е�n��ʱ�������һ����������һ���������档
        {		
            rown=rown+1;
        }
        a[rown][coln]=i;
        row=rown;				//���к������¸�ֵ
        col=coln;
    }
    for(int i=0;i<n;i++)		//����÷�
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
	system("pause");
    return 0;
}
