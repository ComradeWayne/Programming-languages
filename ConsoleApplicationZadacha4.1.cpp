#include <iostream>
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, a, b;
	cout << "Введите размер матрицы " << endl;
	cin >> n;
	cout << "Введите a и b" << endl;
	cin >> a >> b;
	int** matrix = new int* [n]; // матрица н строчек. две звезды указывают указывают на массив из игрок. одна создает ячейку игрока
	for (int i = 0; i < n; i++) // для каждой ячейки массив результатов
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = a + round(rand() * 1.0f * (b - a) / RAND_MAX); // 1.0f
	int green, red;
	int indgreen1, indgreen2, indred1, indred2;
	red = b + 1;
	green = a - 1; // заведомо меньше
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i<j && i + j > n-1) //green
			{
				if (matrix[i][j] < 0 && matrix[i][j]> green)
				{

					green = matrix[i][j];
					indgreen1 = i;
					indgreen2 = j;
				}
			}
			if (i > j&& i + j > n-1)
			{
				if (matrix[i][j] > 0 && matrix[i][j] < red)
				{
					red = matrix[i][j];
					indred1 = i;
					indred2 = j;
				}
			}
		}
	if (red == b+1)
		cout << "В красной области положительных элементов нет";
	else if (green == a-1) 
		cout << "В зеленой области отрицательных элементов нет";
	else
	{
		cout << "Исходная матрица " << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
		cout << "max отрицательный " << green << endl;
		cout << "min положительный " << red << endl;
		int t = matrix[indred1][indred2];
		matrix[indred1][indred2] = matrix[indgreen1][indgreen2];
			matrix[indgreen1][indgreen2] = t;
			cout << "Полученная матрица " << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << matrix[i][j] << " ";
				cout << endl;
			}
	}
	return 0;
}

