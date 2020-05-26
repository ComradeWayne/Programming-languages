#include <iostream>
#include <fstream>
#include "stdio.h"
using namespace std;

int func(int* m, int n)
{
	if (n == 1) return m[0]; // если один элемент то он минимум и выходит
	int* newm = new int[n - 1]; // создаем новый массив без нулевого
	for (int i = 0; i < n - 1; i++) 
		newm[i] = m[i + 1]; // перезаписываем. элементы сдвигаем вперед
	int f = func(newm, n - 1); // нахождение минимума в новом массиве
	if (m[0] < f) // cравниваем из нашедших
		return m[0];
	else return f;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов массива ";
	cin >> n;
	int* mas = new int[n]; // создаем массив
	cout << "Введите элементы массива "; 
	for (int i = 0; i < n; i++) // считываем и кладем 
		cin >> mas[i];
	int min = func(mas, n); // функция возвращает свое минимальное значение
	if (min >= 0) // если минимальный положительный то нет отрицательных
		cout << "Отрицательных нет" << endl;
	else cout << "Минимальное значение " << min << endl;
	return 0;
}