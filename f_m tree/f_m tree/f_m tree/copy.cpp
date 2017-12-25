#include <string>
#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
	char data;
	struct node * leftchild;
	struct node * rightchild;
}bnode, *tree;
void CreateBiTree(tree & t, string front, string mid)	//t�Ǹ��ڵ㣬froΪǰ��midΪ����
{
	if (front.length() == 0)
	{
		t = NULL;
		return;
	}
	char current = front[0];//���ڵ㣬ÿ�εݹ鶼ȡ��һ��������ֵ��ͬ
	int index = mid.find(current);//���ڵ������������е�λ��
	string left_mid = mid.substr(0, index);	//����������������
	string right_mid = mid.substr(index + 1);//����������������
	int left_length = left_mid.length();//�������ĳ���
	int right_length = right_mid.length();//�������ĳ���
	string left_fro = front.substr(1, left_length);//��������ǰ������
	string right_fro = front.substr(1 + left_length);//��������ǰ������

	t=new bnode[sizeof(bnode)];

	if (t != NULL)
	{
		t->data = current;
		CreateBiTree(t->leftchild, left_fro, left_mid);//�ݹ鴴��������
		CreateBiTree(t->rightchild, right_fro, right_mid);//�ݹ鴴��������
	}
}
void beyond(tree & t)//����������
{
	if (t != NULL)
	{
		beyond(t->leftchild);
		beyond(t->rightchild);
		cout << t->data;
	}
}
int main()
{
	tree t;
	string fro = "abcdefg";
	string mid = "cbedafg";
	CreateBiTree(t, fro, mid);
	beyond(t);
	system("pause");
	return 0;
}
