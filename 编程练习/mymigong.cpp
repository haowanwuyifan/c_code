#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

struct mesh//�����Թ��ڵ�ṹ
{
	int wall;//ǽ
	int used;//��ʾ�Ƿ��߹�
};

class maze//�Թ���
{
public:
	int found;//��ʾ�Ƿ��ҵ�����
	void show();//û���ҵ�·����������ԭ�Թ�
	void findway(int, int);//��·����
	void showway();//���·��
	maze(mesh **a, int size);//���캯��
protected:
	
	int start;//��ʼ��ʶ
	mesh**me;
	int size;//�Թ��Ĵ�С
};

maze::maze(mesh** a, int c)//���Թ���ʼ����������һ��������Թ�
{
	found = 0;
	start = 0;
	size = c;
	me = new mesh*[size];
	for (int i = 0; i < size; i++)
	{
		me[i] = new mesh[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			me[i][j] = a[i][j];
		}
	}
}

void maze::show()//���ԭ�Թ���ǽ��#��ʾ���ռ��ÿո��ʾ
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (me[i][j].wall == 1)
				cout << "# ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void maze::showway()//���·����ǽ��#��ʾ���ռ��ÿո��ʾ�ռ䣬*��ʾ�߹���·��
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (me[i][j].used == 1)
				cout << "* ";
			else if (me[i][j].wall == 1)
				cout << "# ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void maze::findway(int row,int col)//��·���õݹ��˼�룬�൱��ÿһ�γ��Զ�����һ����ջ�������·��ͨ����ջ����
{
	if (found == 1)
	{
		return;
	}
	if (start == 0)
	{
		row = size-2;
		col = 3;
		start = 1;
	}
	me[row][col].used = 1;
	if (row == 0 && col == size - 4)
	{
		found = 1;
		showway();
	}
	if (found == 1)
	{
		return;
	}
	if (me[row - 1][col].wall == 0 && me[row - 1][col].used == 0)
	{
		findway(row - 1, col);
		me[row - 1][col].used = 0;
	}
	if (found == 1)
	{
		return;
	}
	if (me[row][col + 1].wall == 0 && me[row][col + 1].used == 0)
	{
		findway(row, col + 1);
		me[row][col + 1].used = 0;
	}
	if (found == 1)
	{
		return;
	}
	if (me[row][col - 1].wall == 0 && me[row][col - 1].used == 0)
	{
		findway(row, col - 1);
		me[row][col - 1].used = 0;
	}
	if (found == 1)
	{
		return;
	}
	if (me[row + 1][col].wall == 0 && me[row + 1][col].used == 0)
	{
		findway(row + 1, col);
		me[row + 1][col].used = 0;
	}
}



int main()
{
	srand((unsigned)time(NULL));//��������Թ�
	int size;
	cin >> size;
	mesh** a = new mesh*[size];
	for(int i=0;i<size;i++)
	{
		a[i] = new mesh[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a[i][j].wall = 0;
			a[i][j].used = 0;
			if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
			{
				a[i][j].wall = 1;
			}
		}
	}
	for (int i = 1; i < size - 1; i++) 
	{
		for (int j = 1; j < size - 1; j++) 
		{
			if (rand() % 5 == 1) 
			{
				a[i][j].wall = 1;
			}
		}
	}
	a[size-1][3].wall = 0;
	a[size-2][3].wall = 0;
	a[size-1][3].used = 1;
	a[0][size - 4].wall = 0;
	a[1][size - 4].wall = 0;
	maze twsr(a, size);
	twsr.findway(0,0);
	if (twsr.found == 0)
	{
		twsr.show();
		cout << "no way exists!" << endl;
	}
	system("pause");
	return 0;
}