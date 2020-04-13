#include <iostream>
#include <fstream>
#include "stdio.h"

using namespace std;

int* func(int* mas, int n, int a)
{
	int* mas2 = new int[n + 1];
	for (int i = 0; i < n; i++)
		mas2[i] = mas[i];
	mas2[n] = a;
	return mas2;
}
void sort(int* mas, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				// меняем элементы местами
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
}

int main()
{
	int a;
	int n = 0;
	int* arr = new int[0];
	ifstream file;
	file.open("тестовый массив.txt");
	if (!file.is_open())
	{
		printf("error");
		return -1;
	}
	while (!file.eof())
	{
		file >> a;
		if (file.eof())
			exit;
		arr = func(arr, n, a);
		n++;
	}
	sort(arr, n);
	file.close();
	for (int i = 0; i < n; i++)
		printf("%d \n", arr[i]);
	scanf_s("%d", &n);
	return 0;
}