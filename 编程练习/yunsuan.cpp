#include<iostream>
#include<stdlib.h>
using namespace std;

class stack//����ջ��
{
public:
	void insert_n(char);//������ջ��ջ
	void pop_n();//������ջ��ջ
	void insert_s(char);//�Է���ջ��ջ
	void pop_s();//�Է���ջ��ջ
	int getsign();//���ط���ջ��ǰ��ָ��λ��
	int getnumber(int);//��������
	char getsing2(int);//���ض�Ӧλ�õķ���
	stack();//���캯��
	int listsize1;//����ջ�ĳ���
	int listsize2;//����ջ�ĳ���
	void insert_n(int);//��������
protected:
	int* number;
	char* sign;

};

stack::stack()//���캯����������ջ�ͷ���ջ��ʼ��
{
	listsize1 = -1;
	listsize2 = -1;
	number = new int[10];
	sign = new char[10];

}
void stack::insert_n(int a)
{//������ջ��ջ�����أ�����������Ԫ�أ��г�+1
	listsize1++;
	number[listsize1] = a;
}
void stack::insert_n(char a)
{//������ջ��ջ�������ַ������ݣ��г�+1
		listsize1++;
		number[listsize1] = int(a) - 48;
}

void stack::pop_n()
{//������ջ��ջ
	listsize1--;
}

void stack::insert_s(char a)
{//����ջ��ջ
	listsize2++;
	sign[listsize2] = a;
}

void stack::pop_s()
{//����ջ��ջ
	listsize2--;
}

int stack::getsign()
{//���ط���ջ��ǰ��ָ��λ��
	return listsize2;
}

int stack::getnumber(int i)
{//����ָ����ָλ�õ�����
	return number[i];
}

char stack::getsing2(int i)
{//���ص�ǰָ����ָ�ķ���
	return sign[i];
}

int compare(int i, int j)
{//�жϷ��ŵ����ȼ���������б���б궼��Ӧ��+����-����*����/����������������#����
	//���С�#��Ϊ��ʼ�ͽ����ı�ʶ�������ȼ���ģ���ʾΪ1��С����ʾΪ0���������ź�����#�������ȼ���ȣ���������Ϊ�޷��Ƚ�
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
{//��ÿ�����Ŷ�Ӧ���Ƚϱ���
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
	st.insert_s('#');//�ȷ���һ��#���ȴ����һ��#����
	int i = 0;
	while (a[i] != '\0')//������ı��ʽ�жϣ���������֣���������ջ
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			st.insert_n(a[i]);
			i++;
		}
		else	if (a[i] < '0' || a[i] > '9')
		{
			if (st.getsign() == 0)//�������ջΪ�գ������ŷ���ջ��
			{
				st.insert_s(a[i]);
				i++;
				continue;
			}
			else//�ǿյĻ������ж����ȼ����ڽ������㣬���µĽ����ջ
			{
				int a_ = getindex(st.getsing2(st.listsize2));
				int b = getindex(a[i]);
				int c = compare(a_, b);
				switch (c)
				{
				case 1://��������£�ջ����ķ��ŵ����ȼ�����ջ��ķ��ŵ����ȼ����Ƚ���ջ����ŵ����㣬���������ջ��
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
				case -1://���ջ�ڷ��ŵ����ȼ�С��ջ����ŵ����ȼ������µķ��Ŵ���ջ��
				{
					st.insert_s(a[i]);
					i++;
					break;
				}
				case 0://������ȼ���ȣ�ִ�г�ջ����
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
