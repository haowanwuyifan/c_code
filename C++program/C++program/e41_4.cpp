#include<iostream>
#include<string>
using namespace std;

class A3
{
public:
	void print()
	{
		cout << "this is A3" << endl;
	}
};
class B3
	:public A3
{
public:
	void print()
	{
		cout << "this is B3" << endl;
	}
};
class C3
{
public:
	virtual void print()
	{
		cout << "this is C3" << endl;
	}
};
class D3
	:public C3
{
public:
	virtual void print()
	{
		cout << "this is D3" << endl;
	}
};
void print1(D3 *p)
{
	p->print();
}
void print2(D3 &a)
{
	a.print();
}
void print3(D3 a)
{
	a.print();
}

int main()
{
	B3 b;
	b.print();
	D3 d;
	C3 *p = &d;
	p->print();
	d.print();
	D3 *t = &d;
	print1(t);
	print2(d);
	print3(d);
}