#include<iostream>
#include<stdlib.h>
#include"myqueue.h"
using namespace std;

struct store
{
	int contant;
	store* next;
};

class AVLtree
{
public:
	AVLtree(int size);							//构造函数
	void buildtree(int* key);					//创建搜索树
	void Search(int key);						//按关键字搜索
	void Search(char content);					//按内容搜索
	void Insert(int key);						//按关键字插入
	void Insert(char content);					//按内容插入
	void Delete(int key);						//按关键字删除
	void Delete(char content);					//按内容删除

	//void Ascend(node* t，void (*function)(node*));						//按关键字层次遍历
	//void Ascend(char content);				//按内容遍历
	void getbalance(node* t);					//计算平衡因子
	int getheight(node* t);						//计算树的高度
	void left_left();							//LL旋转
	void right_right();							//RR旋转
	void left_right();							//LR旋转
	void right_left();							//RL旋转
	void test();								//测试用函数
	node* getroot();							//得到节点
	node* standard(node* t);							//标准化AVL树
	int gettsize();								//得到长度
	void l_lroll(node* t);						//LL旋转
	void r_rroll(node* t);						//RR旋转
	void l_rroll(node* t);						//LR旋转
	void r_lroll(node* t);						//RL旋转
	void merge(node* t);						//合并两棵AVL树
	void devide(node* t);						//将一棵AVL树分裂
	node* iterator(node* t,node* y);
private:
	node* root;
	int height;
	int tsize;

};

AVLtree::AVLtree(int size)
{
	root=NULL;
	tsize=size;
}

void AVLtree::buildtree(int* key)
{
	root=new node;
	root->element.first=key[0];
	root->element.second=(char)(key[0]+96);
	root->n_side = -1;
	root->leftchild=root->rightchild=NULL;
	for(int i=1;i<tsize;i++)
	{
		node* current=root;
		while(1)
		{
			if (key[i] < current->element.first&&current->leftchild != NULL)
			{
				current = current->leftchild;
			}
			if (key[i] < current->element.first&&current->leftchild == NULL)
			{
				current->leftchild = new node;
				current->leftchild->element.first = key[i];
				current->leftchild->element.second = (char)(key[i] + 96);
				current->leftchild->n_side = -1;
				current->leftchild->leftchild = current->leftchild->rightchild = NULL;
				node* t = standard(root);
				if (t->balance == 2 || t->balance == -2)
				{
					if (t->leftchild != NULL && t->leftchild->leftchild == current)
					{
						l_lroll(t);
					}
					else if (t->rightchild !=NULL && t->rightchild->leftchild == current)
					{
						r_lroll(t);
					}
				}
				break;
			}
			if (key[i] > current->element.first&&current->rightchild != NULL)
			{
				current = current->rightchild;
			}
			if (key[i] > current->element.first&&current->rightchild == NULL)
			{
				current->rightchild = new node;
				current->rightchild->element.first = key[i];
				current->rightchild->element.second = (char)(key[i] + 96);
				current->rightchild->n_side = -1;
				current->rightchild->leftchild = current->rightchild->rightchild = NULL;
				node* t = standard(root);
				if (t->balance == 2 || t->balance == -2)
				{
					if (t->leftchild != NULL && t->leftchild->rightchild == current)
					{
						l_rroll(t);
					}
					else if (t->rightchild != NULL && t->rightchild->rightchild == current)
					{
						r_rroll(t);
					}
				}
				break;
			}
		}
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
	if(t==NULL)
		return 0;
	int hl=getheight(t->leftchild);
	int hr=getheight(t->rightchild);
	if(hl>hr)
		return ++hl;
	else
		return ++hr;
}

void AVLtree::getbalance(node* t)
{
	if(t==NULL)
		cout<<"请输入内容"<<endl;
	else
	{
		t->balance=getheight(t->leftchild)-getheight(t->rightchild);
		t->n_height = (getheight(t->leftchild) > getheight(t->rightchild)) ? getheight(t->leftchild) : getheight(t->rightchild);
	}

}

node* AVLtree::iterator(node* t,node* y)
{
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		if (y == root)
		{
			return root;
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

void AVLtree::l_lroll(node* t)
{
	node* temp = t->leftchild;
	t->leftchild = t->leftchild->rightchild;
	temp->rightchild = t;
	node* parent = iterator(root,t);
	if (parent->n_side == 0)
	{
		parent->leftchild = temp;
	}
	if (parent->n_side == 1)
	{
		parent->rightchild = temp;
	}
}

void AVLtree::r_rroll(node* t)
{
	node* temp = t->rightchild;
	t->rightchild = t->rightchild->leftchild;
	temp->leftchild = t;
	node* parent = iterator(root, t);
	if (parent->n_side == 0)
	{
		parent->leftchild = t;
	}
	if (parent->n_side == 1)
	{
		parent->rightchild = temp;
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

//void AVLtree::level(node* t)
//{
//	node* current = t;
//	Queue qu(gettsize());
//	qu.createqueue();
//	qu.push(t);
//	while (qu.empty())
//	{
//		getbalance(t);
//		if (t->leftchild != NULL)
//		{
//			qu.push(t->leftchild);
//		}
//		if (t->rightchild != NULL)
//		{
//			qu.push(t->rightchild);
//		}
//		qu.pop();
//		t = qu.getqueue();
//	}
//}

void Temp(AVLtree av,void (AVLtree::*function)(node*),node* t)
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


int main()
{
	int size = 0;
	store head;
	head.contant = NULL;
	head.next = NULL;
	store* current = &head;
	int t=-1;
	cout << "请输入关键字："<<endl;
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
	int* a=new int[size];
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
	//node* x=tr.iterator(tr.getroot(),tr.get)
	tr.test();
	system("pause");
	return 0;
}