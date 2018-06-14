#include<iostream>
#include<vector>
#include<fstream>
#include<list>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

class StrHandler
{
public:
	virtual void Strhandler(const string &str) = 0;
};

class StrHandlerP
	:public StrHandler
{
public:
	void Strhandler(const string &str)
	{
		cout << str << endl;
	}
};

class StrHandlerV
	:public StrHandler
{
private:
	vector<string>vec;
public:
	void Strhandler(const string &str)
	{
		vec.push_back(str);
	}
};

class StrHandlerL
	:public StrHandler
{
protected:
	list<string>lis;
public:
	void Strhandler(const string &str)
	{
		lis.push_back(str);
	}

};

void readStrings(const std::string &file, StrHandler *p)
{
	ifstream infile(file, ios::in || ios::_Nocreate);
	if (!infile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	string str;
	while (infile >> str)
	{
		p->Strhandler(str);
	}
}
int main()
{
	std::string a = "E42.txt";
	StrHandlerP P;
	StrHandlerV V;
	StrHandlerL L;
	StrHandler *p;
	p = &P;
	readStrings(a, p);
	p = &V;
	readStrings(a, p);
	p = &L;
	readStrings(a, p);
}