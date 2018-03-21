#include<iostream>
#include<stdlib.h>
#include"myqueue.h"
#include"AVL.h"
using namespace std;

int k = 1;

void menu(AVLtree tr)
{
	cout << "*************AVL树选项菜单*****************" << endl;
	cout << "***************1.搜索关键字****************" << endl;
	cout << "****2.删除关键字***********3.插入关键字****" << endl;
	cout << "****4.升序输出***************5.分裂此树****" << endl;
	cout << "****6.合并两棵树*************7.退出程序****" << endl;
	cout << "*******************************************" << endl;
	cout << "请输入选项：";
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
	{
		int key;
		cout << "输入搜索的关键字：";
		cin >> key;
		node* t = tr.Search(key);
		break;
	}
	case 2:
	{
		int del;
		cout << "请输入删除的关键字：";
		cin >> del;
		tr.Delete(del);
		break;
	}
	case 3:
	{
		int insrt;
		cout << "输入要插入的关键字：";
		cin >> insrt;
		tr.Insert(insrt);
		break;
	}
	case 4:
	{
		tr.Ascend(tr.getroot());
		break;
	}
	case 5:
	{
		int div;
		cout << "输入要分裂的关键字：";
		cin >> div;
		tr.getdivide(div, tr.getroot());
		int size = tr.getdiv(tr.getroot());
		AVLtree b(size);
		tr.divide(tr.getroot(), b);
		break;
	}
	case 6:
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
		AVLtree br(size);
		br.buildtree(a);
		tr.merge(br);
		break;
	}
	case 7:
	{
		k = 0;
		break;
	}
	default:
		cout << "请重新输入：";
		break;
	}
}

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
	while (k)
	{
		menu(tr);
	}
	
	
	system("pause");
	return 0;
}