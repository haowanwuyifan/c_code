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
	String substr(int be,int en=-1);
	void insert(int i,const String &b);
	String erase(int be,int len);
	String append(const String &a);
	String replace();
	String find();
	bool constains();
	char at(int);
	friend int length(const String &a);
	friend String operator+(String a, String b);
	friend bool operator==(String a, String b);
	friend ostream& operator<<(ostream &out, String a);
	friend istream& operator>>(istream &in, String &a);
	String operator=(const String &a);
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
		cout << "·ÃÎÊÓÐÎó!" << endl;
	}
}

String String::substr(int be, int en = -1)
{
	if (en == -1)
	{
		en = _size;
	}
	int size = en - be;
	char* s = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		s[i] = string[en + i];
	}
	String a(s);
	return a;
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
		else if(_i<i+b.size)
		{
			a[_i] = b.string[_i - i];
		}
		else
		{
			a[_i] = string[_i-i-b.size];
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

String String::erase(int be,int len)
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
}

String String::append(const String &a)
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
}

String String::replace()
{

}

String String::find()
{

}

bool String::constains()
{

}

int length(const String &a)
{
	return a._size;
}

String operator+(String a, String b)
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
	String c(s);
	return c;
}

bool operator==(String a, String b)
{
	if (a.size() != b.size())
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a.at(i) != b.at(i))
			{
				return -1;
			}
		}
		return 1;
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
	return in;
}

String String::operator=(const String &a)
{
	_size = a._size;
	string = new char[_size];
	for (int i = 0; i < _size; i++)
	{
		string[i] = a.string[i];
	}
	return *this;
}


int main()
{
	
}