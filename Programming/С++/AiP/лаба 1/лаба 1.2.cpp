#include <iostream>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	string N;
	cout << "Введите количество ворон в стае\n";
	cin >> N;
	bool test=true;
	for (int i = 0; i<N.size(); i++)
	{
		if (N[i] == '-') { cerr << "Количество ворон в стае не может принимать отрицательных значений!\n"; test = false; return 1; break; }
		else 
			if (isalpha(N[i])) { cerr << "Число ворон в стае должно иметь числовое значение!\n"; test = false; return 1; break; }
			else if ((N[i] == '.') || (N[i] == ','))
			{
				bool test2 = true;
				for (int j = i + 1; j < N.size(); j++)
					if (N[j] != '0') {test2 = false; break;}
				if (!test2) { cerr << "Количество ворон в стае не может принимать дробных значение!\n"; test = false; return 1; break; }
				else N = N.substr(0,i);
			}
	}
	if (test)
	{ if (N == string(1,'0')) cout << "В стае нет ворон\n";
	else
		if ((N[N.size()-1]=='1') & (N[N.size()-2] != '1')) cout << "В стае " << N << " воронa\n";
		else
			if( ((N[N.size() - 1] == '2')|| (N[N.size() - 1] == '3')|| (N[N.size() - 1] == '4'))& (N[N.size() - 2] != '1')) cout << "В стае " << N << " вороны\n";
			else cout << "В стае " << N << " ворон\n";
	}
	return 0;
}
