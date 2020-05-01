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
	string path = "D:\\test\\sortirovka.txt";
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
	
	unsigned int start_time = clock();

	int step = size / 2; //создаём шаг. сравниваем с элементом, который стоит через определённое число элементов
	while (step > 0)
	{
		for (int i = 0; i < (size - step); i++) { 
			int j = i; //будем идти начиная с i-го элемента, т.е. с первого
			while (j >= 0 && arr[j] > arr[j + step]) // сравниваем j с arr j + step
				//пока не пришли к началу массива
				//и пока рассматриваемый элемент больше
				//чем элемент находящийся на расстоянии шага
				/*
				j>=0: Пока мы вернулись к первому элементу массива
					И
				a[j] > a[j + step]): пока  элемент, который мы в данный момент рассматриваем, больше,
				чем элемент, который находится на расстояния шага
				*/
			{
				//меняем их местами
				int temp = arr[j];
				arr[j] = arr[j + step]; 
				arr[j + step] = temp;
				j--; // уменьшаем справо на лево
			}
		}
		step = step / 2; //каждый раз уменьшаем расстояние шага
	}
	cout << "Выводим отсортированный массив\n: ";
	for (int i = 0; i < size; i++) cout << arr[i] << ' ';
	delete[] arr; // освобождение памяти;
	fin.close();
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << endl << "Время работы программы: " << search_time << "мс" << endl;
	return 0;
}