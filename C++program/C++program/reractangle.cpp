#include<iostream>
using namespace std;

int k = 1;

class Ractangle
{
public:
	Ractangle(double x, double y, double length, double width)
		:_x(x), _y(y), _length(length), _width(width) {}
	double area();
	bool operator==(Ractangle &b);
	bool operator!=(Ractangle &b);
	bool operator<(Ractangle &b);
	bool operator>(Ractangle &b);
	bool operator<=(Ractangle &b);
	bool operator>=(Ractangle &b);
	Ractangle* operator*();
	Ractangle& operator&();
	Ractangle operator*=(double x);
	Ractangle operator/=(double x);
	Ractangle operator+=(double x);
	Ractangle operator-=(double x);
	double operator-(Ractangle &b);
	double operator+(Ractangle &b);
	double operator*(Ractangle &b);
	double operator%(Ractangle &b);
	double operator/(Ractangle &b);
	Ractangle operator=(Ractangle &b);
	int move(double x, double y);
	double get_x() const { return _x; }
	double get_y() const { return _y; }
	double get_length() const { return _length; }
	double get_width() const { return _width; }
private:
	double _x;
	double _y;
	double _length;
	double _width;
};

bool Ractangle::operator==(Ractangle &b)
{
	if (this->_length == b.get_length() && this->_width == b.get_width())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ractangle::operator!=(Ractangle &b)
{
	if (this->_length == b.get_length() && this->_width == b.get_width())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Ractangle::operator<(Ractangle &b)
{
	if (this->area() < b.area())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ractangle::operator<=(Ractangle &b)
{
	if (this->area() <= b.area())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ractangle::operator>(Ractangle &b)
{
	if (this->area() > b.area())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Ractangle::operator>=(Ractangle &b)
{
	if (this->area() >= b.area())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Ractangle* Ractangle::operator*()
{
	return this;
}

Ractangle& Ractangle::operator&()
{
	return *this;
}

Ractangle Ractangle::operator*=(double x)
{
	if (x > 0)
	{
		_length *= x;
		_width *= x;
		return *this;
	}
	else
	{
		cout << "error!" << endl;
	}
}

Ractangle Ractangle::operator/=(double x)
{
	if (x > 0)
	{
		_length /= x;
		_width /= x;
		return *this;
	}
	else
	{
		cout << "error!" << endl;
	}
}

Ractangle Ractangle::operator+=(double x)
{
	if (x > 0)
	{
		_length += x;
		_width += x;
		return *this;
	}
	else
	{
		cout << "error!" << endl;
	}
}

Ractangle Ractangle::operator-=(double x)
{
	if (x > 0)
	{
		_length -= x;
		_width -= x;
		return *this;
	}
	else
	{
		cout << "error!" << endl;
	}
}

double Ractangle::area()
{
	return _length * _width;
}

double Ractangle::operator*(Ractangle &b)
{
	return this->area()*b.area();
}

double Ractangle::operator-(Ractangle &b)
{
	return this->area() - b.area();
}

double Ractangle::operator+(Ractangle &b)
{
	return this->area() + b.area();
}

double Ractangle::operator/(Ractangle &b)
{
	if (b.area() > 0)
	{
		return this->area() / b.area();
	}
	else
	{
		cout << "error" << endl;
	}
}

double Ractangle::operator%(Ractangle &b)
{
	double by = b.get_y() - b.get_width();
	double bx = b.get_x() + b.get_length();
	double ay = _y - _width;
	double ax = _x + _length;
	double w_new;
	double l_new;
	if (_y <= b.get_y())
	{
		w_new = _y - by;
		if (w_new <= 0)
		{
			w_new = 0;
		}
		if (w_new >= b.get_length())
		{
			w_new = b.get_length();
		}
		if (_x <= b.get_x())
		{
			l_new = ax - b.get_x();
			if (l_new <= 0)
			{
				l_new = 0;
			}
			else if (l_new >= b.get_length())
			{
				l_new = b.get_length();
			}
		}
		else if (_x > b.get_x())
		{
			l_new = bx - _x;
			if (l_new <= 0)
			{
				l_new = 0;
			}
			else if (l_new >= b.get_length())
			{
				l_new = b.get_length();
			}
		}
		return l_new * w_new;
	}
	else if (_y > b.get_y())
	{
		w_new = b.get_y() - ay;
		if (w_new <= 0)
		{
			w_new = 0;
		}
		if (w_new >= b.get_length())
		{
			w_new = b.get_length();
		}
		if (_x <= b.get_x())
		{
			l_new = ax - b.get_x();
			if (l_new <= 0)
			{
				l_new = 0;
			}
			else if (l_new >= b.get_length())
			{
				l_new = b.get_length();
			}
		}
		else if (_x > b.get_x())
		{
			l_new = bx - _x;
			if (l_new <= 0)
			{
				l_new = 0;
			}
			else if (l_new >= b.get_length())
			{
				l_new = b.get_length();
			}
		}
		return l_new * w_new;
	}
}

Ractangle Ractangle::operator=(Ractangle &b)
{
	this->_x = b.get_x();
	this->_y = b.get_y();
	this->_length = b.get_length();
	this->_width = b.get_width();
	return *this;
}

int Ractangle::move(double x, double y)
{
	_x += x;
	_y += y;
	return 1;
}

void menu(Ractangle &a)
{
	cout << "******************************" << endl;
	cout << "**1.�����********2.�Ƿ����**" << endl;
	cout << "**3.�ı��С**********4.ƽ��**" << endl;
	cout << "**5.�ص����******6.�˳�����**" << endl;
	cout << "******************************" << endl;
	int option;
	cout << "please input:";
	cin >> option;
	switch (option)
	{
	case 1:
	{
		cout << "���ε�����ǣ�" << a.area() << endl;
		break;
	}
	case 2:
	{
		cout << "Ҫ�жϵľ��ε�λ�ã����ϽǶ�������꣩��" << endl;
		double x, y;
		cin >> x;
		cin >> y;
		cout << "Ҫ�жϵľ��εĳ���";
		int length;
		cin >> length;
		cout << "Ҫ�жϵľ��εĿ�";
		int width;
		cin >> width;
		Ractangle b(x, y, length, width);
		if (a==b)
		{
			cout << "�������" << endl;
		}
		else
		{
			cout << "���β����" << endl;
		}
		break;
	}
	case 3:
	{
		double time;
		cout << "�����������С�ı���:";
		cin >> time;
		a *= time;
		cout << "�µľ��εĳ�Ϊ��" << a.get_length() << endl;
		cout << "�µľ��εĿ�Ϊ��" << a.get_width() << endl;
		cout << "����ʧ��" << endl;
		break;
	}
	case 4:
	{
		cout << "������Ҫƽ�Ƶĳ��ȣ�����Ϊ��������Ϊ��������Ϊ��������Ϊ������" << endl;
		double x;
		double y;
		cin >> x;
		cin >> y;
		if (a.move(x, y) == 1)
		{
			cout << "ƽ�Ƴɹ�" << endl;
			cout << "ƽ�ƺ�������ϽǵĶ���Ϊ����" << a.get_x() << "," << a.get_y() << ")" << endl;

		}
		break;
	}
	case 5:
	{
		cout << "Ҫ�жϵľ��ε�λ�ã����ϽǶ�������꣩��" << endl;
		double x, y;
		cin >> x;
		cin >> y;
		cout << "Ҫ�жϵľ��εĳ���";
		int length;
		cin >> length;
		cout << "Ҫ�жϵľ��εĿ�";
		int width;
		cin >> width;
		Ractangle b(x, y, length, width);
		cout << "�ص����ֵ����Ϊ��" << a%b << endl;
		break;
	}
	case 6:
	{
		k = 0;
		break;
	}
	default:
		cout << "����������" << endl;
		break;
	}
}


int main()
{
	cout << "���ε�λ�ã����ϽǶ�������꣩��" << endl;
	double x, y;
	cin >> x >> y;
	cout << "���εĳ���";
	double length;
	cin >> length;
	cout << "���εĿ�";
	double width;
	cin >> width;
	Ractangle a(x, y, length, width);
	while (k)
	{
		menu(a);
	}
	return 0;
}