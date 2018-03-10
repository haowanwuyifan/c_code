#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int dsize = 50;
int divisor = 961;

struct node//����ɢ�б�Ľṹ
{
	pair<int, int> element;
	int tag = 0;//int tag;
	node* next = NULL;
};

class chart
{
public:
	chart(pair<int, int> *a);//���캯��
	int search(int);//���Һ���
	int find(int);//���ĳ������ָ��Ԫ��
protected:
	node** dict;
};

chart::chart(pair<int, int> *a)
{
	// cout << "check1" << endl;
	dict = new node*[divisor];
	for (int i = 0; i < divisor; i++)
	{
		dict[i]=NULL;
		//dict[i]->tag = 0;��ʱֻ�����˸�ָ�룬��δ��ʼ�������Բ��ܸ�ֵ����
	//	dict[i]->next = NULL;  //dict[i]->next = new node;
	}
	for (int i = 0; i < dsize; i++)
	{
		//node* current = dict[a[i].first%divisor]->next;
		if(dict[a[i].first%divisor]==NULL)//if (dict[a[i].first%divisor]->tag == 0),ΪNULL����ʾ��û�ù�
		{
			dict[a[i].first%divisor] = new node;
			dict[a[i].first%divisor]->element = a[i];//current->element = a[i];
			dict[a[i].first%divisor]->next = new node;//current->next = new node;
			dict[a[i].first%divisor]->tag = 1;//current = current->next;
		}//�����Ĵ˴�Ϊ�գ���Ԫ�طŵ�����
		else//�����ҵ���Ӧ��λ�ã���Ԫ�ز�������
		{
			node* current = dict[a[i].first%divisor];
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = new node;
			current = current->next;
			current->element = a[i];
			/*
			current->element = a[i];
			if (i < dsize - 1)
			{
				current->next = new node;
				current = current->next;
			}
			else
				current = NULL;
			*/
		}
	}
}


int chart::search(int index)//��������
{
	int j = index%divisor;
	if (dict[j] == NULL) //�����λ��Ϊ�գ����-1���Ȳ�����
	{
		return -1;
	}
	//if (dict[j]->next == NULL)
	//	return -1;
	else//����������������Ƿ���Ҫ�����Ԫ�أ�����������û�����-1
	{
		node* current = dict[j];
		while (current != NULL)
		{
			if (current->element.first == index) {
				return current->element.second;
			}
			else {
				current = current->next;
			}
			/*return current->element.second;
			current = current->next;*/
		}
		return -1;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	pair<int, int> *a = new pair<int, int>[dsize];
	for (int i = 0; i < dsize; i++)
	{
		a[i].first = rand();
		a[i].second = a[i].first - 5;
		cout << "index: " << a[i].first << " " << "value: " << a[i].second << endl;
	}
	chart cha(a);
	int index;
	cout << "input the index:";
	cin >> index;
	cout << endl;
	cout << "the value is:";
	int t = cha.search(index);
	if (t == -1)
		cout << "cannot find" << endl;
	else
		cout << t;
	system("pause");
	return 0;
}