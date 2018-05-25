#include<iostream>
using namespace std;

class String
{
public:
	String() {};
	String(char* a);
	String(const String &a);
	int strcmp(const String &b);
	int size();
	String& substr(int be,int en);
	void insert(int i,const String &b);
	String& erase(int be,int len);
	String& append(const String &a);
	String& replace(String& a,int be,int en);
	int find(char a);
	//bool constains();
	char at(int);
	friend int length(const String &a);
	friend String& operator+(String a, String b);
	friend bool operator==(String a, String b);
	friend ostream& operator<<(ostream &out, String a);
	friend istream& operator>>(istream &in, String &a);
	String& operator=(const String &a);
private:
	char* string;
	int _size;
};

String::String(char* a)
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	_size = i;
	string = new char[i + 1];
	for (int j = 0; j < i; j++)
	{
		string[j] = a[j];
	}
}

String::String(const String &a)
{
	
	_size = a._size;
	if (_size > 0)
	{
		string = new char[_size];
		for (int i = 0; i < _size; i++)
		{
			string[i] = a.string[i];
		}
	}
	
}

int String::size()
{
	return _size;
}

char String::at(int i)
{
	if (i < _size)
	{
		return string[i];
	}
	else
	{
		return '\0';
		cout << "访问有误!" << endl;
	}
}

String& String::substr(int be, int en = -1)
{
	if (en == -1)
	{
		en = _size;
	}
	int size = en - be;
	char* s = new char[size];
	for (int i = 0; i < size; i++)
	{
		s[i] = string[be + i];
	}
	String *c = new String(s);
	return *c;
}

int String::strcmp(const String &b)
{
	if (_size == b._size)
	{
		return 0;
	}
	else if (_size > b._size)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void String::insert(int i, const String &b)
{
	char *a = new char[_size + b._size];
	int _i = 0;
	for (int _i = 0; _i < _size + b._size; _i++)
	{
		if (_i < i)
		{
			a[_i] = string[_i];
		}
		else if(_i<i+b._size)
		{
			a[_i] = b.string[_i - i];
		}
		else
		{
			a[_i] = string[_i-i-b._size];
			i++;
		}
	}
	delete[] string;
	_size = _size + b._size;
	string = new char[_size];
	for (int i = 0; i < _size; i++)
	{
		string[i] = a[i];
	}
}

String& String::erase(int be,int len)
{
	
	char* s1 = new char[be];
	char* s2 = new char[_size + 1 - len];
	for (int i = 0; i < _size; i++)
	{
		if (i < be)
		{
			s1[i] = string[i];
		}
		else if (i >= be + len)
		{
			s2[i - be - len] = string[i];
		}
	}
	delete[]string;
	_size = _size - len;
	string = new char[_size + 1];
	for (int i = 0; i < _size; i++)
	{
		if (i < be)
		{
			string[i] = s1[i];
		}
		else
		{
			string[i] = s2[i - be - len];
		}
	}
	return *this;
}

String& String::append(const String &a)
{
	int size = _size + a._size + 1;
	char* s = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (i < _size)
		{
			s[i] = string[i];
		}
		else
		{
			s[i] = a.string[i - _size];
		}
	}
	_size = size;
	delete[] string;
	string = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		string[i] = s[i];
	}
	return *this;
}

String& String::replace(String& a,int be,int en=-1)
{
	int nsize = _size + a._size;
	if (be == -1)
	{
		be = _size;
	}
	char* c = new char[nsize + 1];
	for (int i = 0; i < nsize; i++)
	{
		if (i < be)
		{
			c[i] = string[i];
		}
		else if(i>=be&&i<be+a._size)
		{
			c[i] = a.at(i - be);
		}
		else if (i >= be + a._size&&i < _size + a._size)
		{
			c[i] = string[i - be - a._size + en];
		}
	}
	String *s = new String(c);
	return *s;
}

int String::find(char a)
{
	for (int i = 0; i < _size; i++)
	{
		if (string[i] == a)
		{
			return i;
		}
	}
	cout << "不存在该值！" << endl;
	return NULL;
}

//bool String::constains()
//{
//
//}

int length(const String &a)
{
	return a._size;
}

String& operator+(String a, String b)
{
	int size = a.size() + b.size() - 1;
	char* s = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (i < a.size())
		{
			s[i] = a.at(i);
		}
		else
		{
			s[i] = b.at(i - a.size());
		}
	}
	String *c = new String(s);
	return *c;
}

bool operator==(String a, String b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a.at(i) != b.at(i))
			{
				return false;
			}
		}
		return true;
	}
}

ostream& operator<<(ostream& out, String a)
{
	out << a.string;
	return out;
}

istream& operator>>(istream& in, String &a)
{
	a.string = new char[1024];
	in >> a.string;
	int i = 0;
	while (a.string[i] != '\0')
	{
		i++;
	}
	a._size = i;
	return in;
}

String& String::operator=(const String &a)
{
	delete[] string;
	_size = a._size;
	string = new char[_size];
	for (int i = 0; i < _size; i++)
	{
		string[i] = a.string[i];
	}
	return *this;
}



int k = 1;


void get_name(String& a, String& b, int n)//获取文件名
{
	int t = 0;
	for (int i = 0; i < n; i++)//取最后一个\或/之后的部分为文件名
	{
		if (a.at(i) == '\0')
		{
			break;
		}
		if (a.at(i) == '\\' || a.at(i) == '/')
		{
			t = i;
		}
	}
	b = a.substr(t);
}

void get_index(String& a, String& b, int n)//获取文件目录
{
	int t = 0;
	for (int i = 0; i < n; i++)//取最后一个\或/之前的为文件目录
	{
		if (a.at(i) == '\0')
		{
			break;
		}
		if (a.at(i) == '\\' || a.at(i) == '/')
		{
			t = i;
		}
	}
	b = a.substr(0,t);
}

void replace(String& a, String& b)//替换文件路径
{
	int length_a = a.size();
	int length_b = b.size();
	if (b.at(length_b) != '\\' || b.at(length_b) != '/')//如果不是以\或/结尾的要加上
	{
		char* s = new char('/');
		String c(s);
		b.append(c);
	}
	int t = 0;
	for (int i = 0; i < a.size(); i++)//取最后一个\或/之前的为文件目录
	{
		if (a.at(i) == '\0')
		{
			break;
		}
		if (a.at(i) == '\\' || a.at(i) == '/')
		{
			t = i;
		}
	}
	a.replace(b, 0, t);
}

void merge(String& a, String& b)//合并文件目录和路径
{
	int length_a = a.size();
	int length_b = b.size();
	if (a.at(length_a) != '\\' || a.at(length_a) != '/')//如果不是以\或/结尾的要加上
	{
		char* s = new char('/');
		String c(s);
		a.append(c);
	}
	else
	{
		a = a + b;
	}

}




void menu(String& a)
{
	cout << "*************************************" << endl;
	cout << "**1.获取路径长度*******2.获取文件名**" << endl;
	cout << "**3.获取文件所在目录*4.替换文件目录**" << endl;
	cout << "**5.连接文件名和目录****6，退出程序**" << endl;
	cout << "*************************************" << endl;
	int option;
	cout << "请输入选项：";
	cin >> option;
	switch (option)
	{
	case 1:
	{
		
		cout << "路径的长度为：" << a.size() << endl;
		break;
	}
	case 2:
	{
		int length = a.size();
		String name;
		get_name(a, name, length);
		cout << "文件名为：";
		int i = 0;
		cout << name;
		cout << endl;
		break;
	}
	case 3:
	{
		int length = a.size();
		String name;
		get_index(a, name, length);
		cout << "文件目录为：";
		cout << name;
		break;
	}
	case 4:
	{
		String index;
		cout << "请输入新的文件目录：";
		cin >> index;
		replace(a, index);
		cout << "替换后的文件路径为：";
		cout << a;
		cout << endl;
		break;
	}
	case 5:
	{
		String index;
		String name;
		cout << "请输入文件目录：";
		cin >> index;
		cout << "请输入文件名：";
		cin >> name;
		merge(index, name);
		cout << "连接后的文件路径为：";
		cout << index;
		cout << endl;
		break;
	}
	case 6:
	{
		k = 0;
		break;
	}
	default:
		cout << "请重新输入！" << endl;
		break;
	}
}

int main()
{
	cout << "请输入文件目录：";
	String a;
	cin >> a;
	while (k)
	{
		menu(a);
	}
	return 0;
}
//int main()
//{
//	
//}