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
			cout << "����ֵλ�ڵ�" << i + 1 << "λ" << endl;
		}
	}
	if (i == size_a)
	{
		cout << "û�и���ֵ��" << endl;
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