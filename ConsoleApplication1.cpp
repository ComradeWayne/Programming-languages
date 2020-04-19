#include <iostream>
#include <fstream>
#include "stdio.h"
using namespace std;
const int n = 10;

int main()
{
	int sum; // skolko jivih
	int k; // kolich pokoleniy
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество поколений ";
	cin >> k;
	int field[n][n]; // sozdali matricy
	int neib[n][n]; // живые соседи
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) // 1 - живая клетка, 0 - мертвая клетка
			field[i][j] = round(rand() * 1.0f / RAND_MAX); // formiruet 0 i 1 v matrice
	
	
	for (int l = 0; l < k; l++) // menyaet pokolenie
	{
		for (int i = 0; i < n; i++) // smotrim sosedey
			for (int j = 0; j < n; j++) // smotrim sosedey
			{
				neib[i][j] = 0;
				if (i < n - 1) // esli ne kraynay sprava
					neib[i][j] += field[i + 1][j]; // skladyvayem status soseda
				if (i > 0) // esli ne kraynay sleva
					neib[i][j] += field[i - 1][j]; // skladyvayem status soseda
				if (j > 0) 
					neib[i][j] += field[i][j - 1];
				if (j < n - 1) 
					neib[i][j] += field[i][j + 1];
				if (i > 0 && j > 0)
					neib[i][j] += field[i - 1][j - 1];
				if (i > 0 && j < n - 1)
					neib[i][j] += field[i - 1][j + 1];
				if (i < 7 && j > 0) //sleva s nizy
					neib[i][j] += field[i + 1][j - 1];
				if (i < 7 && j < n - 1) // sprava s nizy
					neib[i][j] += field[i + 1][j + 1];
			}
		for (int i = 0; i < n; i++) // shag igry
			for (int j = 0; j < n; j++)
			{
				if (field[i][j] == 1 && neib[i][j] < 2)
					field[i][j] = 0;
				else if (field[i][j] == 1 && (neib[i][j] == 2 || neib[i][j] == 3))
					field[i][j] = 1;
				else if (field[i][j] == 1 && (neib[i][j] > 3))
					field[i][j] = 0;
				else if (field[i][j] == 0 && (neib[i][j] == 3))
					field[i][j] = 1;
			}
		cout << endl;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				sum = sum + field[i][j]; // jivye kletki
			
		}
		cout << "Поколение " << l << endl;
		cout << "Количество живых организмов = " << sum << endl;
		cout << "Количество мёртвых организмов = " << n * n - sum << endl;
		if (sum == 0)
		{
			cout << "Игра окончена" << endl; // predvaritelno zakanchivaem
			return 0;
		}

	}
	cout << "Игра окончена" << endl; 
	return 0;
}