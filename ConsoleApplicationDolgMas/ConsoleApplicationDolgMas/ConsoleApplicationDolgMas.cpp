#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int* arr; // указатель для выделения памяти под массив
	int size; // размер массива
	int i;
	int m;
	int elem;
	cout << "n = ";
	cin >> size;
	arr = new int[size];
	//string path = "D:\\test\\sortirovka.txt";
	string path = "D:\\test\\random.txt";
	ifstream fin;
	fin.open(path);
	int S = 0; //сумма элементов массива
	for (i = 0; i < size; i++)
	{
		fin >> arr[i]; //считываем из файла и записываем в массив 
	}
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла\n";
	}
	else
	{
		cout << "Файл открыт\n";
	}
	int temp;
	for (int g = 0; g < size; g++)
	{
		
		if (arr[g] == arr[g]) 
		{
			S += arr[g]; //прибавляем его к сумме 
		}
	}
	cout << "\nСумма чисел элементов массива: " << S;
	int min = (arr[0]);
	int indexMin = 0;
	int max = (arr[0]);
	int indexMax = 0;
	for (int g = 0; g < size; g++)
	{
		if ((arr[g]) >= (max))
		{
			max = arr[g];
			indexMax = g;
		}
		if ((arr[g]) <= (min))
		{
			min = arr[g];
			indexMin = g;
		}
	}
	cout << "\nМинимальный элемент массива: " << min << " его индекс: " << indexMin;
	cout << "\nМаксимальный элемент массива: " << max << " его индекс: " << indexMax;
	/*int Tag = (arr[0]);
	int indexTag = 0;
	for (int m = 0; m < size; m++)
	{
		cout << "\nВведите значение элемента ";
		cin >> m;
		if ((arr[m]) <= (max))
		{
			Tag = arr[m];
			indexTag = m;
		}
		
	}
	cout << "\n\nИндекс элемента массива: " << m << " его индекс: " << indexTag; */
	cout << "\nВведите значение элемента ";
	cin >> elem;
	for (int m = 0; m < size; m++) 
	{
		if ((arr[m]) = (elem))
			cout << m << ' ';
	}
	_getch();
	delete[] arr; // освобождение памяти;
	fin.close();
	return 0;
}