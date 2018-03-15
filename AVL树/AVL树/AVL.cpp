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
	node* standard(node* t);							//��׼��AVL��
	int gettsize();								//�õ�����
	void l_lroll(node* t);						//LL��ת
	void r_rroll(node* t);						//RR��ת
	void l_rroll(node* t);						//LR��ת
	void r_lroll(node* t);						//RL��ת
	void merge(node* t);						//�ϲ�����AVL��
	void devide(node* t);						//��һ��AVL������
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
		cout<<"����������"<<endl;
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
	Temp(tr, func, tr.getroot());
	//node* x=tr.iterator(tr.getroot(),tr.get)
	tr.test();
	system("pause");
	return 0;
}