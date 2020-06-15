#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include<math.h>

using namespace std;

struct abonent
{
	long int number;
	char* name;
	char* tarif;
	int payment;
};

struct elem
{
	abonent A;
	elem* next;
};

void print(elem* list)
{
	elem* h = list;
	while (h!= NULL)
	{
		cout << (h->A).number << " ";
		int i = 0;
		while ((h->A).name[i] != '\0')
		{
			cout << (h->A).name[i];
			i++;
		}
		cout << " ";
		i = 0;
		while ((h->A).tarif[i] != '\0')
		{
			cout << (h->A).tarif[i];
			i++;
		}
		cout << " ";
		cout << (h->A).payment;
		h = h->next;
		cout << endl;
	}
}

void search(elem* list)
{
	elem* h;
	h = list;
	while (h != NULL)
	{
		if (((h->A).name[0] == 'I') && ((h -> A).name[1] == 'v') && ((h -> A).name[2] == 'a') && ((h -> A).name[3] == 'n') && ((h -> A).name[4] == 'o') && ((h -> A).name[5] == 'v') && ((h -> A).name[6] == ' '))
			cout << (h->A).number << endl;
		h = h->next;
	}
}

void lowP(elem* list)
{
	elem* h = list;
	while (h!= NULL)
	{
		if ((h->A).payment < 84)
		{
			cout << (h->A).number << " ";
			int i = 0;
			while ((h->A).name[i] != '\0')
			{
				cout << (h->A).name[i];
				i++;
			}
			cout << " ";
			i = 0;
			while ((h->A).tarif[i] != '\0')
			{
				cout << (h->A).tarif[i];
				i++;
			}
			cout << " ";
			cout << (h->A).payment;
			cout << endl;
		}
		h = h->next;
	}
}

bool compare(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] == s2[i])
		i++;
	if (s1[i] > s2[i])
		return true;
	else return false;
}

int main()
{
	elem* list;
	list = NULL;
	setlocale(LC_ALL, "Russian");
	fstream file;
	file.open("filetest.txt");
	if (!file.is_open())
	{
		cout << "error";
		return -1;
	}
	while (!file.eof())
	{
		elem* h = new elem();
		file >> (h->A).number;
		char c;
		c = file.get();
		bool t = true;
		bool f = false;
		int i = 0;
		(h->A).name = new char[20];
		while (t)
		{
			c = file.get();
			(h->A).name[i] = c;
			i++;
			if (c == '.' && f == false)
				f = true;
			else if (c == '.' && f == true)
				t = false;
		}
		(h->A).name[i] = '\0';
		c = file.get();
		i = 0;
		c = file.get();
		(h->A).tarif = new char[20];
		while (c != ' ')
		{
			(h->A).tarif[i] = c;
			i++;
			c = file.get();
		}
		(h->A).tarif[i] = '\0';
		file >> (h->A).payment;
		elem* r;
		elem* l;
		r = list;
		if (list == NULL || compare((list->A).name, (h->A).name))
		{
			r = list;
			list = h;
			list->next =r;
		}
		else
		{
			l = r;
			r = r ->next;

				while (r != NULL && !compare((r->A).name, (h->A).name))
				{
					l = r;
					r = r->next;
				}
			l->next = h;
			h->next = r;
		}
		c = file.get();
	}
	print(list);
	cout << "Номера абонентов с фамилией Иванов" << endl;
	search(list);
	cout << "Абоненты с дешёвым тарифом" << endl;
	lowP(list);
	return 0;
}