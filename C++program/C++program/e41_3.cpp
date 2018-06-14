#include<iostream>
#include<string>
using namespace std;

class A2
{
protected:
	int a;
public:
	A2()
	{
		cout << "construct A2" << endl;
	}
	A2(int _a)
		:a(_a)
	{
		cout << "construct A2:" << _a << endl;
	}
	virtual ~A2()
	{
		cout << "virtual destroy A2" << endl;
	}
};
class B2
	:virtual public A2
{
protected:
	int b;
public:
	B2()
	{
		cout << "construct B2" << endl;
	}
	B2(int _a, int _b)
		:A2(_a), b(_b)
	{
		cout << "construct B2:" << _b << endl;
	}
	~B2()
	{
		cout << "destroy B2" << endl;
	}
};
class C2
	:virtual public A2
{
protected:
	int c;
public:
	C2()
	{
		cout << "construct C2" << endl;
	}
	C2(int _a, int _c)
		:A2(_a), c(_c)
	{
		cout << "construct C2:" << _c << endl;
	}
	~C2()
	{
		cout << "destroy C2" << endl;
	}
};
class D2
	:public B2, public C2
{
protected:
	int d;
public:
	D2()
	{
		cout << "construct D2" << endl;
	}
	D2(int _a, int _b, int _c, int _d)
		:B2(_a, _b), C2(_a, _c), d(_d)
	{
		cout << "construct D2:" << _d << endl;
	}
	~D2()
	{
		cout << "destroy D2" << endl;
	}
};

int main()
{
	D2 d(1, 2, 3, 4);
	return 0;
}