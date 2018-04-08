#pragma once
#include<iostream>
using namespace std;

class Rational
{
public:
	Rational() {};
	void set(int a, int b);
	void add(Rational b);
	void sub(Rational b);
	void mul(Rational a, Rational b);
	int div(Rational a, Rational b);
	int get_fenzi();
	int get_fenmu();
	int sim(int a, int b);
	void seq();
private:
	int fenzi;
	int fenmu;
};

int Rational::sim(int a, int b)
{
	int sum = 1;
	int min = a < b ? a : b;
	for (int i = min; i >= 1; i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			sum = i;
			break;
		}
	}
	return sum;
}

int Rational::get_fenzi()
{
	return fenzi;
}

int Rational::get_fenmu()
{
	return fenmu;
}

void Rational::set(int a, int b)
{
	fenzi = a / sim(a, b);
	fenmu = b / sim(a, b);

}

void Rational::add(Rational b)
{
	int fenmu_c = this->fenmu*b.get_fenmu();
	int fenzi_c = this->fenzi*b.get_fenmu() + this->fenmu*b.get_fenzi();
	int t = sim(fenzi_c, fenmu_c);
	fenmu_c = fenmu_c / t;
	fenzi_c = fenzi_c / t;
	fenzi = fenzi_c;
	fenmu = fenmu_c;
}

void Rational::sub(Rational b)
{
	int fenmu_c = this->fenmu*b.get_fenmu();
	int fenzi_c = this->fenzi*b.get_fenmu() - this->fenmu*b.get_fenzi();
	int t = sim(fenzi_c, fenmu_c);
	fenmu_c = fenmu_c / t;
	fenzi_c = fenzi_c / t;
	fenzi = fenzi_c;
	fenmu = fenmu_c;
}

void Rational::mul(Rational a, Rational b)
{
	int fenzi_c = a.get_fenzi()*b.get_fenzi();
	int fenmu_c = a.get_fenmu()*b.get_fenmu();
	int t = sim(fenzi_c, fenmu_c);
	fenmu_c = fenmu_c / t;
	fenzi_c = fenzi_c / t;
	fenzi = fenzi_c;
	fenmu = fenmu_c;
}

int Rational::div(Rational a, Rational b)
{
	if (b.get_fenzi() != 0)
	{
		int fenzi_c = a.get_fenzi()*b.get_fenmu();
		int fenmu_c = a.get_fenmu()*b.get_fenzi();
		int t = sim(fenzi_c, fenmu_c);
		fenmu_c = fenmu_c / t;
		fenzi_c = fenzi_c / t;
		fenzi = fenzi_c;
		fenmu = fenmu_c;
		return 0;
	}
	else
	{
		cout << "除数不能为0！" << endl;
		return -1;
	}
}

void Rational::seq()
{
	if (fenmu != 1)
	{
		cout << "结果为：" << fenzi << '/' << fenmu << endl;
	}
	else
		cout << "结果为：" << fenzi << endl;
}

int to_int(char* a, int* x, int* y)
{
	int i = 0;
	int m, n;
	int sum_x = 0, sum_y = 0;
	int time_x = 1, time_y = 1;
	while (a[i] != '\0')
	{
		if (a[i] == '/')
		{
			m = i;
		}
		i++;
	}
	n = i - m - 1;
	for (int i = m - 1; i >= 0; i--)
	{
		sum_x = sum_x + ((int)a[i] - 48) * time_x;
		time_x *= 10;
	}
	for (int j = i - 1; j >= i - n; j--)
	{
		sum_y = sum_y + ((int)a[j] - 48) * time_y;
		time_y *= 10;
	}
	*x = sum_x;
	if (sum_y != 0)
	{
		*y = sum_y;
	}
	else
	{
		cout << "分母不能为0！";
		return -1;
	}
	return 0;
}

