#include<iostream>
#include<stdlib.h>
using namespace std;

struct matrixnode
{
    int row;
    int col;
    int element;
};

class matrix
{
public:
    void transpose(); //����ת��
    void add();  //����ӷ�
    //void putmatrix(int *a,int m,int n);  //
    void output(); //�������
    matrix(int **a,int m,int n,int size);//���캯��
    void putsecondnode(int **a,int m,int n,int size);//���캯�����ڶ�������
    //matrixndoe* sort(matrixndoe a);//dui term paxu
protected:
    int rows,cols;//����1�ĳ���
    int row2,col2;//����2�ĳ���
    matrixnode* melements;//�洢����ÿ��λ�õ�Ԫ�أ�����Ľṹ
    matrixnode* selements;
    int listsize;//���鳤��
    int listsize2;

};

matrix::matrix(int **a,int m,int n,int size)
{//�Ծ���ֵ
    listsize=0;
    rows=m;
    cols=n;
    //int size=m*n;
    melements=new matrixnode[size];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i][j]!=0)
            {
                melements[listsize].element=a[i][j];
                melements[listsize].row=i;
                melements[listsize].col=j;
                listsize++;
            }
    }
}

void matrix::putsecondnode(int **a,int m,int n,int size)
{//�Եڶ�������ֵ
    listsize2=0;
    row2=m;
    col2=n;
    //int size=m*n;
    selements=new matrixnode[size];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i][j]!=0)
            {
                selements[listsize2].element=a[i][j];
                selements[listsize2].row=i;
                selements[listsize2].col=j;
                listsize2++;
            }
    }
}

void matrix::transpose()
{//�Ծ���ת�ã��浽һ����ά������
    matrixnode* temp=new matrixnode[listsize];
    for(int i=0;i<listsize;i++)
        temp[i]=melements[i];
    for(int i=0;i<listsize;i++)
    {
        int t;
        t=temp[i].row;
        temp[i].row=temp[i].col;
        temp[i].col=t;
    }

    //���ݴ��Ԫ�ش浽һ��һά�����У����
    int **stemp=new int*[cols];
    for(int i=0;i<cols;i++)
        {stemp[i]=new int[rows];}
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
            stemp[i][j]=0;
    }
    for(int i=0;i<listsize;i++)
    {
        stemp[temp[i].row][temp[i].col]=temp[i].element;
    }
    for(int i=0;i<cols;i++)//���ԭ������Ϊ�м���̵ļ��
    {
        for(int j=0;j<rows;j++)
            cout<<stemp[i][j]<<" ";
        cout<<endl;
    }
}

void matrix::add()
{
    int size=listsize+listsize2;//����һ���洢�¾�������飬�涨����Ϊԭ�������������
    matrixnode* temp=new matrixnode[size];
    int i1=0,i2=0;
    int i=0;
    while(i1<listsize&&i2<listsize2)
    {//��һά�����в������ȱȽϵ�ǰ��ָ��Ԫ���ĸ���ǰ����ǰ�ķŵ��µ������У�ָ����Ƽ����Ƚ�
        if(cols*melements[i1].row+melements[i1].col<col2*selements[i2].row+selements[i2].col)
        {
            temp[i].element=melements[i1].element;
            temp[i].row=melements[i1].row;
            temp[i].col=melements[i1].col;
            i1++;
			i++;
        }
        if(cols*melements[i1].row+melements[i1].col>col2*selements[i2].row+selements[i2].col)
        {
            temp[i].element=selements[i2].element;
            temp[i].row=selements[i2].row;
            temp[i].col=selements[i2].col;
            i2++;
			i++;
        }
        if(cols*melements[i1].row+melements[i1].col==col2*selements[i2].row+selements[i2].col)
        {
			if (melements[i1].element + selements[i2].element==0)
			{
				i++;
			}
			else
			{
				temp[i].element = melements[i1].element + selements[i2].element;
				temp[i].row = melements[i1].row;
				temp[i].col = melements[i1].col;
				i1++;
				i2++;
				i++;
			}
        }
    }//��һ������Ƚ����ʱ����ʣ�µ�����ŵ���������
    while(i1<listsize)
    {
        temp[i].element=melements[i1].element;
        temp[i].row=melements[i1].row;
        temp[i].col=melements[i1].col;
        i1++;
        i++;
    }
    while(i2<listsize2)
    {
        temp[i].element=selements[i2].element;
        temp[i].row=selements[i2].row;
        temp[i].col=selements[i2].col;
        i2++;
        i++;
    }

	//�����Ӻ�ľ���
    int **stemp=new int*[rows];
    for(int s=0;s<rows;s++)
        {stemp[s]=new int[cols];}
    for(int s=0;s<rows;s++)
    {
        for(int j=0;j<cols;j++)
            stemp[s][j]=0;
    }
    for(int s=0;s<i;s++)
    {
        stemp[temp[s].row][temp[s].col]=temp[s].element;
    }
    for(int s=0;s<rows;s++)
    {
        for(int j=0;j<cols;j++)
            cout<<stemp[s][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int size1=0;
    int m1=3;
    int n1=4;
    int **a1=new int*[m1];
    for(int i=0;i<m1;i++)
        a1[i]=new int[n1];
    int b1[3][4]={
       {0,3,0,0},
       {1,0,0,6},
       {0,4,7,0}
    };
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
            a1[i][j]=b1[i][j];
    }
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
            if(a1[i][j]!=0)
                size1++;
    }
    int size2=0;
    int m2=3;
    int n2=4;
    int **a2=new int*[m2];
    for(int i=0;i<m2;i++)
        for(int j=0;j<n2;j++)
            a2[i]=new int[n2];
    int b2[3][4]={
        {2,3,0,0},
        {3,0,0,1},
        {6,0,3,0}
    };
    for(int i=0;i<m2;i++)
    {
        for(int j=0;j<n2;j++)
            a2[i][j]=b2[i][j];
    }
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
            if(a2[i][j]!=0)
                size2++;
    }
	cout << "the first matrix: " << endl;
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			cout << b1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "the second matrix:" << endl;
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			cout << b2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
    matrix ma(a1,m1,n1,size1);
    ma.putsecondnode(a2,m2,n2,size2);
	cout << "the transpose matrix :" << endl;
	cout << endl;
    ma.transpose();
    cout<<endl;
	cout << "the added matrix :" << endl;
    ma.add();
	system("pause");
    return 0;
}
