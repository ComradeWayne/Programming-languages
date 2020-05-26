#include <iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int col_pr = 0; // количество предложений
	int col_w = 0; // количество слов
	fstream file;
	file.open("filetext.txt");
	if (!file.is_open())
	{
		cout << "error";
		return -1;
	}
	char a; // для считывания каждого символа
	
	a = file.get();
	int tr = 1; // для того чтобы не дублировались слова. индикатор
	while (1)
	{
		if ((a == ',' || a == ' ' || a == ':' || a == ';' || a == '\0' || a == '-' || a == L'—') && tr == 0) // тире не корректно работает
		{
			col_w++;
			tr = 1;
		}
		else if ((a == '.' || a == '!' || a == '?') && tr ==0)
		{
			col_pr++;
			col_w++;
			tr = 1;
		}
		else tr = 0; // был не разделитель а буква
		a = file.get(); // если конец файла выходим из цикла
		if (file.eof())
			break;
	}
	cout << "Количество предложений " << col_pr << endl;
	cout << "Количество слов " << col_w << endl;
	return 0;
}
