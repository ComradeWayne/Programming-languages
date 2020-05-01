#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int min, buf;
	int* arr; // указатель для выделения памяти под массив
	int size; // размер массива
	int i;
	// Ввод количества элементов массива
	cout << "n = ";
	cin >> size;
	arr = new int[size]; // выделение памяти под массив
	//string path = "D:\\test\\naoborot.txt";
	string path = "D:\\test\\sortirovka.txt";
	//string path = "D:\\test\\random.txt";
	ifstream fin; // создает объект типа файл
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
	min = 0; // для записи минимального значения
	buf = 0; // для обмена значениями 
	for (int i = 0; i < size; i++) // задает начальную координату диапазона, который будет сжиматься постепенно 
	{
		min = i; // запомним номер текущей ячейки, как ячейки с минимальным значением
		// в цикле найдем реальный номер ячейки с минимальным значением
		for (int j = i + 1; j < size; j++) // ищет минимальный элемент j. минимум от первого до последнего
			min = (arr[j] < arr[min]) ? j : min; // если условие выполняется то min присвоить j. если нет, так и оставить
		// cделаем перестановку этого элемента, поменяв его местами с текущим
		if (i != min) // если не равно min
		{
			buf = arr[i]; // временно записываем 
			arr[i] = arr[min]; 
			arr[min] = buf; 
		}
	}

	for (int i = 0; i < size; i++) //Вывод отсортированного массива
		cout << arr[i] << " ";
	cout << endl;
	delete[] arr; // освобождение памяти;	
	fin.close();
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << endl << "Время работы программы: " << search_time << "мс" << endl;
	return 0;
}