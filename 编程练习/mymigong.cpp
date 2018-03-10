#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

struct mesh//创建迷宫节点结构
{
	int wall;//墙
	int used;//表示是否走过
};

class maze//迷宫类
{
public:
	int found;//表示是否找到出口
	void show();//没有找到路的情况下输出原迷宫
	void findway(int, int);//找路函数
	void showway();//输出路径
	maze(mesh **a, int size);//构造函数
protected:
	
	int start;//开始标识
	mesh**me;
	int size;//迷宫的大小
};

maze::maze(mesh** a, int c)//对迷宫初始化，并构造一个随机的迷宫
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

void maze::show()//输出原迷宫，墙用#表示，空间用空格表示
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

void maze::showway()//输出路径，墙用#表示，空间用空格表示空间，*表示走过的路径
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

void maze::findway(int row,int col)//找路，用递归的思想，相当于每一次尝试都进行一次入栈，如果此路不通，将栈弹出
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
	srand((unsigned)time(NULL));//构造随机迷宫
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