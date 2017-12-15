#include<iostream>
#include<stdlib.h>
using namespace std;

struct node//�����ڵ����ͣ������ڵ��Ԫ�أ������������ַ����ֵ�Ƶ�ʣ��Ƿ���ֹ��ı��
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
	huffman(node** t,char* txt);//���캯���������������
	void maketree();//�Ըո��γɵ����޸ģ��γɻ�������
	void pop(node* t);//������
	void push(node* t);//�����
	node* select();//ѡ��Ƶ����С�Ľڵ�
	void path(char a,node* current);//��¼Ѱ��ĳ���ڵ��·����������
	void output();//�������
protected:
	node * * root;//�ⲿ�ڵ�����
	node* first;//���ڵ�
	int listsize;//���еĳ���
	int routine[20];//��¼���������
	int steps;//��¼Ѱ���ⲿ�ڵ�Ĳ���
	char text[20];//�������ȥ���ַ�����¼����
};

huffman::huffman(node** t,char* txt)
{
	listsize = -1;//�Զ��г��ȳ�ʼ��
	steps = 0;//������ʼ��
	for (int i = 0; txt[i] != '\0'; i++)//���ַ�����¼����
	{
		text[i] = txt[i];
	}
	root = new node*[300];
	for (int i = 0; i < 300; i++)
	{
		root[i] = NULL;//�Կյ��ⲿ�ڵ��ʼ��
	}
	for (int i = 0; i < 300; i++)//��ֵ���������ַ����γɵ��ⲿ�ڵ������鸳���ⲿ�ڵ�
	{
		if (t[i]->tag == 1)
		{
			root[i] = t[i];
			listsize++;
		}
		//t++;
	}
	maketree();//�γɻ�������
	//first = root[0];
	for (int i = 0; txt[i] != '\0'; i++)
	{
		steps = 0;//ÿ�γ�ʼ������
		path(txt[i], first);//�������
	}
}

void huffman::pop(node* t)//���Ӳ���
{
	int n = -1;
	if (listsize == -1)
	{
		cout << "the pop is error" << endl;
	}
	else
	{
		
		for (int i = 0; i <= listsize; i++)//����Ѱ����Ҫ���ӵ�����
		{
			if (root[i] == t)
			{
				n = i;
				break;
			}
		}
		for (int s = n; s < listsize; s++)
		{
			root[s] = root[s + 1];//����Ҫ���ӵĽڵ����Ľڵ�ǰ��
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
	root[listsize] = t;//�����γɵĶ���������ڵ��������
	listsize++;
}

node* huffman::select()//�����ҳ����ִ�����С�Ľڵ�
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

void huffman::maketree()//�γɻ�������
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
		pop(s2);//�ҳ�����Ƶ����С�Ľڵ㣬����
		node* merge = new node;
		merge->frequency = t1->frequency + t2->frequency;
		merge->tag = 1;
		merge->leftchild = t1;
		merge->rightchild = t2;
		push(merge);//���������ڵ�����µ������������뵽��������
		first = merge;
	}
}

void huffman::path(char a,node* current)//�ݹ鷽������¼ĳ���ⲿ�ڵ��Ӧ�ַ��Ļ���������
{
	if (current->tag == 1 && current->element == a)
	{
		output();
	}
	if (current->leftchild != NULL)//��������Ϊ0
	{
		routine[steps] = 0;
		steps++;
		path(a, current->leftchild);
		steps--;
	}
	if (current->rightchild != NULL)//��������Ϊ1
	{
		routine[steps] = 1;
		steps++;
		path(a, current->rightchild);
		steps--;
	}
}

void huffman::output()//���·����������������
{
	for (int i = 0; i < steps; i++)
	{
		cout << routine[i];
	}
	cout << endl;
}

node** statistic(char* a)//ͳ���ַ�����ÿ���ַ����ֵ�Ƶ�ʣ�������һ���ڵ��͵�����
{
	node** b = new node*[300];
	for (int i = 0; i < 300; i++)
	{
		b[i] = new node;
	}
	for (int i = 0; i < 300; i++)//�Ƚ��г�ʼ��
	{
		b[i]->frequency = 0;
		b[i]->leftchild = b[i]->rightchild = NULL;
		b[i]->tag = 0;
		b[i]->element = '0';
	}
	b[0]->element = a[0];//�Ե�һ�����鸳ֵ
	b[0]->frequency = 1;
	b[0]->tag = 1;
	int bsize = 1;
	int isize = 1;
	while (1)
	{
		bool exist = 0;
		if (a[isize] == '\0')//��������
		{
			break;
		}
		for (int j = 0; j < bsize; j++)
		{
			if (b[j]->element == a[isize])//����������ж�Ӧ��Ԫ�أ����ýڵ��Ƶ�ʼ�1
			{
				b[j]->frequency++;
				isize++;
				exist = 1;
				break;
			}
			if (exist == 0)//�������ڵ�û�б��ı����������ַ�����Ϣ��¼���ڵ���
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