#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int* arr; // указатель для выделения памяти под массив
	int size; // размер массива
	int i;
	// Ввод количества элементов массива
	cout << "n = ";
	cin >> size;
	arr = new int[size]; // выделение памяти под массив
	//string path = "D:\\test\\naoborot.txt";
	//string path = "D:\\test\\sortirovka.txt";
	string path = "D:\\test\\random.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла\n";
		return 0;
	}
	else
	{
		cout << "Файл открыт\n";
	}
	for (i = 0; i < size; i++)
	{
		fin >> arr[i]; //считываем из файла и записываем в массив 
	}
	unsigned int start_time = clock();
	cout << endl;
	for (int i = 1; i < size; i++) 
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) // пока j>0 и элемент j-1 > j.  вытакливаем элемент в положенное место 
			swap(arr[j - 1], arr[j]); // когда нашли меняем местами элементы j и j-1. меняем до тех пор пока элемент не станет меньше чем последующий
	cout << "Выводим отсортированный массив\n: ";
	for (int i = 0; i < size; i++) cout << arr[i] << ' '; // выводим элементы
	delete[] arr; // освобождение памяти;
	fin.close();
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << endl << "Время работы программы: " << search_time << "мс" << endl;
	return 0;
}