#include<iostream>
#include<stdlib.h>
#include"myqueue.h"
#include"AVL.h"
using namespace std;

int k = 1;

void menu(AVLtree tr)
{
	cout << "*************AVL��ѡ��˵�*****************" << endl;
	cout << "***************1.�����ؼ���****************" << endl;
	cout << "****2.ɾ���ؼ���***********3.����ؼ���****" << endl;
	cout << "****4.�������***************5.���Ѵ���****" << endl;
	cout << "****6.�ϲ�������*************7.�˳�����****" << endl;
	cout << "*******************************************" << endl;
	cout << "������ѡ�";
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
	{
		int key;
		cout << "���������Ĺؼ��֣�";
		cin >> key;
		node* t = tr.Search(key);
		break;
	}
	case 2:
	{
		int del;
		cout << "������ɾ���Ĺؼ��֣�";
		cin >> del;
		tr.Delete(del);
		break;
	}
	case 3:
	{
		int insrt;
		cout << "����Ҫ����Ĺؼ��֣�";
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
		cout << "����Ҫ���ѵĹؼ��֣�";
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
		cout << "������ؼ��֣�" << endl;
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
		cout << "���������룺";
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
	cout << "������ؼ��֣�" << endl;
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