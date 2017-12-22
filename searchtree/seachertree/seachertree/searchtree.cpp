#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	pair<int, char>  element;
	node* leftchild;
	node* rightchild;
	int index;
};

class searchtree
{
public:
	searchtree(int size);
	void buildtree(int* a);
	void insert(int);
	void erase(int);
	void getfirst(int);
	node* getsecond();
	node* getindex();
	void middleorder(node* t);
	node* getroot();
protected:
	node * root;
	int height;
	int listsize;
	int tsize;

};

searchtree::searchtree(int size)
{
	root = NULL;
	height = 0;
	listsize = 0;
	tsize = size;
}

void searchtree::buildtree(int* a)
{
	root = new node;
	root->element.first = a[0];
	root->element.second = (char)(a[0] + 96);
	root->leftchild = root->rightchild = NULL;
	for (int i = 1; i < tsize; i++)
	{
		node* current = root;
		while (1)
		{
			if (a[i] < current->element.first&&current->leftchild != NULL)
			{
				current = current->leftchild;
			}
			if (a[i] > current->element.first&&current->rightchild != NULL)
			{
				current = current->rightchild;
			}
			if (a[i] < current->element.first&&current->leftchild == NULL)
			{
				current->leftchild = new node;
				current->leftchild->element.first = a[i];
				current->leftchild->element.second = (char)(a[i] + 96);
				current->leftchild->leftchild = current->leftchild->rightchild = NULL;
				//i++;
				break;
			}
			if (a[i] > current->element.first&& current->rightchild == NULL)
			{
				current->rightchild = new node;
				current->rightchild->element.first = a[i];
				current->rightchild->element.second = (char)(a[i] + 96);
				current->rightchild->leftchild = current->rightchild->rightchild = NULL;
				//i++;
				break;
			}
		}


	}
}

void searchtree::insert(int key)
{
	node* store = new node;
	store->element.first = key;
	store->element.second = (char)(key + 96);
	store->leftchild = store->rightchild = NULL;
	node* current = root;
	//current->element.first = key;
	while (1)
	{
		if (current->element.first == key)
		{
			current->element.second = (char)(key + 96);
			break;
		}
		if (current->element.first > key&&current->leftchild != NULL)
		{
			current = current->leftchild;
			//break;
		}
		if (current->element.first < key&&current->rightchild != NULL)
		{
			current = current->rightchild;
			//break;
		}
		if (key < current->element.first&&current->leftchild == NULL)
		{
			current->leftchild = store;
			break;
		}
		if (key > current->element.first&&current->rightchild == NULL)
		{
			current->rightchild = store;
			break;
		}
	}
	tsize++;
}



//void searchtree::erase(int key)
//{
//	node* current = root;
//	node* back = current;
//	while (1)
//	{
//		if (current->element.first == key)
//		{
//			if(current.)
//		}
//	}
//}

void searchtree::getfirst(int key)
{
	node* current = root;
	while (1)
	{
		if (current->element.first == key)
		{
			cout << current->element.second;
			break;
		}
		if (current->leftchild == NULL && current->rightchild == NULL)
		{
			cout << "there is no key existed";
			break;
		}
		if (key < current->element.first&&current->leftchild != NULL)
		{
			current = current->leftchild;
		}
		if (key > current->element.first&&current->rightchild != NULL)
		{
			current = current->rightchild;
		}
	}
}



void searchtree::middleorder(node* t)
{
	if (t)
	{
		cout << t->element.second << ' ';
		middleorder(t->leftchild);
		middleorder(t->rightchild);
	}
}

node* searchtree::getroot()
{
	return root;
}

int main()
{
	int n;
	cout << "input the number of size:";
	cin >> n;
	int* a = new int[n];
	cout << "input the keys: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	searchtree st(n);
	st.buildtree(a);
	st.middleorder(st.getroot());
	/*int ins;
	cout << "if insert " ;
	cin >> ins;
	cout << "then ";
	st.insert(ins);
	st.middleorder(st.getroot());*/
	cout << endl;
	st.getfirst(4);
	//st.middleorder(st.getroot());
	system("pause");
	return 0;
}