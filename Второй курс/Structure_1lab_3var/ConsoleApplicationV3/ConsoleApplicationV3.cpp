#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include<math.h>

using namespace std;

struct Data {
	int day;
	int month;
	int year;
	Data* next; // в файле
	void Vvod(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
		next = NULL;
	}
	void Print()
	{
		if (day < 10)
			cout << "0";
		cout << day << ".";
		if (month < 10)
			cout << "0";
		cout << month << "." << year << endl;
	}
	Data Prev()
	{
		int d, m, y;
		if (day > 1)
		{
			d = day - 1;
			m = month;
			y = year;
		}
		else
		{
			if (month == 1 || month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
				d = 31;
			else if (month == 5 || month == 7 || month == 10 || month == 12)
				d = 30;
			else if (month == 3)
			{
				if (year % 4 == 0)
					d = 29;
				else d = 28;
			}
			if (month != 1)
			{
				y = year;
				m = month - 1;
			}
			else
			{
				m = 12;
				y = year - 1;
			}
		}
		Data Prev;
		Prev.Vvod(d, m, y);
		return Prev;
	}
	Data Post()
	{
		int d, m, y;
		if (day < 30 && month != 2)
		{
			d = day + 1;
			m = month;
			y = year;
		}
		else if (month == 2)
		{
			if (day < 28)
			{
				d = day + 1;
				m = month;
				y = year;
			}
			else if (day == 28 && (year % 4 == 0))
			{
				d = 29;
				m = month;
				y = year;
			}
			else
			{
				d = 1;
				m = 3;
				y = year;
			}
		}
		if (day == 31)
		{
			d = 1;
			if (month < 12)
			{
				m = month + 1;
				y = year;
			}
			else
			{
				m = 1;
				y = year + 1;
			}
		}
		if (day == 30)
		{
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				d = 31;
				m = month;
				y = year;
			}
			else
			{
				d = 1;
				m = month + 1;
				y = year;
			}
		}
		Data Post;
		Post.Vvod(d, m, y);
		return Post;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	int d, m, y, k = 1;
	char c;
	Data* h = NULL; // вспомогательная переменная. заполняет каждое звено
	Data* List = NULL;
	fstream file;
	file.open("Data.txt");
	if (!file.is_open())
	{
		cout << "error";
		return -1;
	}
	while (!file.eof())
	{
		if (List == NULL)
		{
			List = new Data();
			h = List;
		}
		else
		{
			h->next = new Data();
			h = h->next;
		}
		file >> d;
		file >> c;

		file >> m;
		file >> c;

		file >> y;
		(*h).Vvod(d, m, y);
	}
	h = List;
	cout << "Весь список дат:" << endl;
	while (h != NULL)
	{
		cout << k << ") ";
		k++;
		cout << "Текущая дата:" << endl;
		(*h).Print();
		cout << "Предыдующая дата:" << endl;
		(*h).Prev().Print();
		cout << "Следующая дата:" << endl;
		(*h).Post().Print();
		h = h->next;
	}
	h = List;
	cout << "Даты, для которых следующие не попадут в другой месяц" << endl;
	k = 1;
	while (h != NULL)
	{
		
		if ((*h).Post().month == (*h).month)
		{
			cout << k << ") ";
			k++;
			cout << "Текущая дата:" << endl;
			(*h).Print();
			cout << "Следующая дата:" << endl;
			(*h).Post().Print();
		}
		h = h->next;
	}
}