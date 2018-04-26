#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct node
{
	pair<string,string> relations;
	node* next;
};

class stack
{
public:
	stack();
	void createstack(int size);
	bool empty();
	void push(int t);
	void pop();
	int getst();
	void clear();
private:
	int stsize;
	int* stac;
};

stack::stack()
{
	stsize = -1;
}

void stack::createstack(int size)
{
	if (size > 0)
	{
		stac = new int[size];
	}
}

bool stack::empty()
{
	if (stsize == -1)
	{
		return true;
	}
	else if (stsize > -1)
	{
		return false;
	}
}

void stack::push(int t)
{
	stsize++;
	stac[stsize] = t;
}

void stack::pop()
{
	stsize--;
}

int stack::getst()
{
	return stac[stsize];
}

void stack::clear()
{
	stsize = -1;
}

class schedule
{
public:
	schedule(int size);
	void calin();
	void setin();
	void getpath(node* a);
	void display();
	bool getin();
private:
	int** path;
	int _size;
	int* point;
	int* inde;
	int order;
	stack st;
};

schedule::schedule(int size)
{
	_size = size;
	order = 0;
}

void schedule::getpath(node* a)
{
	node* t = a;
	for (int i = 0; i < _size; i++)
	{
		path = new int*[_size];
	}
	for (int j = 0; j < _size; j++)
	{
		path[j] = new int[_size];
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			path[i][j] = 0;
		}
	}
	while (t != NULL)
	{
		path[a->relations.first - 1][a->relations.second - 1] = 1;
		t->next->next;
	}
		
}

void schedule::calin()
{
	point = new int[_size];
	for (int i = 0; i < _size; i++)
	{
		point[i] = 0;
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (path[j][i] == 1)
			{
				point[i]++;
			}
		}
	}
}

void schedule::setin()
{
	st.createstack(_size);
	if (st.empty())
	{
		for (int i = 0; i < _size; i++)
		{
			if (point[i] == 1)
			{
				st.push(i);
				for (int j = 0; j < _size; j++)
				{
					if (path[i][j] == 1)
					{
						point[j]--;
					}
				}
			}

		}
	}
	else
	{
		st.clear();
		for (int i = 0; i < _size; i++)
		{
			if (point[i] == 1)
			{
				st.push(i);
				for (int j = 0; j < _size; j++)
				{
					if (path[i][j] == 1)
					{
						point[j]--;
					}
				}
			}

		}
	}
}

bool schedule::getin()
{
	inde = new int[_size];
	while (!st.empty())
	{
		inde[order++] = st.getst();
		st.pop();
	}
	return order == _size;
}

void schedule::display()
{
	for (int j = order - 1; j >= 0; j--)
	{
		cout << inde[j] << " ";
	}
	cout << endl;
}

int main()
{
	//cout << "请输入节点间关系：" << endl;
	node head;
	head.next = NULL;
	node* current = &head;
	string m,n;
	string a[1024];
    a.
	int size = 0;
	int tsize = 0;
	string tm;
	while (1)
	{
		cout << "请输入节点间关系：" << endl;
		cin >> m;
		cin >> n;
		if (m!=n)
		{
			if (tm.empty())
			{
				tm = m;
				tsize++;
			}
			else
			{
				if (tm != m)
				{
					tsize++;
				}
				if (tm != n)
				{
					tsize++;
				}
			}
			current->next = new node;
			current->next->relations.first = m;
			current->next->relations.second = n;
			current = current->next;
			size++;
		}
		else
		{
			cout << "输入有误！" << endl;
			break;
		}
	}
	node* t = head.next;
	pair<int, int>* a = new pair[tsize];


	schedule a(size);
	a.getpath(t);
	a.calin();
	a.setin();
	if (a.getin())
	{
		a.display();
		cout << "没有环路" << endl;
	}
	else
	{
		a.display();
		cout << "有环路" << endl;
	}
	system("pause");
	return 0;
}