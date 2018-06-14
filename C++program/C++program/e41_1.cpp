#include<iostream>
#include<string>
using namespace std;

class A
{
protected:
	int a;
public:
	A()
	{
		cout << "construct A" << endl;
	}
	A(int _a)
		:a(_a)
	{
		cout << "construct A:" << _a << endl;
	}
	~A()
	{
		cout << "destroy A" << endl;
	}
};

class B
	:public A
{
protected:
	int b;
public:
	B()
	{
		cout << "construct B" << endl;
	}
	B(int _a, int _b)
		:A(_a), b(_b)
	{
		cout << "construct B:" << _b << endl;
	}
	~B()
	{
		cout << "destroy B" << endl;
	}
};

class C
	:public B
{
protected:
	int c;
public:
	C()
	{
		cout << "construct C" << endl;
	}
	C(int _a, int _b, int _c)
		:B(_a, _b), c(_c)
	{
		cout << "construct C:" << _c << endl;
	}
	~C()
	{
		cout << "destroy C" << endl;
	}
};

int main()
{
	B c1(1, 2);
	C c(1, 2, 3);
	return 0;
}