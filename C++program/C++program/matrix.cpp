#include<iostream>
using namespace std;

int k = 1;

void average_row(float** a, int *m, int *n, float* b)
{
	float avg = 0.0;
	for (int i = 0; i<*m; i++)
	{
		for (int j = 0; j<*n; j++)
		{
			avg = avg + a[i][j] / *n;
		}
		b[i] = avg;
		avg = 0.0;
	}
}

void average_col(float** a, int *m, int *n, float* b)
{
	float avg = 0.0;
	for (int i = 0; i<*n; i++)
	{
		for (int j = 0; j<*m; j++)
		{
			avg = avg + a[j][i] / *m;
		}
		b[i] = avg;
		avg = 0.0;
	}
}

void erase_row(float** a, int* m, int* n, int goal)
{
	if (*m>goal)
	{
		for (int i = goal - 1; i<*m - 1; i++)
		{
			for (int j = 0; j<*n; j++)
			{
				a[i][j] = a[i + 1][j];
			}
		}
		(*m)--;
	}
	else if (*m == goal)
	{
		(*m)--;
	}
	else
	{
		cout << "输入有误！" << endl;
	}
}

void erase_col(float** a, int* m, int* n, int goal)
{
	if (*n>goal)
	{
		for (int i = 0; i<*m; i++)
		{
			for (int j = goal - 1; j<*n - 1; j++)
			{
				a[i][j] = a[i][j + 1];
			}
		}
		(*n)--;
	}
	else if (*n == goal)
	{
		(*n)--;
	}
	else
	{
		cout << "输入有误！" << endl;
	}
}

void multiple(float** a, int *m, int *n, float* b, float* c)
{
	float sum = 0.0;
	for (int i = 0; i<*m; i++)
	{
		for (int j = 0; j<*n; j++)
		{
			sum += a[i][j] * b[j];
		}
		c[i] = sum;
		sum = 0.0;
	}
}

void menu(float** a, int *m, int *n)
{
	cout << "****************************" << endl;
	cout << "**1.每行均值****2.退出程序**" << endl;
	cout << "**3.每列均值****4.删除某行**" << endl;
	cout << "**5.删除某列****6.矩阵乘法**" << endl;
	cout << "****************************" << endl;
	int option;
	cout << "请输入选项：";
	cin >> option;
	switch (option)
	{
	case 1:
	{
		float* b = new float[*m];
		average_row(a, m, n, b);
		for (int i = 0; i<*m; i++)
		{
			cout << b[i] << " ";
			cout << endl;
		}
		delete[] b;
		break;
	}
	case 2:
	{
		k = 0;
		break;
	}
	case 3:
	{
		float* b = new float[*n];
		average_col(a, m, n, b);
		for (int i = 0; i<*n; i++)
		{
			cout << b[i] << " ";
			cout << endl;
		}
		delete[] b;
		break;
	}
	case 4:
	{
		cout << "请输入要删除的行：";
		int row;
		cin >> row;
		erase_row(a, m, n, row);
		for (int i = 0; i<*m; i++)
		{
			for (int j = 0; j<*n; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		break;
	}
	case 5:
	{
		cout << "请输入要删除的列：";
		int col;
		cin >> col;
		erase_col(a, m, n, col);
		for (int i = 0; i<*m; i++)
		{
			for (int j = 0; j<*n; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		break;
	}
	case 6:
	{
		cout << "请输入Ｎ维向量" << endl;
		float* b = new float[*n];
		for (int i = 0; i<*n; i++)
		{
			cin >> b[i];
		}
		float* c = new float[*m];
		multiple(a, m, n, b, c);
		cout << "计算结果为：" ;
		for (int i = 0; i<*m; i++)
		{
			cout << c[i] << " ";
		}
		cout << endl;
		break;
	}
	default:
		cout << "请重新输入！" << endl;
		break;
	}
}

int main()
{
	int m, n;
	cout << "请输入矩阵行：";
	cin >> m;
	cout << "请输入矩阵列：";
	cin >> n;
	cout << "请输入矩阵：" << endl;
	int *p = &m;
	int *q = &n;
	float** a = new float*[m];
	for (int i = 0; i<m; i++)
	{
		a[i] = new float[n];
	}
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}
	while (k)
	{
		menu(a, p, q);
	}
	return 0;
}