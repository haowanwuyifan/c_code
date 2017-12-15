#include<iostream>
#include<stdlib.h>
using namespace std;

struct node//创建节点类型，包括节点的元素，左右子树，字符出现的频率，是否出现过的标记
{
	char element;
	node* leftchild;
	node* rightchild;
	int frequency;
	int tag;
};

class huffman
{
public:
	huffman(node** t,char* txt);//构造函数，构造霍夫曼树
	void maketree();//对刚刚形成的树修改，形成霍夫曼树
	void pop(node* t);//出队列
	void push(node* t);//入队列
	node* select();//选出频率最小的节点
	void path(char a,node* current);//记录寻到某个节点的路径，即编码
	void output();//输出编码
protected:
	node * * root;//外部节点数组
	node* first;//根节点
	int listsize;//队列的长度
	int routine[20];//记录编码的数组
	int steps;//记录寻找外部节点的步数
	char text[20];//把输入进去的字符串记录下来
};

huffman::huffman(node** t,char* txt)
{
	listsize = -1;//对队列长度初始化
	steps = 0;//步数初始化
	for (int i = 0; txt[i] != '\0'; i++)//把字符串记录下来
	{
		text[i] = txt[i];
	}
	root = new node*[300];
	for (int i = 0; i < 300; i++)
	{
		root[i] = NULL;//对空的外部节点初始化
	}
	for (int i = 0; i < 300; i++)//赋值操作，将字符串形成的外部节点型数组赋给外部节点
	{
		if (t[i]->tag == 1)
		{
			root[i] = t[i];
			listsize++;
		}
		//t++;
	}
	maketree();//形成霍夫曼树
	//first = root[0];
	for (int i = 0; txt[i] != '\0'; i++)
	{
		steps = 0;//每次初始化步数
		path(txt[i], first);//输出编码
	}
}

void huffman::pop(node* t)//出队操作
{
	int n = -1;
	if (listsize == -1)
	{
		cout << "the pop is error" << endl;
	}
	else
	{
		
		for (int i = 0; i <= listsize; i++)//遍历寻找需要出队的数组
		{
			if (root[i] == t)
			{
				n = i;
				break;
			}
		}
		for (int s = n; s < listsize; s++)
		{
			root[s] = root[s + 1];//把需要出队的节点后面的节点前移
		}
		listsize--;
	}
}

void huffman::push(node* t)
{
	/*if (listsize == -1)
	{
		root[0] = t;
		listsize++;
	}
	else
	{
		for (int i = listsize; i >= 0; i--)
		{
			root[i + 1] = root[i];
		}
		root[0] = t;
		listsize++;
	}*/
	root[listsize] = t;//将新形成的二叉树插入节点二叉树组
	listsize++;
}

node* huffman::select()//遍历找出出现次数最小的节点
{
	int t = root[0]->frequency;
	node* r = new node;
	r = root[0];
	//int j;
	for (int i = 1; i <= listsize; i++)
		{
			
			node* q = root[i];
			int p = q->frequency;
			if (p < t)
			{
				t = p;
				r = q;
			}
		}
	return r;
}

void huffman::maketree()//形成霍夫曼树
{
	while (listsize != 0)
	{
		node* t1 = new node;
		node* s1 = select();
		t1 = select();
		pop(s1);
		node* t2 = new node;
		node* s2 = select();
		t2 = select();
		pop(s2);//找出两个频率最小的节点，出队
		node* merge = new node;
		merge->frequency = t1->frequency + t2->frequency;
		merge->tag = 1;
		merge->leftchild = t1;
		merge->rightchild = t2;
		push(merge);//将这两个节点组成新的树，将树插入到二叉树组
		first = merge;
	}
}

void huffman::path(char a,node* current)//递归方法，记录某个外部节点对应字符的霍夫曼编码
{
	if (current->tag == 1 && current->element == a)
	{
		output();
	}
	if (current->leftchild != NULL)//左子树记为0
	{
		routine[steps] = 0;
		steps++;
		path(a, current->leftchild);
		steps--;
	}
	if (current->rightchild != NULL)//右子树记为1
	{
		routine[steps] = 1;
		steps++;
		path(a, current->rightchild);
		steps--;
	}
}

void huffman::output()//输出路径，即霍夫曼编码
{
	for (int i = 0; i < steps; i++)
	{
		cout << routine[i];
	}
	cout << endl;
}

node** statistic(char* a)//统计字符串中每个字符出现的频率，并创建一个节点型的数组
{
	node** b = new node*[300];
	for (int i = 0; i < 300; i++)
	{
		b[i] = new node;
	}
	for (int i = 0; i < 300; i++)//先进行初始化
	{
		b[i]->frequency = 0;
		b[i]->leftchild = b[i]->rightchild = NULL;
		b[i]->tag = 0;
		b[i]->element = '0';
	}
	b[0]->element = a[0];//对第一个数组赋值
	b[0]->frequency = 1;
	b[0]->tag = 1;
	int bsize = 1;
	int isize = 1;
	while (1)
	{
		bool exist = 0;
		if (a[isize] == '\0')//结束条件
		{
			break;
		}
		for (int j = 0; j < bsize; j++)
		{
			if (b[j]->element == a[isize])//如果数组中有对应的元素，将该节点的频率加1
			{
				b[j]->frequency++;
				isize++;
				exist = 1;
				break;
			}
			if (exist == 0)//如果这个节点没有被改变过，将这个字符的信息记录到节点中
			{
				b[bsize]->element = a[isize];
				b[bsize]->frequency++;
				b[bsize]->tag = 1;
				bsize++;
				isize++;
			}
		}
	}
	//for (int i = 0; a[i]!='\0'; i++)
	//{
	//	int sign = 0;
	//	for (int j = 0; j < 300 && sign == 0; j++)
	//	{
	//		if (b[j]->element == a[i])
	//		{
	//			b[j]->frequency++;
	//			sign = 1;
	//		}
	//	}

	//		else if(b[j])

	//		{
	//			for (int t = j+1; t < 300; t++)
	//			{
	//				if (b[t]->tag == 0)
	//				{
	//					b[t]->element = a[i];
	//					b[t]->tag = 1;
	//					b[t]->frequency++;
	//					break;
	//				}
	//				else
	//				{
	//					cout << "error!" << endl;
	//				}
	//			}
	//			//break;
	//		}
	//		break;
	//	
	//}
	return b;
}

int main()
{
	char a[] = "live or dead";
	node** store;

	/*for (int i = 0; i < 300; i++)
	{
		store[i]->frequency = 0;
		store[i]->leftchild = store[i]->rightchild = NULL;
		store[i]->tag = 0;
		store[i]->element = '0';
	}*/
	store=statistic(a);
	huffman hu(store,a);
	system("pause");
	return 0;
}