#include <iostream>
using namespace std;

int palindrom(char* str, int n)
{
	int tr = 1;
	for (int i = 0; i < n * 0.5; i++)
	{
		if (str[i] != str[n - 1 - i])
		{
			tr = 0;
			break;
		}
	}
	return tr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите палиндром английскими буквами" << endl;
	char* str = new char[100];
	int j = 0;
	char c;
	c = getchar();
	while (c != '\n')
	{
		if (c != ' ' && c != '.' && c != '!' && c != '?' && c != ',' && c != ':')
		{
			if (c > 'А' && c < 'Я')
				c = c - 'А' + 'а';
			if (c == toupper(c))
				c = tolower(c);
			str[j] = c;
			j++;

		}
		c = getchar();
	}
	int n = j; // кол-во символов в строке там где остановился курсор
	char* mas = new char[n];
	for (int i = 0; i < n; i++)
		mas[i] = str[i];
	delete[]str;
	str = mas;
	
	int t = palindrom(str, n);
	if (t == 1)
		cout << "\nявляется палиндромом" << endl;
	else
		cout << "\nне является" << endl;
	return 0;
}