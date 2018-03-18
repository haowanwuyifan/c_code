#pragma once

#include<iostream>
#include<stdlib.h>
#include"myqueue.h"
using namespace std;

class AVLtree
{
public:
	AVLtree(int size);							//���캯��
	void buildtree(int* key);					//����������
	node* Search(int key);						//���ؼ�������
												//void Search(char content);					//����������
	void Insert(int key);						//���ؼ��ֲ���
												//void Insert(char content);					//�����ݲ���
	void Delete(int key);						//���ؼ���ɾ��
												//void Delete(char content);					//������ɾ��
	void Ascend();								//�������
	void getbalance(node* t);					//����ƽ������
	int getheight(node* t);						//�������ĸ߶�
	void test();								//�����ú���
	node* getroot();							//�õ��ڵ�
	node* standard(node* t);							//��׼��AVL��
	int gettsize();								//�õ�����
	void l_lroll(node* t);						//LL��ת
	void r_rroll(node* t);						//RR��ת
	void l_rroll(node* t);						//LR��ת
	void r_lroll(node* t);						//RL��ת
	void merge(AVLtree av);						//�ϲ�����AVL��
	void devide();						//��һ��AVL������
	node* iterator(node* t, node* y);
	void erase(int key);
	node* max_right(node* t);
private:
	node * root;
	int height;
	int tsize;

};

AVLtree::AVLtree(int size)
{
	root = NULL;
	tsize = size;
}

void AVLtree::buildtree(int* key)
{
	root = new node;
	root->element.first = key[0];
	root->element.second = (char)(key[0] + 96);
	root->n_side = -1;
	root->leftchild = root->rightchild = NULL;
	for (int i = 1; i<tsize; i++)
	{
		Insert(key[i]);
	}
}

node* AVLtree::getroot()
{
	return root;
}

void AVLtree::test()
{
	node* m = root/*->rightchild->leftchild*/;
	try
	{
		//node* t = iterator(root, m);
		cout << m->balance << endl;
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}

}

int AVLtree::gettsize()
{
	return tsize;
}

int AVLtree::getheight(node* t)
{
	if (t == NULL)
		return 0;
	int hl = getheight(t->leftchild);
	int hr = getheight(t->rightchild);
	if (hl>hr)
		return ++hl;
	else
		return ++hr;
}

void AVLtree::getbalance(node* t)
{
	if (t == NULL)
		cout << "����������" << endl;
	else
	{
		t->balance = getheight(t->leftchild) - getheight(t->rightchild);
		t->n_height = (getheight(t->leftchild) > getheight(t->rightchild)) ? getheight(t->leftchild) : getheight(t->rightchild);
	}

}

node* AVLtree::iterator(node* t, node* y)
{
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		if (y == root)
		{
			return y;
		}
		if (t == NULL)
		{
			{
				throw"error";
			}
			return t;
		}
		if (t->leftchild == y)
		{
			t->n_side = 0;
			return t;
			break;
		}
		if (t->rightchild == y)
		{
			t->n_side = 1;
			return t;
		}
		if (t->leftchild != NULL)
		{
			qu.push(t->leftchild);
		}
		if (t->rightchild != NULL)
		{
			qu.push(t->rightchild);
		}
		qu.pop();
		t = qu.getqueue();
	}
}

node* AVLtree::max_right(node* t)
{
	node* current = t;
	while (current->rightchild != NULL)
	{
		current = current->rightchild;
	}
	return current;
}

void AVLtree::l_lroll(node* t)
{
	node* temp = t->leftchild;
	t->leftchild = t->leftchild->rightchild;
	temp->rightchild = t;
	if (t == root)
	{
		root = temp;
	}
	else
	{
		node* parent = iterator(root, t);
		if (parent->n_side == 0)
		{
			parent->leftchild = temp;
		}
		if (parent->n_side == 1)
		{
			parent->rightchild = temp;
		}
	}
}

void AVLtree::r_rroll(node* t)
{
	node* temp = t->rightchild;
	t->rightchild = t->rightchild->leftchild;
	temp->leftchild = t;
	if (root == t)
	{
		root = temp;
	}
	else
	{
		node* parent = iterator(root, t);
		if (parent->n_side == 0)
		{
			parent->leftchild = temp;
		}
		if (parent->n_side == 1)
		{
			parent->rightchild = temp;
		}
	}
}

void AVLtree::l_rroll(node* t)
{
	r_rroll(t->leftchild);
	l_lroll(t);
}

void AVLtree::r_lroll(node* t)
{
	l_lroll(t->rightchild);
	r_rroll(t);
}

node* AVLtree::standard(node* t)
{
	node* current = t;
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		getbalance(t);
		if ((t->balance == 2 || t->balance == -2) && current->n_height > t->n_height)
		{
			current = t;
		}
		if (t->leftchild != NULL)
		{
			qu.push(t->leftchild);
		}
		if (t->rightchild != NULL)
		{
			qu.push(t->rightchild);
		}
		qu.pop();
		t = qu.getqueue();
	}
	return current;
}

node* AVLtree::Search(int key)
{
	node* current = root;
	while (1)
	{
		if (current == NULL)
		{
			cout << "�����ڸùؼ��֣�" << endl;
			return NULL;
			break;
		}
		if (key == current->element.first)
		{
			return current;
		}
		if (key < current->element.first)
		{
			current = current->leftchild;
			//break;
		}
		if (key > current->element.first)
		{
			current = current->rightchild;
			//break;
		}
	}
}

void AVLtree::Insert(int key)
{
	node* current = root;
	while (1)
	{
		if (key < current->element.first&&current->leftchild != NULL)
		{
			current = current->leftchild;
		}
		if (key < current->element.first&&current->leftchild == NULL)
		{
			current->leftchild = new node;
			current->leftchild->element.first = key;
			current->leftchild->element.second = (char)(key + 96);
			current->leftchild->n_side = -1;
			current->leftchild->leftchild = current->leftchild->rightchild = NULL;
			node* t = standard(root);
			if (t->balance == 2)
			{
				if (t->leftchild->balance == 1)
				{
					l_lroll(t);
				}
				else if (t->leftchild->balance == -1)
				{
					l_rroll(t);
				}
			}
			if (t->balance == -2)
			{
				if (t->rightchild->balance == 1)
				{
					r_lroll(t);
				}
				else if (t->rightchild->balance == -1)
				{
					r_rroll(t);
				}
			}
			break;
		}
		if (key > current->element.first&&current->rightchild != NULL)
		{
			current = current->rightchild;
		}
		if (key > current->element.first&&current->rightchild == NULL)
		{
			current->rightchild = new node;
			current->rightchild->element.first = key;
			current->rightchild->element.second = (char)(key + 96);
			current->rightchild->n_side = -1;
			current->rightchild->leftchild = current->rightchild->rightchild = NULL;
			node* t = standard(root);
			if (t->balance == 2)
			{
				if (t->leftchild->balance == 1)
				{
					l_lroll(t);
				}
				if (t->leftchild->balance == -1)
				{
					l_rroll(t);
				}
			}
			if (t->balance == -2)
			{
				if (t->rightchild->balance == 1)
				{
					r_lroll(t);
				}
				if (t->rightchild->balance == -1)
				{
					r_rroll(t);
				}
			}
			break;
		}
	}
}

void AVLtree::erase(int key)
{
	node* t = Search(key);
	if (t == NULL)
	{
		cout << "�����ڸùؼ��֣�";
	}
	else
	{
		node* parent = iterator(root, t);
		if (t->leftchild == NULL && t->rightchild == NULL)
		{
			if (parent->n_side == 0)
			{
				parent->leftchild = NULL;
			}
			if (parent->n_side == 1)
			{
				parent->rightchild = NULL;
			}
		}
		else if (t->rightchild != NULL && t->leftchild != NULL)
		{
			node* max_l = max_right(t);
			node* parent_d = iterator(root, max_l);
			parent_d->rightchild = max_l->leftchild;
			max_l->leftchild = t->leftchild;
			if (t == root)
			{
				root = max_l;
			}
			if (parent->n_side == 0)
			{
				parent->leftchild = max_l;
			}
			if (parent->n_side == 1)
			{
				parent->rightchild = max_l;
			}
		}
		else if ((t->rightchild != NULL&&t->leftchild==NULL) || (t->leftchild != NULL&&t->rightchild==NULL))
		{
			node* chil = t->leftchild == NULL ? t->rightchild : t->leftchild;
			if (t = root)
			{
				root = chil;
			}
			if (parent->n_side == 0)
			{
				parent->leftchild = chil;
			}
			if (parent->n_side == 1)
			{
				parent->rightchild = chil;
			}
		}
	}
}

void AVLtree::Delete(int key)
{
	node* t = Search(key);
	node* parent = iterator(root, t);
	getbalance(parent);
	if (parent->balance == 1 || parent->balance == -1)
	{
		erase(key);
	}
	if (parent->balance == 2 || parent->balance == -2)
	{

	}
	if (parent->balance == 0)
	{
		node* grand = standard(root);
		if (grand->balance == 2 || grand->balance == -2)
		{

		}
		else
		{
			erase(key);
		}
	}
	if (t == root)
	{
		erase(key);
	}
	else
	{

	}
}

void AVLtree::Ascend()
{

}

void AVLtree::merge(AVLtree av)
{

}

void AVLtree::devide()
{

}

void Temp(AVLtree av, void (AVLtree::*function)(node*), node* t)
{
	Queue qu(av.gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		(av.*function)(t);
		if (t->leftchild != NULL)
		{
			qu.push(t->leftchild);
		}
		if (t->rightchild != NULL)
		{
			qu.push(t->rightchild);
		}
		qu.pop();
		t = qu.getqueue();
	}
}
