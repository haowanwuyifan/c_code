#include<iostream>
using namespace std;

int k = 1;

int get_length(char* a)//获取文件路径长度
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}

void get_name(char* a, char* b,int n)//获取文件名
{
	int t = 0;
	for (int i = 0; i < n; i++)//取最后一个\或/之后的部分为文件名
	{
		if (a[i] == '\0')
		{
			break;
		}
		if (a[i] == '\\'||a[i]=='/')
		{
			t = i;
		}
	}
	t++;
	int j = 0;
	while (a[t] != '\0')
	{
		b[j] = a[t];
		j++;
		t++;
	}
	b[j] = '\0';
}

void get_index(char* a, char* b, int n)//获取文件目录
{
	int t = 0;
	for (int i = 0; i < n; i++)//取最后一个\或/之前的为文件目录
	{
		if (a[i] == '\0')
		{
			break;
		}
		if (a[i] == '\\' || a[i] == '/')
		{
			t = i;
		}
	}
	for (int i = 0; i <= t; i++)
	{
		b[i] = a[i];
	}
	b[t + 1] = '\0';
}

void replace(char* a, char* b)//替换文件路径
{
	int length_a = get_length(a);
	int length_b = get_length(b);
	char* c = new char[length_a];
	get_name(a, c, length_a);//将被替换文件的名字部分存在另一个数组
	int length_c = get_length(c);
	if (b[length_b - 1] != '\\' || b[length_b - 1] != '/')//如果不是以\或/结尾的要加上
	{
		b[length_b] = '\\';
		b[length_b + 1] = '\0';
		length_b++;
	}
	int i = 0, j = 0;
	while (1)
	{
		if (i < length_b&&b[i] != '\0')//替换目录
		{
			a[i] = b[i];
			i++;
		}
		else if (c[j] != '\0')//替换名字
		{
			a[i] = c[j];
			j++;
			i++;
		}
		else if (c[j] == '\0')
		{
			break;
		}
	}
	a[i] = '\0';
}

void merge(char* a, char* b)//合并文件目录和路径
{
	int length_a = get_length(a);
	int length_b = get_length(b);
	if (a[length_a - 1] != '\\' || a[length_a - 1] != '/')//如果不是以\或/结尾的要加上
	{
		a[length_a] = '\\';
		int i = 0;
		while (b[i] != '\0')
		{
			a[length_a + 1 + i] = b[i];
			i++;
		}
		a[length_a + 1 + i] = '\0';
	}
	else
	{
		int i = 0;
		while (b[i] != '\0')
		{
			a[length_a + i] = b[i];
			i++;
		}
		a[length_a + i] = '\0';
	}

}




void menu(char* a)
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
		int length = get_length(a);
		cout << "路径的长度为：" << length << endl;
		break;
	}
	case 2:
	{
		int length = get_length(a);
		char* name = new char[length];
		get_name(a, name, length);
		cout << "文件名为：";
		int i = 0;
		while (name[i] != '\0')
		{
			cout << name[i];
			i++;
		}
		cout << endl;
		break;
	}
	case 3:
	{
		int length = get_length(a);
		char* name = new char[length];
		get_index(a, name, length);
		cout << "文件目录为：";
		int i = 0;
		while (name[i] != '\0')
		{
			cout << name[i];
			i++;
		}
		cout << endl;
		break;
	}
	case 4:
	{
		char* index = new char[200];
		cout << "请输入新的文件目录：";
		cin >> index;
		replace(a, index);
		cout << "替换后的文件路径为：";
		int i = 0;
		while (a[i] != '\0')
		{
			cout << a[i];
			i++;
		}
		cout << endl;
		break;
	}
	case 5:
	{
		char* index = new char[200];
		char* name = new char[200];
		cout << "请输入文件目录：";
		cin >> index;
		cout << "请输入文件名：";
		cin >> name;
		merge(index, name);
		cout << "连接后的文件路径为：";
		int i = 0;
		while (index[i] != '\0')
		{
			cout << index[i];
			i++;
		}
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
	char* a = new char[1024];
	cin >> a;
	while (k)
	{
		menu(a);
	}
	return 0;
}