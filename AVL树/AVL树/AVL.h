#pragma once

#include<iostream>
#include<stdlib.h>
#include"myqueue.h"
using namespace std;

class AVLtree
{
public:
	AVLtree(int size);							//构造函数
	void buildtree(int* key);					//创建搜索树
	node* Search(int key);						//按关键字搜索
												//void Search(char content);					//按内容搜索
	void Insert(int key);						//按关键字插入
												//void Insert(char content);					//按内容插入
	void Delete(int key);						//按关键字删除
												//void Delete(char content);					//按内容删除
	void Ascend();								//升序输出
	void getbalance(node* t);					//计算平衡因子
	int getheight(node* t);						//计算树的高度
	void test();								//测试用函数
	node* getroot();							//得到节点
	node* standard(node* t);							//标准化AVL树
	int gettsize();								//得到长度
	void l_lroll(node* t);						//LL旋转
	void r_rroll(node* t);						//RR旋转
	void l_rroll(node* t);						//LR旋转
	void r_lroll(node* t);						//RL旋转
	void merge(AVLtree av);						//合并两棵AVL树
	void devide();						//将一棵AVL树分裂
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
		cout << "请输入内容" << endl;
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
			cout << "不存在该关键字！" << endl;
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
		cout << "不存在该关键字！";
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
