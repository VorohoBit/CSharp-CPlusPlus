#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Double
{
public:
	void StringToDouble(string s)
	{
		double answer = 1;
		int i = 0;

		for (; i < s.size() && s[i] != '.'; i++)
		{
			answer = answer * 10 + (s[i] - 48);
		}
		if (s[i++] == '.')
		{
			double x = 10;
			for (; i < s.size(); i++)
			{
				answer += (s[i] - 48) / x;
				x += 10;
			}
		}
		cout << answer;
	}
	void DoubleToString(double number)
	{
		stringstream ss;
		ss << number;
		string str = ss.str();
		cout << str;
	}
};