#include <iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int max_length = 0; // смотрит на макс длину в строчке. 
	int length = 0; // читает длину каждого слова
	fstream file;
	file.open("filetext.txt");
	if (!file.is_open())
	{
		cout << "error";
		return -1;
	}
	char a = file.get(); // текущий символ, берём по одому символу и кладем в а
	char* ans = new char[20]; // строчка из чаров. туда кладём длинное слово. заранее зарезервировали
	char* str = new char[20]; // длинное слово в каждой строчке.
	while (1) // пока не кончится файл
	{
		if (a == '\n') // если перенос строки. если перенос есть - строка нас не интересует
		{
			
			max_length = 0; // обнуляем
			length = 0; 
			delete[] str;
			str = new char[20];
			
		}
		else if (a == ' ' || a == ',' || a == ';' || a == '.' || a == '!' || a == '?')
		{
			if (length > max_length) // если найденное слово больше макс длина из всех слов которое мы встретили
			{
				max_length = length; 
					ans = new char[length]; // кладем слово большее прежнего
				for (int i = 0; i < max_length; i++) 
					ans[i] = str[i]; // копируем в анс новое большое слово
			}
			length = 0;
			delete[] str;
			
			str = new char[20]; // создали чистую

		}
		else
		{
			str[length] = a; // если не встретили ни перенос ни знак. кладем в ячейки буквы
			length++;
		}
		a = file.get(); // 
		if (file.eof()) // перепроверяем последнее крупное слово 
		{
			if (length > max_length)
			{
				max_length = length;
				ans = new char[length];
				for (int i = 0; i < max_length; i++)
					ans[i] = str[i];
			}
			break;
		}
	}
	cout << "Максимальная длина слова последней строчки = " << max_length << endl;
	for (int i = 0; i < max_length; i++) // нам нужно вывести каждую букву. поэтому цикл
		cout << ans[i];
	return 0;
}