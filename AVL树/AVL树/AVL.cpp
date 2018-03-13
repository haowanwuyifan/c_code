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
	AVLtree(int size);							//���캯��
	void buildtree(int* key);					//����������
	void Search(int key);						//���ؼ�������
	void Search(char content);					//����������
	void Insert(int key);						//���ؼ��ֲ���
	void Insert(char content);					//�����ݲ���
	void Delete(int key);						//���ؼ���ɾ��
	void Delete(char content);					//������ɾ��

	//void Ascend(node* t��void (*function)(node*));						//���ؼ��ֲ�α���
	//void Ascend(char content);				//�����ݱ���
	void getbalance(node* t);					//����ƽ������
	int getheight(node* t);						//�������ĸ߶�
	void left_left();							//LL��ת
	void right_right();							//RR��ת
	void left_right();							//LR��ת
	void right_left();							//RL��ת
	void test();								//�����ú���
	node* getroot();							//�õ��ڵ�
	void standard(node* t);							//��׼��AVL��
	int gettsize();								//�õ�����
	void l_lroll(node* t);						//LL��ת
	void r_rroll(node* t);						//RR��ת
	void l_rroll(node* t);						//LR��ת
	void r_lroll(node* t);						//RL��ת
	void merge(node* t);						//�ϲ�����AVL��
	void devide(node* t);						//��һ��AVL������
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
		cout<<"����������"<<endl;
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
	cout << "������ؼ��֣�"<<endl;
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