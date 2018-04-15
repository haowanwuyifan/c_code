#include<iostream>
#include<stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include"myqueue.h"
//using std::max;
//using std::cout;
//using std::endl;
#define posilchild(p) ((p)->leftchild ? (p)->leftchild->horizontal_position : (p)->horizontal_position)
#define posirchild(p) ((p)->rightchild ? (p)->rightchild->horizontal_position : (p)->horizontal_position)

int k = 1;
class AVLtree
{
public:
	AVLtree(int size);							//构造函数
	void buildtree(int* key);					//创建搜索树
	node* Search(int key);						//按关键字搜索
	void Insert(int key);						//按关键字插入
	void Delete(int key);						//按关键字删除
	void Ascend(node* t);						//升序输出
	void getbalance(node* t);					//计算平衡因子
	int getheight(node* t);						//计算树的高度
	void test();								//测试用函数
	node* getroot();							//得到节点
	node* standard(node* t);					//标准化AVL树
	int gettsize();								//得到长度
	void l_lroll(node* t);						//LL旋转
	void r_rroll(node* t);						//RR旋转
	void l_rroll(node* t);						//LR旋转
	void r_lroll(node* t);						//RL旋转
	void merge(AVLtree av);						//合并两棵AVL树
	void divide(node* t, AVLtree b);						//将一棵AVL树分裂
	node* iterator(node* t, node* y);
	void erase(int key);
	node* max_right(node* t);
	void Insert(node* t);
	void getdivide(int key, node* t);
	int getdiv(node* t);
	bool empty();
	void calculatePosition();
	void updateDistanceToRoot(node* x);
	node* succ(node *x);
	void display();
private:
	node * root;
	int height;
	int tsize;
	int i_size;
};

AVLtree::AVLtree(int size)
{
	root = NULL;
	tsize = 0;
	i_size = size;
}

void AVLtree::buildtree(int* key)
{
	root = new node;
	root->element.first = key[0];
	root->element.second = (char)(key[0] + 96);
	root->n_side = -1;
	root->divd = 0;
	root->leftchild = root->rightchild = NULL;
	tsize = 1;
	for (int i = 1; i<i_size; i++)
	{
		Insert(key[i]);
		//display();
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

int AVLtree::getdiv(node* t)
{
	int div_num = 0;
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		if (t->divd == 1)
		{
			div_num++;
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
	return div_num;
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
	node* current = t->leftchild;
	while (current->rightchild != NULL)
	{
		current = current->rightchild;
	}
	return current;
}

void AVLtree::Insert(node* tp)
{
	int key = tp->element.first;
	node* current = root;
	while (1)
	{
		if (key < current->element.first&&current->leftchild != NULL)
		{
			current = current->leftchild;
		}
		if (key < current->element.first&&current->leftchild == NULL)
		{
			current->leftchild = tp;
			tp->n_side = -1;
			tp->divd = 0;
			tp->leftchild = tp->rightchild = NULL;
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
			current->rightchild = tp;
			tp->n_side = -1;
			tp->divd = 0;
			tp->leftchild = tp->rightchild = NULL;
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
	}
	tsize++;
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
			if (max_l->leftchild != NULL)
			{
				max_l->leftchild = t->leftchild;
			}
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
		else if ((t->rightchild != NULL && t->leftchild == NULL) || (t->leftchild != NULL && t->rightchild == NULL))
		{
			node* chil = t->leftchild == NULL ? t->rightchild : t->leftchild;
			if (t == root)
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
		tsize--;
	}
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
		if (key < current->element.first/*&&current->leftchild != NULL*/)
		{
			current = current->leftchild;
			continue;
		}
		if (key > current->element.first/*&&current->rightchild != NULL*/)
		{
			current = current->rightchild;
			continue;
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
			current->leftchild->divd = 0;
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
			current->rightchild->divd = 0;
			current->rightchild->leftchild = current->rightchild->rightchild = NULL;
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
	}
	tsize++;
}

void AVLtree::Delete(int key)
{
	node* t = Search(key);
	if (t != NULL)
	{
		node* parent = iterator(root, t);
		erase(key);
		getbalance(parent);
		if (parent->balance == 1 || parent->balance == -1)
		{
			return;
		}
		if (parent->balance == 2 || parent->balance == -2)
		{
			node* t = standard(parent);
			if (t->balance == 2)
			{
				if (t->leftchild->balance == 1 || t->leftchild->balance == 0)
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
				if (t->rightchild->balance == 1 || t->rightchild->balance == 0)
				{
					r_lroll(t);
				}
				else if (t->rightchild->balance == -1)
				{
					r_rroll(t);
				}
			}
		}
		if (parent->balance == 0)
		{
			node* grand = standard(root);
			if (grand->balance == 2)
			{
				if (grand->leftchild->balance == 1)
				{
					l_lroll(grand);
				}
				else if (grand->leftchild->balance == -1)
				{
					l_rroll(grand);
				}
			}
			if (grand->balance == -2)
			{
				if (grand->rightchild->balance == 1)
				{
					r_lroll(grand);
				}
				else if (grand->rightchild->balance == -1)
				{
					r_rroll(grand);
				}
			}
		}
		if (t == root)
		{
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
		}
	}
}

void AVLtree::Ascend(node* t)
{
	if (t)
	{
		Ascend(t->leftchild);
		cout << t->element.first << " ";
		Ascend(t->rightchild);
	}
}

void AVLtree::merge(AVLtree av)
{
	int sizeb = 0;
	store headb;
	headb.contant = NULL;
	headb.next = NULL;
	store* currentb = &headb;
	Queue qu(av.gettsize());
	node* t = av.root;
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		currentb->next = new store;
		currentb->next->contant = t->element.first;
		currentb = currentb->next;
		sizeb++;
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
	int* bs = new int[sizeb];
	store* currentb_2 = headb.next;
	for (int i = 0; i < sizeb; i++)
	{
		bs[i] = currentb_2->contant;
		currentb_2 = currentb_2->next;
	}
	for (int i = 0; i < sizeb; i++)
	{
		Insert(bs[i]);
	}
}

void AVLtree::getdivide(int key, node* t)
{
	if (t)
	{
		getdivide(key, t->leftchild);
		{
			int y = t->element.first;
			if (y > key)
			{
				t->divd = 1;
			}
		}
		getdivide(key, t->rightchild);
	}
}

void AVLtree::divide(node* t, AVLtree b)
{
	int sizea = 0, sizeb = 0;
	store heada;
	heada.contant = NULL;
	heada.next = NULL;
	store* currenta = &heada;
	store headb;
	headb.contant = NULL;
	headb.next = NULL;
	store* currentb = &headb;
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		if (t->divd == 0)
		{
			currenta->next = new store;
			currenta->next->contant = t->element.first;
			currenta = currenta->next;
			sizea++;
		}
		if (t->divd == 1)
		{
			currentb->next = new store;
			currentb->next->contant = t->element.first;
			currentb = currentb->next;
			sizeb++;
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
	int* a = new int[sizea];
	store* currenta_2 = heada.next;
	for (int i = 0; i < sizea; i++)
	{
		a[i] = currenta_2->contant;
		currenta_2 = currenta_2->next;
	}
	int* bs = new int[sizeb];
	store* currentb_2 = headb.next;
	for (int i = 0; i < sizeb; i++)
	{
		bs[i] = currentb_2->contant;
		currentb_2 = currentb_2->next;
	}
	b.buildtree(bs);
	for (int i = 0; i < sizea; i++)
	{
		Delete(a[i]);
	}
}

void Temp(AVLtree av, void (AVLtree::*function)(int), node* t)
{
	Queue qu(av.gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		if (t->divd = 1)
		{
			(av.*function)(t->element.first);
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

bool AVLtree::empty()
{
	if (root == NULL)
	{
		return 0;
	}
	else
		return 1;
}

node* AVLtree::succ(node* x)
{

	if (x->rightchild != NULL)
	{
		x = x->rightchild;
		while (x->leftchild != NULL)
			x = x->leftchild;
	}
	else
	{
		if (x == root)
		{
			return NULL;
		}
		node* parent = iterator(root, x);
		while (parent != x && parent->leftchild != x)
		{
			x = parent;
			parent = iterator(root, x);
		}
		parent = iterator(root, x);
		if (parent == x)
		{
			return NULL;
		}
		x = parent;
	}
	return x;
}

void AVLtree::updateDistanceToRoot(node* x)
{
	if (!x) return;
	int i = 0;
	node* p = x;
	while (p != root)
	{
		p = iterator(root, p);
		++i;
	}

	x->distance_to_root = i ;

	Queue q(gettsize());
	q.createqueue();
	q.push(x);
	while (q.empty())
	{
		node* parent = iterator(root, x);
		if (x != root)
		{
			x->distance_to_root = parent->distance_to_root + 1;
		}
		if (x->leftchild != NULL)
		{
			q.push(x->leftchild);
		}
		if (x->rightchild != NULL)
		{
			q.push(x->rightchild);
		}
		q.pop();
		x = q.getqueue();
	}

}

void AVLtree::calculatePosition()
{
	//计算垂直位置
	updateDistanceToRoot(root);


	//计算水平位置
	int count = 0;
	node* x = root;
	//找到中序遍历的第一个结点
	while (x && x->leftchild != NULL)
		x = x->leftchild;
	//按照中序遍历的次序记录结点访问次序
	while (x != NULL)
	{
		x->horizontal_position = ++count;
		x->horizontal_position *= 4;    //水平位置放缩4倍 命令行显示时结点之间的空隙4个字符
		x = succ(x);
	}


}

void AVLtree::display()
{
	calculatePosition();
	int nowheight = 0;
	int lastheight = 0;
	int levelcount = 0;
	int i = 0;
	node* t = root;
	Queue qu(gettsize());
	qu.createqueue();
	qu.push(t);
	while (qu.empty())
	{
		long long int tmpposi;
		if (t)
		{
			nowheight = t->distance_to_root;
			if (nowheight != lastheight)
			{
				lastheight = nowheight;
				cout << endl;
				levelcount = 0;
			}
			for (i = levelcount; i < posilchild(t); ++i)
			{
				printf(" ");
			}
			int firstprint = 1;
			for (; i < t->horizontal_position; ++i)
			{
				if (firstprint)
				{
					printf("_");
					firstprint = 0;
				}
				else
					printf("_");
			}
			tmpposi = cout.tellp();
			cout << t->element.first;
			long long int tellpppp = cout.tellp() - tmpposi;
			levelcount += (int)(tellpppp);

			levelcount += t->horizontal_position - levelcount;

			for (i = levelcount; i < posirchild(t); ++i)
			{
				if (i == posirchild(t) - 1)
					printf("_");
				else
					printf("_");
			}
			levelcount = i;
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
	cout << endl;
}


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
		tr.display();
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