#include<iostream>
#include"array.h"
using namespace std;

void initial(int* a, int size, int content)
{
	for (int i = 0; i < size; ++i)
	{
		a[i] = content;
	}
}

void merge(int* a, int size_a, int* b, int size_b, int* c)
{
	//c = new int[size_a + size_b];
	for (int i = 0; i < size_a; ++i)
	{
		c[i] = a[i];
	}
	for (int j = 0; j < size_b; ++j)
	{
		c[j + size_a] = b[j];
	}
}

void index(int* a, int size_a,int key)
{
	int i = 0;
	for (i; i < size_a; ++i)
	{
		if (a[i] == key)
		{
			cout << "该数值位于第" << i + 1 << "位" << endl;
		}
	}
	if (i == size_a)
	{
		cout << "没有该数值！" << endl;
	}
}

void erase(int* a, int size_a, int key)
{
	for (int i = 0; i < size_a; ++i)
	{
		if (a[i] == key)
		{
			for (int j = i; j < size_a; ++j)
			{
				a[j] = a[j + 1];
			}
		}
	}
}

void select(int* list, int m)
{
	int i, j, temp;
	int k;
	for (i = 0; i<m - 1; i++)
	{
		k = 0;
		for (j = 0; j<m - i; j++)
		{
			if (list[k]<list[j])
				k = j;
		}
		temp = list[m - 1 - i];
		list[m - 1 - i] = list[k];
		list[k] = temp;
	}
	for (int i = 0; i<m; i++)
		cout << list[i];
}