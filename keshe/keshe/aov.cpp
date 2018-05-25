#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class stack
{
public:
	stack();
	void createstack(int size);
	bool empty();
	void push(int t);
	void pop();
	int getst();
	void clear();
	int getssize();
private:
	int stsize;
	int* stac;
};

stack::stack()
{
	stsize = -1;
}

void stack::createstack(int size)
{
	if (size > 0)
	{
		stac = new int[size];
	}
}

bool stack::empty()
{
	if (stsize == -1)
	{
		return true;
	}
	else if (stsize > -1)
	{
		return false;
	}
}

void stack::push(int t)
{
	stsize++;
	stac[stsize] = t;
}

void stack::pop()
{
	stsize--;
}

int stack::getst()
{
	return stac[stsize];
}

void stack::clear()
{
	stsize = -1;
}

int stack::getssize()
{
	return stsize;
}

class schedule
{
public:
	schedule(int size, vector <string> &a);
	void calin();
	bool setin();
	void getpath(vector <pair<string, string>> &a);
	void display(int);
private:
	int** path;
	int _size;
	int* point;
	int* inde;
	int order;
	vector <string> b;
	stack st;
};

schedule::schedule(int size, vector <string> &a)
{
	_size = size;
	order = 0;
	for (int i = 0; i < a.size(); i++)
	{
		b.push_back(a.at(i));
	}
}

void schedule::getpath(vector <pair<string, string>> &a)
{
	for (int i = 0; i < _size; i++)
	{
		path = new int*[_size];
	}
	for (int j = 0; j < _size; j++)
	{
		path[j] = new int[_size];
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			path[i][j] = 0;
		}
	}
	point = new int[_size];
	
	for (int i = 0; i < a.size(); i++)
	{
		int x = -1, y = -1;
		for (int j = 0; j < b.size(); j++)
		{
			if (b.at(j) == a.at(i).first)
			{
				x = j;
			}
			if (b.at(j) == a.at(i).second)
			{
				y = j;
			}
			
		}
		if (x > -1 && y > -1)
		{
			path[x][y] = 1;
		}
	}
}

void schedule::calin()
{
	for (int i = 0; i < _size; i++)
	{
		point[i] = 0;
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (path[j][i] == 1)
			{
				point[i]++;
			}
		}
	}
}

  bool schedule::setin()
{
	inde = new int[_size];
	st.createstack(_size);
	if (st.empty())
	{
		for (int j = 0; j < _size; j++)
		{
			for (int i = 0; i < _size; i++)
			{
				if (point[i] == 0)
				{
					st.push(i);
					point[i] = -1;
				}
			}
			int s = st.getssize();
			if (s != -1)
			{
				while (!st.empty())
				{
					inde[order++] = st.getst();
					for (int j = 0; j < _size; j++)
					{
						if (path[(inde[order - 1])][j] == 1)
						{
							point[j]--;
						}
					}
					st.pop();
				}
				if (st.empty())
				{
					cout << "第" << j + 1 << "学期：";
					display(s);
				}
			}
		}
	}
	return order == _size && order != 0 && _size != 0;
}

void schedule::display(int s)
{
	for (int j = order-1; j >=order-s-1; j--)
	{
		
		cout <<b.at(inde[j]) << " ";
	}
	cout << endl;
}

int main()
{
	//cout << "请输入节点间关系：" << endl;
	vector <pair<string,string>> a;
	vector <string> b;
	string m;
	string n;
	ifstream out;
	out.open("t.txt");
	if (out.fail())
	{
		cout << "Error opening file"; 
		exit(1);
	}
	while (!out.eof())
	{
		out >> m;
		if (b.empty())
		{
			b.push_back(m);
		}
		out >> n;
		if (m != n && m.length() == 4 && n.length() == 4)
		{
			b.push_back(m);
			for (int i = 0; i < b.size() - 1; i++)
			{
				if (b.at(i) == m)
				{
					b.pop_back();
					break;
				}
			}
			b.push_back(n);
			for (int i = 0; i < b.size() - 1; i++)
			{
				if (b.at(i) == n)
				{
					b.pop_back();
					break;
				}
			}
			pair<string, string> t;
			t.first = m;
			t.second = n;
			a.push_back(t);
		}
		else
		{
			cout << "输入有误！" << endl;
			continue;
		}
	}
	out.close();
	cout << "文件中的课程有：";
	for (int i = 0; i < b.size(); i++)
	{
		cout << b.at(i) << " ";
	}
	cout << endl;
	schedule sc(b.size(),b);
	sc.getpath(a);
	sc.calin();
	//sc.setin();
	if (sc.setin())
	{
		//sc.display(b);
		cout << "没有环路" << endl;
	}
	else
	{
		//sc.display(b);
		cout << "有环路" << endl;
	}
	system("pause");
	return 0;
}