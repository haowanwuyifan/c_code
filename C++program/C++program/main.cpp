#include<iostream>
#include"array.h"
#include<stdlib.h>

using namespace std;

int main()
{
	int size_a, size_b;
	cout << "请输入第一个数组的个数:";
	cin >> size_a;
	cout << "请输入第二个数组的个数:";
	cin >> size_b;
	int* a = new int[size_a];
	int* b = new int[size_b];
	int size_c = size_a + size_b;
	int* c = new int[size_c];
	int content_a, content_b;
	cout << "请输入为第1个数组初始化的数值：";
	cin >> content_a;
	cout << "请输入为第2个数组初始化的数值：";
	cin >> content_b;
	initial(a, size_a, content_a);
	initial(b, size_b, content_b);
	merge(a, size_a, b, size_b, c);
	cout << "请输入想要搜索的数值：";
	int search_key;
	cin >> search_key;
	index(c, size_c, search_key);
	system("pause");
	return 0;
}
