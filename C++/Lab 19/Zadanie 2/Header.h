#pragma once
#include <iostream>
using namespace std;
class FLOAT
{
private:
	float number;
public:
	FLOAT();
	FLOAT(float num);
	int min(FLOAT& fl_1, FLOAT& fl_2);
	operator int() const;
	operator float() const;
	friend ostream& operator << (ostream& out, FLOAT& tmp);
	friend istream& operator >> (istream& in, FLOAT& tmp);
};