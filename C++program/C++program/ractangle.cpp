#include<iostream>
#include<stdlib.h>
using namespace std;

class Ractangle
{
public:
	Ractangle(double x, double y, double length,double width)
		:_x(x),_y(y),_length(length),_width(width){}
	double area();
	bool equal(const Ractangle &b) const;
	int change_size(double time);
	int move(double x,double y);
	double overlap(const Ractangle &b) const;
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

}

double Ractangle::overlap(const Ractangle &b) const
{
	double y = b.get_y() - b.get_width();
	double x = b.get_x() + b.get_length();
	if (_y < b.get_y())
	{
		if (y < _y)
		{
			double w_new = _y - y;
			if (y > _y - _width)
			{
				w_new = _y - y;
			}
			else
			{
				w_new = _width;
			}
			if (_x > b.get_x())
			{
				if (x > _x && x < _x + _length)
				{
					double l_new = x - _x;
					return l_new * w_new;
				}
				else if (x <= _x)
				{
					return -1;
				}
				else if (x > _x + _length)
				{
					double l_new = _length;
					return l_new * w_new;
				}
			}
			else if (_x < b.get_x())
			{
				if (b.get_x() > _x && b.get_x() < _x + _length)
				{
					double l_new = x - _x;
					return l_new * w_new;
				}
				else if (x <= _x)
				{
					return -1;
				}
				else if (x > _x + _length)
				{
					double l_new = _length;
					return l_new * w_new;
				}
			}
			
		}
		else if (y >= _y)
		{
			return -1;
		}
	}
	if (_x > b.get_x() && _y > b.get_y())
	{

	}
	if (_x < b.get_x() && _y > b.get_y())
	{

	}
}


int main()
{

}