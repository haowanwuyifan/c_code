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
		cout << "��������!" << endl;
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
	cout << "�����ڸ�ֵ��" << endl;
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


void get_name(String& a, String& b, int n)//��ȡ�ļ���
{
	int t = 0;
	for (int i = 0; i < n; i++)//ȡ���һ��\��/֮��Ĳ���Ϊ�ļ���
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

void get_index(String& a, String& b, int n)//��ȡ�ļ�Ŀ¼
{
	int t = 0;
	for (int i = 0; i < n; i++)//ȡ���һ��\��/֮ǰ��Ϊ�ļ�Ŀ¼
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

void replace(String& a, String& b)//�滻�ļ�·��
{
	int length_a = a.size();
	int length_b = b.size();
	if (b.at(length_b) != '\\' || b.at(length_b) != '/')//���������\��/��β��Ҫ����
	{
		char* s = new char('/');
		String c(s);
		b.append(c);
	}
	int t = 0;
	for (int i = 0; i < a.size(); i++)//ȡ���һ��\��/֮ǰ��Ϊ�ļ�Ŀ¼
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

void merge(String& a, String& b)//�ϲ��ļ�Ŀ¼��·��
{
	int length_a = a.size();
	int length_b = b.size();
	if (a.at(length_a) != '\\' || a.at(length_a) != '/')//���������\��/��β��Ҫ����
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
	cout << "**1.��ȡ·������*******2.��ȡ�ļ���**" << endl;
	cout << "**3.��ȡ�ļ�����Ŀ¼*4.�滻�ļ�Ŀ¼**" << endl;
	cout << "**5.�����ļ�����Ŀ¼****6���˳�����**" << endl;
	cout << "*************************************" << endl;
	int option;
	cout << "������ѡ�";
	cin >> option;
	switch (option)
	{
	case 1:
	{
		
		cout << "·���ĳ���Ϊ��" << a.size() << endl;
		break;
	}
	case 2:
	{
		int length = a.size();
		String name;
		get_name(a, name, length);
		cout << "�ļ���Ϊ��";
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
		cout << "�ļ�Ŀ¼Ϊ��";
		cout << name;
		break;
	}
	case 4:
	{
		String index;
		cout << "�������µ��ļ�Ŀ¼��";
		cin >> index;
		replace(a, index);
		cout << "�滻����ļ�·��Ϊ��";
		cout << a;
		cout << endl;
		break;
	}
	case 5:
	{
		String index;
		String name;
		cout << "�������ļ�Ŀ¼��";
		cin >> index;
		cout << "�������ļ�����";
		cin >> name;
		merge(index, name);
		cout << "���Ӻ���ļ�·��Ϊ��";
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
		cout << "���������룡" << endl;
		break;
	}
}

int main()
{
	cout << "�������ļ�Ŀ¼��";
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