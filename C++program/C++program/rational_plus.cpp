#include"rational.h"
#include<stdlib.h>
using namespace std;

void caculate(char* s,Rational &a, Rational &b)
{
	int i = 0, j = 0;
	Rational c;
	while (s[i] != '\0')						//对输入的字符串处理
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (j == 0)							//当遇到运算符时，判断是否为第一个数，第一个数时j=0，将这个数赋给对象a
			{
				j = i;
				char* _a = new char[j+1];
				for (int m = 0; m < j; m++)
				{
					_a[m] = s[m];
				}
				_a[j] = '\0';
				int m, n;
				int p = to_int(_a, &m, &n);
				if (p == -1)
				{
					cout << endl;
					break;
				}
				a.set(m, n);
			}
			else
			{
				int l = i - j - 1;						//否则，将这个数赋给对象b，根据上一个符号判断进行加法还是减法，将结果存入a中
				char* _b = new char[l+1];
				for (int m = j + 1; m < i; m++)
				{
					_b[m - j - 1] = s[m];
				}
				_b[l] = '\0';
				int _m, _n;
				int p = to_int(_b, &_m, &_n);
				if (p == -1)
				{
					cout << endl;
					break;
				}
				b.set(_m, _n);
				if (s[j] == '+')
				{
					a = a + b;
				}
				else if (s[j] == '-')
				{
					a = a - b;
				}
				/*else if (s[j] == '*')
				{

				}*/
				j = i;
			}
		}
		i++;
	}
	int l = i - j - 1;									//最后一个数上面的循环不能处理，需要单独处理，方法和j！=0时的情况相同
	char* _b = new char[l+1];
	for (int m = j + 1; m < i; m++)
	{
		_b[m - j - 1] = s[m];
	}
	_b[l] = '\0';
	int _m, _n;
	int p = to_int(_b, &_m, &_n);
	if (p == -1)
	{
		cout << endl;
		return ;
	}
	b.set(_m, _n);
	if (s[j] == '+')
	{
		a = a + b;
	}
	else if (s[j] == '-')
	{
		a = a - b;
	}
	a.seq();
}

int main()
{
	char* s = new char[1024];
	cout << "请输入表达式：";
	cin >> s;
	Rational a;
	Rational b;
	caculate(s, a, b);
	system("pause");
	return 0;
}