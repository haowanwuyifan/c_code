#include<iostream>
#include<stdlib.h>
#include"myqueue.h"
#include"AVL.h"
using namespace std;


int main()
{
	int size = 0;
	store head;
	head.contant = NULL;
	head.next = NULL;
	store* current = &head;
	int t = -1;
	cout << "请输入关键字：" << endl;
	while (1)
	{
		cin >> t;
		if (t != 0)
		{
			current->next = new store;
			current->next->contant = t;
			current = current->next;
			size++;
		}
		else
		{
			break;
		}
	}
	int* a = new int[size];
	store* current_2 = head.next;
	for (int i = 0; i < size; i++)
	{
		a[i] = current_2->contant;
		current_2 = current_2->next;
	}
	AVLtree tr(size);
	tr.buildtree(a);
	void (AVLtree::*func)(node*);
	func = &AVLtree::getbalance;
	Temp(tr, func, tr.getroot());
	tr.test();
	int key;
	cout << "输入搜索的关键字：";
	cin >> key;
	tr.Search(key);
	int insrt;
	cout << "输入要插入的关键字：";
	cin >> insrt;
	tr.Insert(insrt);
	system("pause");
	return 0;
}