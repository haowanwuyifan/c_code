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
		cout << "��������" << endl;
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
		cout << "��������" << endl;
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
	cout << "**1.ÿ�о�ֵ****2.�˳�����**" << endl;
	cout << "**3.ÿ�о�ֵ****4.ɾ��ĳ��**" << endl;
	cout << "**5.ɾ��ĳ��****6.����˷�**" << endl;
	cout << "****************************" << endl;
	int option;
	cout << "������ѡ�";
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
		cout << "������Ҫɾ�����У�";
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
		cout << "������Ҫɾ�����У�";
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
		cout << "�������ά����" << endl;
		float* b = new float[*n];
		for (int i = 0; i<*n; i++)
		{
			cin >> b[i];
		}
		float* c = new float[*m];
		multiple(a, m, n, b, c);
		cout << "������Ϊ��" ;
		for (int i = 0; i<*m; i++)
		{
			cout << c[i] << " ";
		}
		cout << endl;
		break;
	}
	default:
		cout << "���������룡" << endl;
		break;
	}
}

int main()
{
	int m, n;
	cout << "����������У�";
	cin >> m;
	cout << "����������У�";
	cin >> n;
	cout << "���������" << endl;
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