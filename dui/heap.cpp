#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	char element;//节点中的元素
	node* leftchild;//左子树
	node* rightchild;//右子树
	int tag;//标签，记录当前元素为第i个
};

class maxheap
{
public:
	maxheap(char* a, int size);//构造函数
	void insert(char a);//插入函数
	void erase();//删除函数
				 //void level(node* t);//函数
	void output();//输出函数
	void sort();//函数
	void middle(node* t);
	void push(node* t);//入队列
	void pop();//出队列
	bool empty();//判断队列是否为空
	node* getroot();//返回根节点
	void restruct();
	node* getqueue();
	void initialize();
	node* gettag(int n);
	void level(node* t);
	//void restruct_que();

private:
	node * root;//根节点
	node** queue;//层次遍历赋值用到的队列
	int listsize;//树的长度
	int que_size;
	int heapsize;

};

maxheap::maxheap(char* a, int size)//初始化，定义节点为空
{
	listsize = -1;
	//que_size = size;
	queue = new node*[200];
	root = new node;
	node* current = root;
	int i = 0;
	push(current);
	while (1)
	{
		if (i < size - 1)
		{
			current->leftchild = new node;
			current->leftchild->leftchild = NULL;
			current->leftchild->rightchild = NULL;
			push(current->leftchild);
			i++;
		}
		else
		{
			break;
		}
		if (i < size)
		{
			current->rightchild = new node;
			current->rightchild->rightchild = NULL;
			current->rightchild->leftchild = NULL;
			push(current->rightchild);
			i++;
		}
		else
		{
			break;
		}
		pop();
		current = getqueue();
	}
	restruct();
	i = 0;
	current = root;
	push(current);
	while (empty())
	{
		current->element = a[i];
		i++;
		current->tag = i;
		if (current->leftchild != NULL)
		{
			push(current->leftchild);
		}
		if (current->rightchild != NULL)
		{
			push(current->rightchild);
		}
		pop();
		current = getqueue();
	}
	heapsize = i;
}

void maxheap::restruct()
{
	listsize = -1;
	/*queue = new node*[200];
	for (int i = 0; i < 200; i++)
	{
	queue[i] = NULL;
	}*/
}

/*void maxheap::restruct_que()
{
for (int i = 0; i < 200; i++)
{
delete queue[i];
}
}*/

bool maxheap::empty()
{
	if (listsize == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void maxheap::push(node* t)
{
	if (listsize == -1)
	{
		queue[0] = t;
		listsize++;
	}
	else
	{
		for (int i = listsize; i >= 0; i--)
		{
			queue[i + 1] = queue[i];
		}
		queue[0] = t;
		listsize++;
	}
}

void maxheap::pop()
{
	if (listsize == -1)
	{
		cout << "the queue is empty" << endl;
	}
	else
	{
		listsize--;
	}
}

node* maxheap::getqueue()
{
	return queue[listsize];
}

void maxheap::output()
{
	cout << heapsize << endl;
	//cout << level(2)->element << endl;

}

void maxheap::middle(node *t)//中序遍历，输出节点的元素
{
	if (t)
	{
		middle(t->leftchild);
		//char vis = visit();
		cout << t->element << " " << t->tag << " ";
		middle(t->rightchild);
	}
}

node* maxheap::getroot()
{
	return root;
}

void maxheap::initialize()
{
	int i;
	for (int i = heapsize; i > 0; i--)
	{
		node* current = gettag(i);
		int j = i / 2;
		while (j > 0)
		{
			node* parent = gettag(j);
			if (parent->element < current->element)
			{
				char t = parent->element;
				parent->element = current->element;
				current->element = t;
			}
			j = j / 2;
			current = parent;
		}
	}
}

node* ::maxheap::gettag(int n)
{
	node* t = root;
	push(t);
	while (empty())
	{
		if (t->tag == n)
		{
			node* goal = new node;
			goal = t;
			return goal;
		}
		else
		{
			if (t->leftchild != NULL)
			{
				push(t->leftchild);
			}
			if (t->rightchild != NULL)
			{
				push(t->rightchild);
			}
			pop();
			t = getqueue();
		}
	}
}

void maxheap::insert(char a)
{
	heapsize++;
	node* put = new node;
	put->element = a;
	put->tag = heapsize;
	put->leftchild = put->rightchild = NULL;
	int n = put->tag;
	node* parent = gettag(n / 2);
	switch (n % 2)
	{
	case 0:
		parent->leftchild = put;
		break;
	case 1:
		parent->rightchild = put;
		break;
	default:
		break;
	}
	initialize();
}

void maxheap::level(node* t)//层次遍历，按次序进入队列，同时按顺序输出
{
	restruct();
	push(t);
	while (empty())
	{
		cout << t->element << " ";
		if (t->leftchild != NULL)
		{
			push(t->leftchild);
		}
		if (t->rightchild != NULL)
		{
			push(t->rightchild);
		}
		pop();
		t = getqueue();
	}

}

void maxheap::erase()
{
	node* current = gettag(heapsize);
	root->element = current->element;
	int n = heapsize;
	node* parent2 = gettag(n / 2);
	switch (n % 2)
	{
	case 0:
		parent2->leftchild = NULL;
		break;
	case 1:
		parent2->rightchild = NULL;
		break;
	default:
		break;
	}
	delete current;
	heapsize--;
	initialize();
}

void maxheap::sort()
{
	for (int i = 0; i < heapsize; i++)
	{
		erase();
	}
	delete root;
}



int main()
{
	char* a = new char[200];
	cin >> a;
	cout << "the input order is:";
	cout << a;
	cout << endl;
	maxheap ma(a, 3);
	cout << "the sequence is:";
	ma.middle(ma.getroot());
	cout << endl;
	ma.output();
	cout << endl;
	ma.initialize();
	ma.middle(ma.getroot());
	cout << endl;
	ma.insert('w');
	//ma.middle(ma.getroot());
	ma.level(ma.getroot());
	cout << endl;
	ma.erase();
	//ma.level(ma.getroot());
	ma.middle(ma.getroot());
	ma.sort();
	system("pause");
	return 0;
}