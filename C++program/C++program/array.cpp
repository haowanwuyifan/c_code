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
	int t = 0;
	for (i; i < size_a; ++i)
	{
		if (a[i] == key)
		{
			cout << "该数值位于第" << i + 1 << "位" << endl;
			t++;
		}
	}
	if (t == 0)
	{
		cout << "没有该数值！" << endl;
	}
}

int erase(int* a, int size_a, int key)
{
	for (int i = 0; i < size_a; ++i)
	{
		if (a[i] == key)
		{
			for (int j = i; j < size_a-1; ++j)
			{
				a[j] = a[j + 1];
				size_a--;
			}
		}
	}
	int size = size_a;
	return size;
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

void merge_plus(int* a, int size_a, int* b, int size_b, int* c)
{
	int size_c = size_a + size_b;
	int i = 0, j = 0;
	for (int k = 0; k < size_c; k++)
	{
		if (i < size_a&&j < size_b)
		{
			if (a[i] < b[j])
			{
				c[k] = a[i];
				i++;
			}
			else
			{
				c[k] = b[j];
				j++;
			}
		}
		else if (i < size_a)
		{
			c[k] = a[i];
			i++;
		}
		else if (j < size_b)
		{
			c[k] = b[j];
			j++;
		}
	}
}

void choose(int* m,int size_m)
{
		cout << "请输入想要搜索的数值：";
		int search_key;
		cin >> search_key;
		index(m, size_m, search_key);
		cout << "请输入想要删除的数值：";
		int delete_num;
		cin >> delete_num;
		cout << "删除后的数组长度为：" << erase(m, size_m, delete_num) << endl;
}