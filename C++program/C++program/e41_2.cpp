#include<iostream>
#include<string>
using namespace std;

class A1
{
private:
	int a;
public:
	A1()
	{
		cout << "construct A1" << endl;
	}
	A1(int _a)
		:a(_a)
	{
		cout << "construct A1:" << _a << endl;
	}
	~A1()
	{
		cout << "destroy A1" << endl;
	}
};

class B1
{
private:
	A1 a;
	int b;
public:
	B1()
	{
		cout << "construct B1" << endl;
	}
	B1(int _a, int _b)
		:a(_a), b(_b)
	{
		cout << "construct B1:" << _b << endl;
	}
	~B1()
	{
		cout << "destroy B1" << endl;
	}
};

class C1
{
private:
	A1 a;
	B1 b;
	int c;
public:
	C1()
	{
		cout << "construct C1" << endl;
	}
	C1(int _a, int _b, int _c)
		:a(_a), b(_a, _b), c(_c)
	{
		cout << "construct C1:" << _c << endl;
	}
	~C1()
	{
		cout << "destroy C1" << endl;
	}
};

int main()
{
	//B1 a1(1, 2);
	C1 c(1, 2, 3);
	return 0;
}