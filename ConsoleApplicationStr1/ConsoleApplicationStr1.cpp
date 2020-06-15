#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include<math.h>

using namespace std;

struct student
{
	char* surname;
	char* name;
	int age;
	bool z;
	char first;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	fstream file;
	file.open("filetext.txt");
	if (!file.is_open())
	{
		cout << "error";
		return -1;
	}

	student* mas = new student[20];
	char c;
	int i = 0;
	bool flag_end = false;
	bool flag_empty = true;
	mas[i].name = new char[20];
	mas[i].surname = new char[20];
	while (!flag_end)
	{
		if (file.eof())
			exit;
		c = file.get();
		flag_empty = false;
		if (file.eof())
			exit;
		int j = 0;
		while (c != ' ')
		{
			mas[i].surname[j] = c;
			j++;
			c = file.get();
		}
		mas[i].surname[j] = '\0';
		mas[i].first = mas[i].surname[0];

		c = file.get();
		j = 0;
		while (c != ' ')
		{

			mas[i].name[j] = c;
			j++;
			c = file.get();
		}
		mas[i].name[j] = '\0';

		file >> mas[i].age;

		c = file.get();
		c = file.get();
		if (c == '+')
			mas[i].z = true;
		else mas[i].z = false;
		if (file.eof())
		{
			flag_end = true;
			break;
		}
		c = file.get();
		if (file.eof())
		{
			flag_end = true;
			break;
		}
		else
		{
			i++;
			if (i == sizeof(mas))
			{
				student* mas_new = new student[sizeof(mas) * 2];
				for (int k = 0; k < sizeof(mas); k++)
					mas_new[k] = mas[k];
				mas = mas_new;
			}
			mas[i].name = new char[20];
			mas[i].surname = new char[20];
		}

	}
	int size = i;
	if (flag_empty)
		return 0;
	for (int j = 0; j <= size; j++)
	{
		int t = 0;

		while (mas[j].surname[t] != '\0')
		{
			cout << mas[j].surname[t];
			t++;
		}
		t = 0;
		cout << " ";
		while (mas[j].name[t] != '\0')
		{
			cout << mas[j].name[t];
			t++;
		}
		cout << " ";
		cout << (int)(mas[j].age) << " ";
		if (mas[j].z == true)
			cout << "зачет" << endl;
		else cout << "не зачет" << endl;
	}
	return 0;
}