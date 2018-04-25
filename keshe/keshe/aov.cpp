#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	pair<int, int> relations;
	node* next;
};

class stack
{
public:
	stack();
	void createstack(int size);
	bool empty();
	void push(int* t);
	void pop();
	int getst();
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
		return false;
	}
	else if (stsize > -1)
	{
		return true;
	}
}

void stack::push(int* t)
{
	stsize++;
	stac[stsize] = *t;
}

void stack::pop()
{
	stsize--;
}

int stack::getst()
{
	return stac[stsize];
}

class schedule
{
public:
	schedule(int size);
	void calin(pair<int, int>* a);
	void setin();
	void getpath();
	void display();
private:
	int _size;
	int* point;
	int* inde;
};

schedule::schedule(int size)
{
	_size = size;
	
}

void schedule::calin(pair<int, int>* a)
{
	point = new int[_size];
	for (int i = 0; i < _size; i++)
	{
		point[i] = 0;
	}
	for (int i = 0; i < _size; i++)
	{
		point[a[i].second]++;
	}
}

void schedule::setin()
{
	stack st;
	st.createstack
}

int main()
{

	system("pause");
	return 0;
}