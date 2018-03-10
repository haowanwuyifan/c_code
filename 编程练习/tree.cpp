#include<iostream>
#include<stdlib.h>

using namespace std;

struct node//创建节点结构
{
	char element;
	node* lefttree;//左子树
	node* righttree;//右子树
};

class tree
{
public:
	void front(node *t);//前序搜索
	void middle(node *t);//中序搜索
	void back(node *t);//后序搜索
	//char visit();//dayinyuansu
	int count(node* t);//计算数量
	int height(node* t);//计算高度
	/*void inputf(char* a, int size);//前序插入
	void inputm(char* a, int size);//后序插入*/
	void level(node* t);//层次遍历，通过层次遍历对二叉树赋值
	tree();//构造函数
	void create(char a);//对二叉树的元素赋值
	//char getre();
	node* getroot();//返回根节点
	bool empty();//判断队列是否为空
	void pop();//弹出队列
	void push(node* t);//加入队列
	void createqueue();//创建队列
	node* getqueue();//返回队列的节点

protected:
	node* root;
	node** queue;
	int listsize;
	int he;
};

tree::tree()//初始化
{
	//4listsize = 0;
	he = 0;
	//root = new node;
	root = NULL;
	//root->righttree = NULL;
	//root->lefttree = NULL;
}

/*char tree::visit()//调用访问函数
{
	return this->root->element;
}*/

void tree::front(node *t)//前序遍历，输出节点的元素
{
	if (t)
	{
		//char vis = visit();
		cout << t->element<<" ";
		front(t->lefttree);
		front(t->righttree);
	}
}

void tree::middle(node *t)//中序遍历，输出节点的元素
{
	if (t)
	{
		middle(t->lefttree);
		//char vis = visit();
		cout << t->element << " ";
		middle(t->righttree);
	}
}

void tree::back(node *t)//后序遍历，输出节点的元素
{
	if (t)
	{
		back(t->lefttree);
		back(t->righttree);
		//char vis = visit();
		cout << t->element << " ";
	}
}

int tree::count(node* t)//计算二叉树节点的个数
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return count(t->lefttree) + count(t->righttree) + 1;//递归方法，通过每次返回实验计数
	}
}

int tree::height(node* t)//计算二叉树的高度
{
	int i, j;
	if (!t)
		return 0;
	if (t->lefttree)
	{
		i = height(t->lefttree);
	}
	else
	{
		i = 0;
	}
	if (t->righttree)
	{
		j = height(t->righttree);
	}
	else
	{
		j = 0;
	}
	return (i > j) ? i+1 : j+1;//递归方法，通过每次返回计数
}

/*void tree::inputf(char* a, int size)
{
	
}

void tree::inputm(char* a, int size)
{

}*/

void tree::create(char a)
{
	node* newnode =new node;
	newnode->element = a;
	newnode->lefttree = newnode->righttree = NULL;
	if (root == NULL)//如果根节点为空，将新定义的节点赋给根节点
	{
		root = newnode;
	}
	else//否则，将输入的元素和当前所指的节点的元素比较，如果新输入的小于当前所指的，则将其插入到左子树，否则插入到右子树
	{
		node *back=NULL;
		node *current = root;
		while (current!=NULL)
		{
			back = current;
			if (current->element > a)
			{
				current = current->lefttree;
			}
			else
			{
				current = current->righttree;
			}
		}
		if (back->element > a)
		{
			back->lefttree = newnode;
		}
		else
		{
			back->righttree = newnode;
		}
	}
}

node* tree::getroot()
{
	return root;
}

node* tree::getqueue()
{
	return queue[listsize];
}


bool tree::empty()
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

void tree::push(node* t)
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

void tree::pop()
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

void tree::createqueue()
{
	listsize = -1;
	queue = new node*[200];
	for (int i = 0; i < 200; i++)
	{
		queue[i] = NULL;
	}
}




/*char tree::getre()
{
	return root->element;
}*/

void tree::level(node* t)//层次遍历，按次序进入队列，同时按顺序输出
{
	push(t);
	while (empty())
	{
		cout << t->element << " ";
		if (t->lefttree!=NULL)
		{
			push(t->lefttree);
		}
		if (t->righttree!=NULL)
		{
			push(t->righttree);
		}
		pop();
		t = getqueue();
	}
	
}


int main()
{
	tree t;
	char a[20] /*= "a+b/c+d"*/;
	//int k = (sizeof(a) - 1) / sizeof(a[0]);
	//cout << k << endl;
	cin >> a;
	int i = 0;
	while (a[i]!='\0')
	{
		
		i++;
	}
	cout << "the input order is:";
	for (int j = 0; j < i; j++)
	{
		t.create(a[j]);
		cout << a[j] << " ";
	}
	cout << endl;
	//cout << t.getre() << endl;
	cout << "前序遍历结果：";
	t.front(t.getroot());
	cout << endl;
	cout << "中序遍历结果：";
	t.middle(t.getroot());
	cout << endl;
	cout << "后序遍历结果：";
	t.back(t.getroot());
	cout << endl;
	t.createqueue();
	cout << "层次遍历结果：";
	t.level(t.getroot());
	cout << endl;
	cout << "the number of tree is:" << t.count(t.getroot()) << endl;
	cout << "the height of tree is:" << t.height(t.getroot()) << endl;
	system("pause");
	return 0;
}