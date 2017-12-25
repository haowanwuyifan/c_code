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
void CreateBiTree(tree & t, string front, string mid)	//t是根节点，fro为前序，mid为中序
{
	if (front.length() == 0)
	{
		t = NULL;
		return;
	}
	char current = front[0];//根节点，每次递归都取第一个，但是值不同
	int index = mid.find(current);//根节点在中序序列中的位置
	string left_mid = mid.substr(0, index);	//左子树的中序序列
	string right_mid = mid.substr(index + 1);//右子树的中序序列
	int left_length = left_mid.length();//左子树的长度
	int right_length = right_mid.length();//右子树的长度
	string left_fro = front.substr(1, left_length);//左子树的前序序列
	string right_fro = front.substr(1 + left_length);//右子树的前序序列

	t=new bnode[sizeof(bnode)];

	if (t != NULL)
	{
		t->data = current;
		CreateBiTree(t->leftchild, left_fro, left_mid);//递归创建左子树
		CreateBiTree(t->rightchild, right_fro, right_mid);//递归创建右子树
	}
}
void beyond(tree & t)//后序遍历输出
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
