
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;
const int n = 3;

double comp(double a[], double b[]) //сравнивам два вектора. используется в самом конце. сравниваем задаваемый с получившимся сравнивается и находит погрешность наибольшую. 
{
	double delta = 0; // погрешность 0
	for (int i = 0; i < n; i++)
	{
		double d; // переменная каждый раз сравниваем и записывем разность координат
		if (a[i] > b[i]) 
			d = a[i] - b[i];
		else d = b[i] - a[i];

		if (d > delta)
			delta = d; // искомая погрешность 
	}
	return delta; //возвращаем значение дельта
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double b[n]; // вектор столбец
	double a[n][n]; // матрица а
	double x[n]; // решение
	double b1[n]; // вектор столбец который мы вычислилы для проверки
	double a_double[n][n]; // дубликаты
	double b_double[n]; // дубликаты для сравнения

	cout << "Если хотите ввести матрицу вручную нажмите 1. Если случайным образом 2. Если хотите проверить матрицу Гильберта 3. " << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		cout << "Введите элемент матрицы " << endl;
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
				cin >> a[i][j];
			cout << endl;
		}
		cout << "Введите стобец b " << endl;
		for (int i = 0; i < n; i++)
			cin >> b[i];
	}
	else if (y == 2)
	{
		for (int i = 0; i < n; i++)
	    {
		for (int j = 0; j < n; j++)
			a[i][j] = rand()*1.f / RAND_MAX*100;
		b[i] = rand()*1.f / RAND_MAX*100;
	    }
	}
	else if (y == 3)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = 1.0f / (i + j + 1);
				cout << "введите слобец b" << endl;
				for (int i = 0; i < n; i++)
					cin >> b[i];
	}
	int time1 = clock();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a_double[i][j] = a[i][j]; //
		b_double[i] = b[i]; // сохраняем оригинал
	}
	for (int i = 0; i < n; i++) // проверка на вырожденность 
	{

		for (int j = i + 1; j < n; j++)
		{
			double k = a[i][0] / a[j][0];
			bool t = true;
			for (int c = 0; c < n; c++) // c за столбцы 
			{
				if (a[i][c] / a[j][c] != k) // 
					t = false; // линейно независимы
			}
			if (t == true) // линейно зависима
				if (b[i] / b[j] == k)// отдельно прверяем вектор столбец 
				{
					cout << "бесконечно много решений ";
					return 0;
				}
				else {
					cout << "матрица несовместна "; // вектор столбцы не имеют схожий коэффициэнт
					return 0; 
				}
		}
	}
	for (int k = 0; k < n; k++) // решение
	{

		for (int j = k+1; j < n; j++) // k строки j столбцы
			a[k][j] = a[k][j] / a[k][k];
		b[k] = b[k] / a[k][k];
		a[k][k] = 1;
		for (int i = k + 1; i < n; i++) // вычитаем 
		{
			double f = a[i][k];
			for (int j = 0; j < n; j++)
				a[i][j] = a[i][j] - a[k][j] * f; // обнулили первый элемент
			b[i] = b[i] - b[k] * f;
		}
		for (int i = k+1; i < n; i++) 
			a[k][i] = a[k][i] / a[k][k]; 
		b[k] = b[k] / a[k][k];
		a[k][k] = 1;
	}
	cout << "\nприведённая матрица " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " "; // выводим вектор столбец который получился
		cout << endl;
	}
	cout << "\nприведённый b " << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	for (int i = n - 1; i >= 0; i--) // 
	{
		x[i] = b[i]; // присваемваем столбец свободных членов
		for (int j = n - 1; j > i; j--) // 
			x[i] -= x[j] * a[i][j];
	}
	cout << "\nрешение: " << endl;
	
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << "\n\nВремя работы программы " << clock() - time1 << endl;
	for (int i = 0; i < n; i++)
	{
		b1[i] = 0;
		for (int j = 0; j < n; j++)
			b1[i] += a_double[i][j] * x[j]; // находим погрешность. проверка для исходного вектора столбца
	}
	double t;
	t = comp(b_double, b1); // вычисленная погрешность
	cout << "\nпогрешность " << t << "мс" << endl;
	return 0;
}