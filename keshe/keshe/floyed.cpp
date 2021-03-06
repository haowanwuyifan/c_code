#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<fstream>
#define HUGE 9999
using namespace std;

class hosnet
{
public:
	hosnet(int size,vector <string> &a);
	void getpath(vector <pair<string, string>> &a,vector <int> &c);
	void setpath();
	void display();
	void sequence();
private:
	int** path;
	int** swit;
	vector <string> b;
	int _size;
};

hosnet::hosnet(int size,vector <string> &a)
{
	_size = size;
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
			if (i == j)
			{
				path[i][j] = HUGE;
			}
			else
			{
				path[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < _size; i++)
	{
		swit = new int*[_size];
	}
	for (int j = 0; j < _size; j++)
	{
		swit[j] = new int[_size];
	}
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			swit[i][j] = -1;
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		b.push_back(a.at(i));
	}
}

void hosnet::getpath(vector <pair<string, string>> &a, vector <int> &c)
{
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
			path[x][y] = c.at(i);
			path[y][x] = c.at(i);
		}
	}
}

void hosnet::setpath()
{
	for (int k = 0; k < _size; k++)
	{
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				if (i != j)
				{
					if (path[i][k]!=0 && path[k][j]!=0)
					{
						if (path[i][j] > path[i][k] + path[k][j])
						{
							path[i][j] = path[i][k] + path[k][j];
							swit[i][j] = k;
						}
					}
				}
			}
		}
	}
}

void hosnet::display()
{
	vector <int> c;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (i != j)
			{
				if (path[i][j] != 0)
				{
					cout << b.at(i) << "->" << b.at(j) << ":" << path[i][j] << endl;
					int x = i;
					int k = swit[i][j];
					while (k != -1)
					{
						x = k;
						c.push_back(k);
						k = swit[x][j];
					}
					cout << "中间经过：";
					for (int s = 0; s < c.size(); s++)
					{
						cout << b.at(c.at(s)) << " ";
					}
					c.clear();
					cout << endl;
				}
				else
				{
					cout << b.at(i) << "->" << b.at(j) << ":" << "无法到达" << endl;
				}
			}
		}
	}
}

void hosnet::sequence()
{
	int* a = new int[_size];
	for (int i = 0; i < _size; i++)
	{
		int ad = 0;
		for (int j = 0; j < _size; j++)
		{
			if (path[i][j] == 0)
			{
				ad = HUGE + 99;
				break;
			}
			else if (path[i][j] != HUGE)
			{
				ad += path[i][j];
			}
		}
		if (ad > HUGE)
		{
			ad = -1;
		}
		else
		{
			a[i] = ad;
		}
	}
	int t = a[0] > 0 ? a[0] : HUGE;
	int j = 0;
	for (int i = 0; i < _size; i++)
	{
		if (a[i] < t && a[i] > 0)
		{
			t = a[i];
			j = i;
		}
	}
	if (t > 0 && t < HUGE)
	{
		cout << "选择的社区为：" << b.at(j) << endl;
		cout << "最短的距离和为：" << t << endl;
	}
	else
	{
		cout << "社区不连通，无法选址！" << endl;
	}
}

int main()
{
	vector <pair<string, string>> a;
	vector <string> b;
	vector <int> c;
	string m;
	string n;
	int l;
	fstream file("y.txt");
	if (file.fail())
	{
		cout << "failed!" << endl;
		exit(1);
	}
	while (!file.eof())
	{
		file >> m;
		if (b.empty())
		{
			b.push_back(m);
		}
		file >> n;
		file >> l;
		if (m != n && m.length() == 4 && n.length() == 4 && l > 0)
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
			c.push_back(l);
		}
		else
		{
			cout << "输入有误！" << endl;
			continue;
		}
	}
	cout << "文件中的社区有：";
	for (int i = 0; i < b.size(); i++)
	{
		cout << b.at(i) << " ";
	}
	cout << endl;
	hosnet hs(b.size(), b);
	hs.getpath(a, c);
	hs.setpath();
	hs.display();
	hs.sequence();
	system("pause");
	return 0;
}