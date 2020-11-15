#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

using namespace std;

template <class T>
class Set
{
	int count; // количество 
	T* numbers; // указатель на список из чисел
public:
	Set() // конструктор
	{
		count = 0; // нет элементов в созданном множестве
		numbers = NULL; // указатель на список пуст
	}
	void Add(T n) // вставка
	{
		if (numbers == NULL) // если ранее список пуст
		{
			numbers = new T[1]; // создаём
			numbers[0] = n; 
			count++;
		}
		else // если список не пуст, проверем сколько было до этого элементов
		{
			bool f = true; // флажок
			for (int i = 0; i < count; i++)
				if (numbers[i] == n)
					f = false;
			if (f)
			{
				T* h = new T[count + 1]; // вспомогательная переменная. Массив на 1 больше чем был раньше
				for (int i = 0; i < count; i++) // заполняем массив элементами, которые были до этого
					h[i] = numbers[i]; 
				h[count] = n; // заполняем новым числом, которое к нам пришло
				delete[] numbers; // старый массив удаляем
				numbers = h; // присваиваем новый массив
				count++;
			}
		}
		
	}
	bool def(int z) // метод определения четности
	{
		if (z % 2 == 1)
			return true;
		else return false;
	}
	void print() // метод. печатает все, что получилось
	{
		for (int i = 0; i < count; i++)
			cout << numbers[i] << " ";
		cout << endl;
	}
	int get_count() // метод, который выводит сколько элементов есть в множестве
	{
		return count;
	}
	void del(T k) // удаление элемента
	{
		int i = 0;
		bool f = true;
		while (i < (count) && f) 
		{
			if (numbers[i] == k)
				f = false;
			else i++;
		}
		
		if (i < count)
		{
			for (int j = i; j < count - 1; j++)
				numbers[j] = numbers[j + 1];
			count--;
			T* h = new T[count];
			for (int j = 0; j < count; j++)
				h[j] = numbers[j];
			delete[] numbers;
			numbers = h;
		}
	}
	T get_elem(int i)
	{
		return numbers[i];
	}
	Set <T> union1(Set <T> M) // метод объединения
	{
		Set <T> S;
		for (int i = 0; i < count; i++)
			S.Add(numbers[i]);
		for (int i = 0; i < M.get_count(); i++)
			S.Add(M.get_elem(i));
		return S;
	}
	Set <T> intersect(Set <T> M) // метод пересечения
	{
		Set <T> S;
		for (int i = 0; i < count; i++)
		{
			bool t = false;
			for (int j = 0; j < M.get_count(); j++)
				if (numbers[i] == (M.get_elem(j)))
					t = true;
			if (t)
				S.Add(numbers[i]);
		}
		return S;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	int d;
	fstream file1;
	file1.open("M1.txt");
	if (!file1.is_open())
	{
		cout << "error";
		return -1;
	}
	Set <int> M1;
	while (!file1.eof())
	{
		file1 >> d;
		if (M1.def(d))
			M1.Add(d);
	}
	fstream file2;
	file2.open("M2.txt");
	if (!file2.is_open())
	{
		cout << "error";
		return -1;
	}
	Set <int> M2;
	while (!file2.eof())
	{
		file2 >> d;
		if (M2.def(d))
			M2.Add(d);
	}
	fstream file3;
	file3.open("M3.txt");
	if (!file3.is_open())
	{
		cout << "error";
		return -1;
	}
	Set <int> M3;
	while (!file3.eof())
	{
		file3 >> d;
		if (M3.def(d))
			M3.Add(d);
	}
	cout << "Первое множество М1" << endl;
	M1.print();
	cout << "Второе множество М2" << endl;
	M2.print();
	cout << "Третье множество М3" << endl;
	M3.print();
	cout << "1. Большее количество элементов в множестве " << endl;
	int a = M1.get_count();
	int b = M2.get_count();
	int c = M3.get_count();
	if ((a == b) && (a == c))
		cout << "Во всех множествах одинаковое количество элементов: " << a << endl;
	else if (a == b)
	{
		if (a > c)
			cout << "Больше элементов в М1 и М2: " << a << endl;
		else cout << "Больше элементов в М3: " << c << endl;
	}
	else if (a == c)
	{
		if (a > b)
			cout << "Больше элементов в М1 и М3: " << a << endl;
		else cout << "Больше элементов в М2: " << b << endl;
	}
	else if (b == c)
	{
		if (b > a)
			cout << "Больше элементов в М2 и М3: " << b << endl;
		else cout << "Больше элементов в М1: " << a << endl;
	}
	else
	{
		if ((a>b) && (a>c))
			cout << "Больше элементов в М1: " << a << endl;
		else if ((b > a) && (b > c))
			cout << "Больше элементов в М2: " << b << endl;
		else if ((c > a) && (c > b))
			cout << "Больше элементов в М3: " << c << endl;
	}
	////
	cout << "2. Пересечение множеств М1 и М2" << endl;
	Set <int> M5 = M1.intersect(M2);
	M5.print();
	if (M5.get_count() == 0)
		cout << "Эти множества не пересекаются" << endl;
	if (M5.get_count() == M1.get_count())
		cout << "Множество М1 вложено в М2" << endl;
	else if (M5.get_count() == M2.get_count())
		cout << "Множество М2 вложено в М1" << endl;
	////
	cout << "3. Добавить элемент в М1" << endl;
	cout << "Введите число ";
	int t;
	cin >> t;
	if (M1.def(t))
		M1.Add(t);
	cout << "Множество М1 после добавления нового элемента" << endl;
	M1.print();
	cout << "4. Удаление элемента из М2" << endl;
	cout << "Введите число ";
	cin >> t;
	M2.del(t);
	cout << "Множество М2 после возможного удаления элемента" << endl;
	M2.print();
	cout << "5. Объединение множеств М2 и М3" << endl;
	Set <int> M4 = M2.union1(M3);
	M4.print();
	return 0;
}
