#pragma once
#include <iostream>
#include <string>
using namespace std;

class String
{
public:
	void StringToCHar(string s)
	{
		char* arrayChars = new char[s.size()];
		for (int i = 0; i < s.size(); ++i)
		{
			arrayChars[i] = s[i];
			cout << arrayChars[i];
		}
	}
	void CharToString(const char* s) 
	{
		int x = strlen(s);
		string answer;
		for (int i = 0; i < x; ++i)
		{
			answer += s[i];
			cout << answer[i];
		}
	}
};