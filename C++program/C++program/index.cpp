#include<iostream>
using namespace std;

int k = 1;

int get_length(char* a)//��ȡ�ļ�·������
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}

void get_name(char* a, char* b,int n)//��ȡ�ļ���
{
	int t = 0;
	for (int i = 0; i < n; i++)//ȡ���һ��\��/֮��Ĳ���Ϊ�ļ���
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

void get_index(char* a, char* b, int n)//��ȡ�ļ�Ŀ¼
{
	int t = 0;
	for (int i = 0; i < n; i++)//ȡ���һ��\��/֮ǰ��Ϊ�ļ�Ŀ¼
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

void replace(char* a, char* b)//�滻�ļ�·��
{
	int length_a = get_length(a);
	int length_b = get_length(b);
	char* c = new char[length_a];
	get_name(a, c, length_a);//�����滻�ļ������ֲ��ִ�����һ������
	int length_c = get_length(c);
	if (b[length_b - 1] != '\\' || b[length_b - 1] != '/')//���������\��/��β��Ҫ����
	{
		b[length_b] = '\\';
		b[length_b + 1] = '\0';
		length_b++;
	}
	int i = 0, j = 0;
	while (1)
	{
		if (i < length_b&&b[i] != '\0')//�滻Ŀ¼
		{
			a[i] = b[i];
			i++;
		}
		else if (c[j] != '\0')//�滻����
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

void merge(char* a, char* b)//�ϲ��ļ�Ŀ¼��·��
{
	int length_a = get_length(a);
	int length_b = get_length(b);
	if (a[length_a - 1] != '\\' || a[length_a - 1] != '/')//���������\��/��β��Ҫ����
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
		int length = get_length(a);
		cout << "·���ĳ���Ϊ��" << length << endl;
		break;
	}
	case 2:
	{
		int length = get_length(a);
		char* name = new char[length];
		get_name(a, name, length);
		cout << "�ļ���Ϊ��";
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
		cout << "�ļ�Ŀ¼Ϊ��";
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
		cout << "�������µ��ļ�Ŀ¼��";
		cin >> index;
		replace(a, index);
		cout << "�滻����ļ�·��Ϊ��";
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
		cout << "�������ļ�Ŀ¼��";
		cin >> index;
		cout << "�������ļ�����";
		cin >> name;
		merge(index, name);
		cout << "���Ӻ���ļ�·��Ϊ��";
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
		cout << "���������룡" << endl;
		break;
	}
}

int main()
{
	cout << "�������ļ�Ŀ¼��";
	char* a = new char[1024];
	cin >> a;
	while (k)
	{
		menu(a);
	}
	return 0;
}