#include<iostream>
#include<stdlib.h>
using namespace std;

class Ractangle
{
public:
	Ractangle() {};
	Ractangle(double x, double y, double length,double width)
		:_x(x),_y(y),_length(length),_width(width){}
	double area();
	bool equal(const Ractangle &b) const;
	int change_size(double time);
	int move(double x,double y);
	Ractangle overlap(const Ractangle &b) const;
	double get_x() const { return _x; }
	double get_y() const { return _y; }
	double get_length() const { return _length; }
	double get_width() const { return _width; }
	double min(double x, const double y) const;
	double max(double x, const double y) const;
	friend bool operator!=(Ractangle &a,int x);
private:
	double _x;
	double _y;
	double _length;
	double _width;
};

int k = 1;

double Ractangle::min(double x,double y) const
{
	return x <= y ? x : y;
}

double Ractangle::max(double x, double y) const
{
	return x <= y ? y : x;
}

double Ractangle::area()
{
	return _length * _width;
}

bool Ractangle::equal(const Ractangle &b) const
{
	if (this->_length*this->_width == b._length*b._width)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Ractangle::change_size(double time)
{
	if (time > 0)
	{
		_length *= time;
		_width *= time;
		return 1;
	}
	else
	{
		cout << "error!" << endl;
		return -1;
	}
}

int Ractangle::move(double x, double y)
{
	_x += x;
	_y += y;
	return 1;
}

Ractangle Ractangle::overlap(const Ractangle &b) const
{
	double by = b.get_y() - b.get_width();
	double bx = b.get_x() + b.get_length();
	double ay = _y - _width;
	double ax = _x + _length;
	double w_new;
	double l_new;
	double x;
	double y;
	if (_y <= b.get_y())
	{
			w_new = _y - by;
			y = _y;
			if (w_new <= 0)
			{
				w_new = 0;
				y = NULL;
			}
			if (w_new >= _width)
			{
				w_new = _width;
			}
			if (_x <= bx)
			{
				l_new = ax - b.get_x();
				x = max(_x, b.get_x());
				if (l_new <= 0)
				{
					l_new = 0;
					x = NULL;
				}
				else if (l_new >= min(_length,b.get_length()))
				{
					l_new = min(_length, b.get_length());
				}
			}
			else if (_x > b.get_x())
			{
				l_new = bx - _x;
				x = min(_x, b.get_x());
				if (l_new <= 0)
				{
					l_new = 0;
					x = NULL;
				}
				else if (l_new >= min(_length, b.get_length()))
				{
					l_new = min(_length, b.get_length());
				}
			}
			
	}
	else if (_y > b.get_y())
	{
		w_new = b.get_y() - ay;
		y = b.get_y();
		if (w_new <= 0)
		{
			w_new = 0;
			y = NULL;
		}
		if (w_new >= b.get_width())
		{
			w_new = b.get_width();
		}
		if (_x <= bx)
		{
			l_new = ax - b.get_x();
			x = max(_x, b.get_x());
			if (l_new <= 0)
			{
				l_new = 0;
				x = NULL;
			}
			else if (l_new >= min(_length, b.get_length()))
			{
				l_new = min(_length, b.get_length());
			}
		}
		else if (_x > b.get_x())
		{
			l_new = bx - _x;
			x = min(_x, b.get_x());
			if (l_new <= 0)
			{
				l_new = 0;
				x = NULL;
			}
			else if (l_new >= min(_length, b.get_length()))
			{
				l_new = min(_length, b.get_length());
			}
		}
		
	}
	if (x != NULL && y != NULL)
	{

		Ractangle c(x, y, l_new, w_new);
		return c;
	}
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
		if (a.equal(b) == 1)
		{
			cout << "面积相等" << endl;
		}
		else
		{
			cout << "面积不相等" << endl;
		}
		break;
	}
	case 3:
	{
		double time;
		cout << "输入扩大或缩小的倍数:";
		cin >> time;
		if (a.change_size(time) == 1)
		{
			cout << "新的矩形的长为：" << a.get_length() << endl;
			cout << "新的矩形的宽为：" << a.get_width() << endl;
		}
		else
		{
			cout << "变形失败" << endl;
		}
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
			cout << "平移成功" <<endl;
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
		Ractangle c = a.overlap(b);
		if (c != NULL)
		{
			cout << "重叠部分为：" << c.get_x() << " " << c.get_y() << " " << c.get_length() << " " << c.get_width() << endl;
		}
		else
		{
			cout << "没有重叠！" << endl;
		}
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

bool operator!=(Ractangle &a,int x)
{
	return a._x != NULL && a._y != NULL;
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