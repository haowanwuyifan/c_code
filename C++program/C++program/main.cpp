#include<iostream>
#include"array.h"
#include<stdlib.h>

using namespace std;

int main()
{
	int size_a, size_b;
	cout << "�������һ������ĸ���:";
	cin >> size_a;
	cout << "������ڶ�������ĸ���:";
	cin >> size_b;
	int* a = new int[size_a];
	int* b = new int[size_b];
	int size_c = size_a + size_b;
	int* c = new int[size_c];
	int content_a, content_b;
	cout << "������Ϊ��1�������ʼ������ֵ��";
	cin >> content_a;
	cout << "������Ϊ��2�������ʼ������ֵ��";
	cin >> content_b;
	initial(a, size_a, content_a);
	initial(b, size_b, content_b);
	merge(a, size_a, b, size_b, c);
	cout << "��������Ҫ��������ֵ��";
	int search_key;
	cin >> search_key;
	index(c, size_c, search_key);
	system("pause");
	return 0;
}
