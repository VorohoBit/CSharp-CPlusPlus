#include "Header.h"
#include <iostream>
using namespace std;
FLOAT::FLOAT()
{
	number = 0;
}
FLOAT::FLOAT(float num)
{
	number = num;
}
int FLOAT::min(FLOAT& fl_1, FLOAT& fl_2)
{
	if (fl_1.number < fl_2.number) return fl_1.number;
	else return fl_2.number;
}
FLOAT::operator int() const
{
	return number;
}
FLOAT::operator float() const
{
	return number;
}
ostream& operator << (ostream& out, FLOAT& tmp)
{
	out << tmp.number;
	return out;
}
istream& operator >> (istream& in, FLOAT& tmp)
{
	in >> tmp.number;
	return in;
}