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
	void output();//输出函数
	void sort();//排序函数
	void middle(node* t);
	void push(node* t);//入队列
	void pop();//出队列
	bool empty();//判断队列是否为空
	node* getroot();//返回根节点
	void restruct();//刷新队列
	node* getqueue();//返回队列中对应的元素
	void initialize();//大根堆初始化
	node* gettag(int n);//返回对应位置的节点
	void level(node* t);//层次遍历
	//void restruct_que();

private:
	node * root;//根节点
	node** queue;//层次遍历赋值用到的队列
	int listsize;//树的长度
	int heapsize;//堆的大小
	char sequence[10];
};

maxheap::maxheap(char* a, int size)//初始化，定义节点为空
{
	listsize = -1;
	//que_size = size;
	queue = new node*[200];
	root = new node;
	node* current = root;
	int i = 1;
	push(current);//层次遍历的思想创建堆，并对节点赋空值
	while (1)
	{
		if (i < size )
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
	restruct();//刷新队列
	i = 0;
	current = root;
	push(current);//层次遍历的思想对堆进行赋值
	while (empty())
	{
		if (i < size)
		{
			current->element = a[i];
			i++;
			current->tag = i;
		}
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

void maxheap::restruct()//刷新队列
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

bool maxheap::empty()//判断是否为空
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

void maxheap::push(node* t)//入队列
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

void maxheap::pop()//出队列
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

node* maxheap::getqueue()//返回队列元素
{
	return queue[listsize];
}

void maxheap::output()//队列大小
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
		cout << t->element  << " ";
		middle(t->rightchild);
	}
}

node* maxheap::getroot()//返回根节点
{
	return root;
}

void maxheap::initialize()//堆初始化，从最后一个节点开始，判断它和它父树元素的大小，如果大于父树元素，将子树上移
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

node* ::maxheap::gettag(int n)//遍历返回特定的节点
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

void maxheap::insert(char a)//插入函数
{
	heapsize++;
	node* put = new node;
	put->element = a;
	put->tag = heapsize;
	put->leftchild = put->rightchild = NULL;
	int n = put->tag;
	node* parent = gettag(n / 2);//判断应该插入左子树还是右子树
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

void maxheap::erase()//删除操作
{
	node* current = gettag(heapsize);
	root->element = current->element;
	int n = heapsize;
	node* parent2 = gettag(n / 2);//将最后一个节点删除，然后插入到根节点
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
	initialize();//初始化堆
}

void maxheap::sort()//堆排序
{
	for (int i = 0; i < heapsize; i++)
	{
		node* temp = gettag(heapsize);
		erase();
		sequence[i] = temp->element;
	}
	delete root;
	cout << sequence;
}



int main()
{
	char* a = new char[100];
	cin >> a;
	cout << "the input order is:";
	cout << a;
	cout << endl;
	maxheap ma(a,4);
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