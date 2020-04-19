#include <iostream>
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;

int main()
{
	int n, m;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество стрелков" << endl;
	cin >> n;
	cout << "Введите количество выстрелов" << endl;
	cin >> m;
	int** matrix = new int* [n]; // матрица н строчек. две звезды указывают указывают на массив из игрок. одна создает ячейку игрока
	for (int i = 0; i < n; i++) // для каждой ячейки массив результатов
		matrix[i] = new int[m]; // массив из их результатов 
	cout << "Внесите результаты " << endl;
	for (int i = 0; i < n; i++) // 
	{
		cout << i + 1 << " игрок" << endl; // 
		for (int j = 0; j < m; j++) // м результаты
			cin >> matrix[i][j]; // кладет в соответ ячейку
	}
	int* res = new int[n]; // сумма очков игроков
	for (int i = 0; i < n; i++) 
	{
		res[i] = 0; //
		for (int j = 0; j < m; j++) // прибавляем результат
			res[i] += matrix[i][j]; 
	}
	int max = 0; // обнулили максимум
	for (int i = 0; i < n; i++) // н игроков
		if (res[i] > max) // 
			max = res[i]; // обновить макс найденный балл 
	cout << "Номера победителей " << endl;
	for (int i = 0; i < n; i++) // выводим победителей
		if (res[i] == max)
	cout << i + 1 << " " << endl;
	return 0;
}