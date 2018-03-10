#include<iostream>
#include<stdlib.h>

using namespace std;

struct node//�����ڵ�ṹ
{
	char element;
	node* lefttree;//������
	node* righttree;//������
};

class tree
{
public:
	void front(node *t);//ǰ������
	void middle(node *t);//��������
	void back(node *t);//��������
	//char visit();//dayinyuansu
	int count(node* t);//��������
	int height(node* t);//����߶�
	/*void inputf(char* a, int size);//ǰ�����
	void inputm(char* a, int size);//�������*/
	void level(node* t);//��α�����ͨ����α����Զ�������ֵ
	tree();//���캯��
	void create(char a);//�Զ�������Ԫ�ظ�ֵ
	//char getre();
	node* getroot();//���ظ��ڵ�
	bool empty();//�ж϶����Ƿ�Ϊ��
	void pop();//��������
	void push(node* t);//�������
	void createqueue();//��������
	node* getqueue();//���ض��еĽڵ�

protected:
	node* root;
	node** queue;
	int listsize;
	int he;
};

tree::tree()//��ʼ��
{
	//4listsize = 0;
	he = 0;
	//root = new node;
	root = NULL;
	//root->righttree = NULL;
	//root->lefttree = NULL;
}

/*char tree::visit()//���÷��ʺ���
{
	return this->root->element;
}*/

void tree::front(node *t)//ǰ�����������ڵ��Ԫ��
{
	if (t)
	{
		//char vis = visit();
		cout << t->element<<" ";
		front(t->lefttree);
		front(t->righttree);
	}
}

void tree::middle(node *t)//�������������ڵ��Ԫ��
{
	if (t)
	{
		middle(t->lefttree);
		//char vis = visit();
		cout << t->element << " ";
		middle(t->righttree);
	}
}

void tree::back(node *t)//�������������ڵ��Ԫ��
{
	if (t)
	{
		back(t->lefttree);
		back(t->righttree);
		//char vis = visit();
		cout << t->element << " ";
	}
}

int tree::count(node* t)//����������ڵ�ĸ���
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return count(t->lefttree) + count(t->righttree) + 1;//�ݹ鷽����ͨ��ÿ�η���ʵ�����
	}
}

int tree::height(node* t)//����������ĸ߶�
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
	return (i > j) ? i+1 : j+1;//�ݹ鷽����ͨ��ÿ�η��ؼ���
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
	if (root == NULL)//������ڵ�Ϊ�գ����¶���Ľڵ㸳�����ڵ�
	{
		root = newnode;
	}
	else//���򣬽������Ԫ�غ͵�ǰ��ָ�Ľڵ��Ԫ�رȽϣ�����������С�ڵ�ǰ��ָ�ģ�������뵽��������������뵽������
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

void tree::level(node* t)//��α����������������У�ͬʱ��˳�����
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
	cout << "ǰ����������";
	t.front(t.getroot());
	cout << endl;
	cout << "������������";
	t.middle(t.getroot());
	cout << endl;
	cout << "������������";
	t.back(t.getroot());
	cout << endl;
	t.createqueue();
	cout << "��α��������";
	t.level(t.getroot());
	cout << endl;
	cout << "the number of tree is:" << t.count(t.getroot()) << endl;
	cout << "the height of tree is:" << t.height(t.getroot()) << endl;
	system("pause");
	return 0;
}