#include <iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char** l = new char* [20]; // указатель на строки из чаров. указатель на указатели - на ячейки а ячейки показывают где лежит строка
	int* num = new int[20]; // 
	int j = 0;
	int length = 0; // читает длину каждого слова
	fstream file;
	file.open("filetext.txt");
	if (!file.is_open())
	{
		cout << "error";
		return -1;
	}
	char a = file.get(); // текущий символ, берём по одому символу и кладем в а
	
	char* str = new char[20]; // длинное слово в каждой строчке.
	while (1) // пока не кончится файл
	{
		if (a == '\n' || a == ' ' || a == ',' || a == ';' || a == '.' || a == '!' || a == '?') // если перенос строки. если перенос есть - строка нас не интересует
		{
			if (length != 0) // если пробел или знак то кладем слово в реестр 
			{
				l[j] = new char[length]; // создали массив длинной length
				for (int i = 0; i < length; i++) 
					l[j][i] = str[i]; // скопировали слово в эль
				num[j] = length; // кладем длину полученного слова 
				str = new char[20]; // сделали чистым
				length = 0; // обновили
				j++; // перевели курсор на новую строчку
			}
		}
		else
		{
			str[length] = a; // кладем букву в свободную ячейку
			length++; // дальше идем
		}
		a = file.get(); // считали новую букву
		if (file.eof()) // перепроверяем. если кончился файл 
		{
			if (length != 0)
			{
				l[j] = new char[length];
				for (int i = 0; i < length; i++)
					l[j][i] = str[i];
				num[j] = length;
				str = new char[20];
				length = 0;
				j++;
			}
			break;
		}
	}
	while (1)
	{
		int min = 20;
		for (int i = 0; i < j; i++)
			if (num[i] < min) // ищем минимальное значение
				min = num[i];
		for (int i = 0; i < j; i++) 
			if (num[i] == min)
			{
				for (int k = 0; k < min; k++) // выводим из реестра.
					cout << l[i][k]; // выводим минимальное
				cout << endl;
				num[i] = 21; // чтобы наименьшее слово повторно не выводить
			}
		if (min == 20) // если в точности равен то выходим
			break;
	}
	return 0;
}