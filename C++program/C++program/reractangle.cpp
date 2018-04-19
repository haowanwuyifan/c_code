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
	cout << "**1.求面积********2.是否相等**" << endl;
	cout << "**3.改变大小**********4.平移**" << endl;
	cout << "**5.重叠情况******6.退出程序**" << endl;
	cout << "******************************" << endl;
	int option;
	cout << "please input:";
	cin >> option;
	switch (option)
	{
	case 1:
	{
		cout << "矩形的面积是：" << a.area() << endl;
		break;
	}
	case 2:
	{
		cout << "要判断的矩形的位置（左上角顶点的坐标）：" << endl;
		double x, y;
		cin >> x;
		cin >> y;
		cout << "要判断的矩形的长：";
		int length;
		cin >> length;
		cout << "要判断的矩形的宽：";
		int width;
		cin >> width;
		Ractangle b(x, y, length, width);
		if (a==b)
		{
			cout << "矩形相等" << endl;
		}
		else
		{
			cout << "矩形不相等" << endl;
		}
		break;
	}
	case 3:
	{
		double time;
		cout << "输入扩大或缩小的倍数:";
		cin >> time;
		a *= time;
		cout << "新的矩形的长为：" << a.get_length() << endl;
		cout << "新的矩形的宽为：" << a.get_width() << endl;
		cout << "变形失败" << endl;
		break;
	}
	case 4:
	{
		cout << "请输入要平移的长度（左移为负，右移为正，上移为正，下移为负）：" << endl;
		double x;
		double y;
		cin >> x;
		cin >> y;
		if (a.move(x, y) == 1)
		{
			cout << "平移成功" << endl;
			cout << "平移后矩形左上角的顶点为：（" << a.get_x() << "," << a.get_y() << ")" << endl;

		}
		break;
	}
	case 5:
	{
		cout << "要判断的矩形的位置（左上角顶点的坐标）：" << endl;
		double x, y;
		cin >> x;
		cin >> y;
		cout << "要判断的矩形的长：";
		int length;
		cin >> length;
		cout << "要判断的矩形的宽：";
		int width;
		cin >> width;
		Ractangle b(x, y, length, width);
		cout << "重叠部分的面积为：" << a%b << endl;
		break;
	}
	case 6:
	{
		k = 0;
		break;
	}
	default:
		cout << "请重新输入" << endl;
		break;
	}
}


int main()
{
	cout << "矩形的位置（左上角顶点的坐标）：" << endl;
	double x, y;
	cin >> x >> y;
	cout << "矩形的长：";
	double length;
	cin >> length;
	cout << "矩形的宽：";
	double width;
	cin >> width;
	Ractangle a(x, y, length, width);
	while (k)
	{
		menu(a);
	}
	return 0;
}