#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
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
	huffman(node** t,char* txt);
	void maketree();
	void pop(node* t);
	void push(node* t);
	node* select();
	void path(char a,node* current);
	void output();
protected:
	node * * root;
	node* first;
	int listsize;
	int routine[20];
	int steps;
	char text[20];
};

huffman::huffman(node** t,char* txt)
{
	listsize = -1;
	steps = 0;
	for (int i = 0; txt[i] != '\0'; i++)
	{
		text[i] = txt[i];
	}
	root = new node*[300];
	for (int i = 0; i < 300; i++)
	{
		root[i] = NULL;
	}
	for (int i = 0; i < 300; i++)
	{
		if (t[i]->tag == 1)
		{
			root[i] = t[i];
			listsize++;
		}
	}
	maketree();
	first = root[0];
	for (int i = 0; txt[i] != '\0'; i++)
	{
		steps = 0;
		path(txt[i], first);
	}
}

void huffman::pop(node* t)
{
	if (listsize == -1)
	{
		cout << "the pop is error" << endl;
	}
	else
	{
		int n;
		for (int i = 0; i <= listsize; i++)
		{
			if (root[i] == t)
			{
				n = i;
				break;
			}
		}
		for (int i = n; i <= listsize; i++)
		{
			root[i] = root[i + 1];
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
	root[listsize] = t;
	listsize++;
}

node* huffman::select()
{
	int t = root[0]->frequency;
	node* r = new node;
	//int j;
	for (int i = 1; i <= listsize; i++)
		{
			if (root[i]->frequency < t)
			{
				t = root[i]->frequency;
				r = root[i];
			}
		}
	return r;
}

void huffman::maketree()
{
	while (listsize != 0)
	{
		node* t1 = new node;
		t1 = select();
		pop(select());
		node* t2 = new node;
		t2 = select();
		pop(select());
		node* merge = new node;
		merge->frequency = t1->frequency + t2->frequency;
		merge->tag = 1;
		merge->leftchild = t1;
		merge->rightchild = t2;
		push(merge);
	}
}

void huffman::path(char a,node* current)
{
	if (current->tag == 1 && current->element == a)
	{
		output();
	}
	if (current->leftchild != NULL)
	{
		routine[steps] = 0;
		steps++;
		path(a, current->leftchild);
		steps--;
	}
	if (current->rightchild != NULL)
	{
		routine[steps] = 1;
		steps++;
		path(a, current->rightchild);
		steps--;
	}
}

void huffman::output()
{
	for (int i = 0; i < steps; i++)
	{
		cout << routine[i];
	}
	cout << endl;
}

node** statistic(char* a)
{
	node** b = new node*[300];
	for (int i = 0; i < 300; i++)
	{
		b[i]->frequency = 0;
		b[i]->leftchild = b[i]->rightchild = NULL;
		b[i]->tag = 0;
		b[i]->element = '0';
	}
	for (int i = 0; a[i]!='\0'; i++)
	{
		for (int j = 0; j < 300; j++)

		{
			if (b[j]->element == a[i])
			{
				b[j]->frequency++;
				break;
			}
			else

			{
				for (int t = 0; t < 300; t++)
				{
					if (b[j]->tag == 0)
					{
						b[j]->element = a[i];
						b[j]->tag = 1;
						b[j]->frequency++;
						break;
					}
				}
			}
		}
	}
	return b;
}

int main()
{
	char a[] = "mdzz";
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