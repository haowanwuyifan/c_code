#include"rational.h"
#include<stdlib.h>
using namespace std;

void caculate(char* s,Rational &a, Rational &b)
{
	int i = 0, j = 0;
	Rational c;
	while (s[i] != '\0')						//��������ַ�������
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if (j == 0)							//�����������ʱ���ж��Ƿ�Ϊ��һ��������һ����ʱj=0�����������������a
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
				int l = i - j - 1;						//���򣬽��������������b��������һ�������жϽ��мӷ����Ǽ��������������a��
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
	int l = i - j - 1;									//���һ���������ѭ�����ܴ�����Ҫ��������������j��=0ʱ�������ͬ
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
	cout << "��������ʽ��";
	cin >> s;
	Rational a;
	Rational b;
	caculate(s, a, b);
	system("pause");
	return 0;
}