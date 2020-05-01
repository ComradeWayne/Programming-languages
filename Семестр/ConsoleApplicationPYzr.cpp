#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	unsigned int start_time = clock();
	int* arr; // указатель для выделения памяти под массив
	int size; // размер массива
	int i;
	// Ввод количества элементов массива
	cout << "n = ";
	cin >> size;
	arr = new int[size]; // выделение памяти под массив
	string path = "D:\\test\\naoborot.txt";
	//string path = "D:\\test\\sortirovka.txt";
	//string path = "D:\\test\\random.txt";
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
	int temp; // временная переменная для обмена элементов местами

		// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) { // сколько будет этапов обмена
		for (int j = 0; j < size - i - 1; j++) { // сколько обменов будет внутри пройденного этапа
			if (arr[j] > arr[j + 1]) { // сравниваем соседов
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	// Вывод отсортированного массива на экран
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	fin.close();
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << endl << "Время работы программы: " << search_time << "мс" << endl;
	return 0;
}