#include "Double.h"
#include "String.h"
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	while (true)
	{
		cout << "What do u want to choose?(1-стринг в дабл,2-дабл в стринг,3-чар в стринг,4-стринг в чар,5-выход" << endl; cin >> N;
		if (N == 1) cout << "Вы выбрали string V double" << endl;
		else if (N == 2) cout << "Вы выбрали double V string" << endl;
		else if (N == 3) cout << "Вы выбрали char* V string" << endl;
		else if (N == 4) cout << "Вы выбрали string V char*" << endl;
		else if (N == 5) cout << "Вы выбрали выход из программы" << endl;
		switch (N)
		{
		case 1:
		{
			Double d_1;
			d_1.StringToDouble("Char");
			cout << endl;
			break;
		}
		case 2:
		{
			Double d_2;
			d_2.DoubleToString(26);
			cout << endl;
			break;
		}
		case 3:
		{
			String s_1;
			s_1.CharToString("Hello bez world");
			cout << endl;
			break;
		}
		case 4:
		{
			String s_2;
			s_2.StringToCHar("World bez hello");
			cout << endl;
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		default: {cout << "Please,make a normal choice" << endl; break; }
		}
	}
}