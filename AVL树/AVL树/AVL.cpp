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
	void standard(node* t);							//标准化AVL树
	int gettsize();								//得到长度
	void l_lroll(node* t);						//LL旋转
	void r_rroll(node* t);						//RR旋转
	void l_rroll(node* t);						//LR旋转
	void r_lroll(node* t);						//RL旋转
	void merge(node* t);						//合并两棵AVL树
	void devide(node* t);						//将一棵AVL树分裂
	void iterator(node* first, node* t,node* st);

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
				current->leftchild->leftchild = current->leftchild->rightchild = NULL;
				standard(root);
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
				current->rightchild->leftchild = current->rightchild->rightchild = NULL;
				standard(root);
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
	node* m = root->rightchild;
	node* t=NULL;
	iterator(root, m,t);
	cout << t->balance << endl;
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
	//else if(t->leftchild=t->rightchild==NULL)
		//t->balance=0;
	else
	{
		t->balance=getheight(t->leftchild)-getheight(t->rightchild);
		t->n_height = (getheight(t->leftchild) > getheight(t->rightchild)) ? getheight(t->leftchild) : getheight(t->rightchild);
	}

}

void AVLtree::iterator(node* first,node* t,node* st)
{
	if (first == NULL)
	{
		return ;
	}
	if (first == t)
	{
		st = t;
		return ;
	}
	iterator(first->leftchild, t,st);
	iterator(first->rightchild, t,st);
	if (left == NULL)
	{
		st = first->leftchild;
		return;
	}
	if (right == NULL)
	{
		st = first->rightchild;
		return;
	}
	else
	{
		st = first;
		return;
	}
}

void AVLtree::l_lroll(node* t)
{

}

void AVLtree::r_rroll(node* t)
{

}

void AVLtree::l_rroll(node* t)
{

}

void AVLtree::r_lroll(node* t)
{

}

void AVLtree::standard(node* t)
{
	node* current = t;
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		getbalance(t);
		if ((current->balance == 2 || current->balance == -2) && current->n_height < t->n_height)
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

void Ascend(AVLtree av,void (AVLtree::*function)(node*),node* t)
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
	Ascend(tr, func, tr.getroot());
	//node* x=tr.iterator(tr.getroot(),tr.get)
	tr.test();
	system("pause");
	return 0;
}