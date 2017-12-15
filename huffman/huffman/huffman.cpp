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
		//t++;
	}
	maketree();
	//first = root[0];
	for (int i = 0; txt[i] != '\0'; i++)
	{
		steps = 0;
		path(txt[i], first);
	}
}

void huffman::pop(node* t)
{
	int n = -1;
	if (listsize == -1)
	{
		cout << "the pop is error" << endl;
	}
	else
	{
		
		for (int i = 0; i <= listsize; i++)
		{
			if (root[i] == t)
			{
				n = i;
				break;
			}
		}
		for (int s = n; s < listsize; s++)
		{
			root[s] = root[s + 1];
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

void huffman::maketree()
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
		pop(s2);
		node* merge = new node;
		merge->frequency = t1->frequency + t2->frequency;
		merge->tag = 1;
		merge->leftchild = t1;
		merge->rightchild = t2;
		push(merge);
		first = merge;
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
		b[i] = new node;
	}
	for (int i = 0; i < 300; i++)
	{
		b[i]->frequency = 0;
		b[i]->leftchild = b[i]->rightchild = NULL;
		b[i]->tag = 0;
		b[i]->element = '0';
	}
	b[0]->element = a[0];
	b[0]->frequency = 1;
	b[0]->tag = 1;
	int bsize = 1;
	int isize = 1;
	while (1)
	{
		bool exist = 0;
		if (a[isize] == '\0')
		{
			break;
		}
		for (int j = 0; j < bsize; j++)
		{
			if (b[j]->element == a[isize])
			{
				b[j]->frequency++;
				isize++;
				exist = 1;
				break;
			}
			if (exist == 0)
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