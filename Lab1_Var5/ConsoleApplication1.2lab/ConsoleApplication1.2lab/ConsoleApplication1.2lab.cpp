#include <iostream>
#include <fstream>
#include "stdio.h"
using namespace std;

float* delfun(float* mas, int k, int n)
{
	float* mas2 = new float[n - 1]; // до того как хотим удалить кпирум до того как хотим удалить
	for (int i=0; i < k; i++)
		mas2[i] = mas[i];
	for (int i = k; i < n - 1; i++) // копируем со сдвигом 
		mas2[i] = mas[i + 1];
	return mas2;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	float a, b;
	int k;
	cout << "Введите количество чисел" << endl;
	cin >> n;
	cout << "\nВведите границу интервала" << endl;
	cin >> a >> b;
	cout << "\nВведите k" << endl; // как фильтруется граница после все удаляем
	cin >> k;
	float* mas = new float[n];
	for (int i = 0; i < n; i++)
		mas[i] = a + rand() * (b - a) / RAND_MAX; // нормировали интервал
	cout << "\nБыло" << endl;
	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	for (int i = 0; i < n; i++)
	{
		if ((mas[i]) > k) // если элемент больше заданного к, 
		{
			mas = delfun(mas, i, n);
			delfun(mas, i, n); //удаляющая функция
			n--; // коррекция длины массива
			i--; // проверка нового элемента

		}
	}
	cout << "\nСтало" << endl;
	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";

}
	
