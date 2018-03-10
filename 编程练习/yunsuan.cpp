#include<iostream>
#include<stdlib.h>
using namespace std;

class stack//创建栈类
{
public:
	void insert_n(char);//对数字栈入栈
	void pop_n();//对数字栈出栈
	void insert_s(char);//对符号栈入栈
	void pop_s();//对符号栈出栈
	int getsign();//返回符号栈当前的指针位置
	int getnumber(int);//返回数字
	char getsing2(int);//返回对应位置的符号
	stack();//构造函数
	int listsize1;//数字栈的长度
	int listsize2;//符号栈的长度
	void insert_n(int);//插入数字
protected:
	int* number;
	char* sign;

};

stack::stack()//构造函数，对数字栈和符号栈初始化
{
	listsize1 = -1;
	listsize2 = -1;
	number = new int[10];
	sign = new char[10];

}
void stack::insert_n(int a)
{//对数字栈入栈的重载，加入数字型元素，列长+1
	listsize1++;
	number[listsize1] = a;
}
void stack::insert_n(char a)
{//对数字栈入栈，插入字符型数据，列长+1
		listsize1++;
		number[listsize1] = int(a) - 48;
}

void stack::pop_n()
{//对数字栈出栈
	listsize1--;
}

void stack::insert_s(char a)
{//符号栈入栈
	listsize2++;
	sign[listsize2] = a;
}

void stack::pop_s()
{//符号栈出栈
	listsize2--;
}

int stack::getsign()
{//返回符号栈当前的指针位置
	return listsize2;
}

int stack::getnumber(int i)
{//返回指针所指位置的数字
	return number[i];
}

char stack::getsing2(int i)
{//返回当前指针所指的符号
	return sign[i];
}

int compare(int i, int j)
{//判断符号的优先级，数组的行标和列标都对应“+”“-”“*”“/”“（”“）”“#”，
	//其中“#”为开始和结束的标识符，优先级大的，显示为1，小的显示为0，两个括号和两个#相遇优先级相等，其他数字为无法比较
	int a[7][7] = {
		{1,1,-1,-1,-1,1,1},
		{1,1,-1,-1,-1,1,1},
		{1,1,1,1,-1,1,1},
		{1,1,1,1,-1,1,1},
		{-1,-1,-1,-1,-1,0,6},
		{1,1,1,1,6,1,1},
		{-1,-1,-1,-1,-1,6,0}
	};
	return a[i][j];
}

int getindex(char a)
{//将每个符号对应到比较表中
	switch (a)
	{
	case '+':
		return 0;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 3;
		break;
	case '(':
		return 4;
		break;
	case ')':
		return 5;
		break;
	case '#':
		return 6;
		break;
	default:
		break;
	}
}

int main()
{
	char a[100];
	cin >> a;
	int m = 0;
	while (a[m] != '\0')
	{
		m++;
	}
	a[m] = '#';
	a[m + 1] = '\0';
	cout << endl;
	stack st;
	st.insert_s('#');//先放入一个#，等待最后一个#结束
	int i = 0;
	while (a[i] != '\0')//对输入的表达式判断，如果是数字，放入数字栈
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			st.insert_n(a[i]);
			i++;
		}
		else	if (a[i] < '0' || a[i] > '9')
		{
			if (st.getsign() == 0)//如果符号栈为空，将符号放入栈中
			{
				st.insert_s(a[i]);
				i++;
				continue;
			}
			else//非空的话，先判断优先级，在进行运算，将新的结果入栈
			{
				int a_ = getindex(st.getsing2(st.listsize2));
				int b = getindex(a[i]);
				int c = compare(a_, b);
				switch (c)
				{
				case 1://这种情况下，栈里面的符号的优先级大于栈外的符号的优先级，先进行栈外符号的运算，将结果存入栈中
				{
					if (st.getsing2(st.listsize2) == '+')
					{
						int n1 = st.getnumber(st.listsize1);
						int n2 = st.getnumber(st.listsize1 - 1);
						st.pop_n();
						st.pop_n();
						st.insert_n(n1 + n2);
						st.pop_s();

						break;
					}
					if (st.getsing2(st.listsize2) == '-')
					{
						int n1 = st.getnumber(st.listsize1);
						int n2 = st.getnumber(st.listsize1 - 1);
						st.pop_n();
						st.pop_n();
						st.insert_n(n2 - n1);
						st.pop_s();

						break;
					}
					if (st.getsing2(st.listsize2) == '*')
					{
						int n1 = st.getnumber(st.listsize1);
						int n2 = st.getnumber(st.listsize1 - 1);
						st.pop_n();
						st.pop_n();
						st.insert_n(n1 * n2);
						st.pop_s();

						break;
					}
					if (st.getsing2(st.listsize2) == '/')
					{
						int n1 = st.getnumber(st.listsize1);
						int n2 = st.getnumber(st.listsize1 - 1);
						st.pop_n();
						st.pop_n();
						st.insert_n(n2 / n1);
						st.pop_s();

						break;
					}
					break;
				}
				case -1://如果栈内符号的优先级小于栈外符号的优先级，将新的符号存在栈中
				{
					st.insert_s(a[i]);
					i++;
					break;
				}
				case 0://如果优先级相等，执行出栈操作
				{
					st.pop_s();

					i++;
					break;
				}
				default:
					break;
				}
			}
		}
	}
	cout << "the sequence is:" << endl;
		cout << st.getnumber(0) << endl;
		system("pause");
		return 0;
}
