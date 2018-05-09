#include<iostream>
using namespace std;

class String
{
public:
	String() {};
	String(char* a);
	String(const String &a);
	String strcpy();
	bool strcmp();
	int size();
	String substr();
	void insert();
	String erase();
	String append();
	String replace();
	String find();

};


int main()
{

}