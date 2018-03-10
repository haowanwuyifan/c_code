#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;					//输入幻方的阶
	printf("please input the size of matrix ");
    scanf_s("%d",&n);
	while (n % 2 != 1)		//如果输入的是偶数，重新输入
    {
        printf("Error,please input again!");
        scanf_s("%d",&n);
    }
    const int MAX=n*n;
    int** a=new int*[n];		//动态建立n阶幻方
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++)		//初始化，令所有值都为0
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    int col=n/2;			
    int row=0;
    a[row][col]=1;				//第一行中间一列为1
    for(int i=2;i<=MAX;i++)		//从2开始，
    {
        int rown=row-1;			//每一个数存放的行比前一个数的行数减1，列数加1
        int coln=col+1;
        if(row==0)				//如果上一个数的行数为1，则下一个数的行数为n（指最下一行）
        {
            rown=n-1;
        }
        if(col==n-1)			//当上一个数的列数为n时，下一个数的列数应为1，行数减去1
        {
            coln=0;
        }
        if(a[rown][coln]!=0)	//如果按上面规则确定的位置上已有数，或上一个数是第一行第n列时，则把下一个数放在上一个数的下面。
        {		
            rown=rown+1;
        }
        a[rown][coln]=i;
        row=rown;				//对行和列重新赋值
        col=coln;
    }
    for(int i=0;i<n;i++)		//输出幻方
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
