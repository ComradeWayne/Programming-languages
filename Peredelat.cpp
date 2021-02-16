#include <iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>
#include <Windows.h>

using namespace std;

const float pi = 3.1416;

class MyEx // созадали класс исключение
{
	const char* m;
	float t;
public:
	MyEx(const char* message, float t1) // конструктор MyEx
	{
		m = message;
		t = t1;
	}
	int GetValue() { return t; } // возвращает переменную t из приватной части. метод обращается к закрытым полям
	const char* GetMessage() { return m; } // возвращает переменную m из приватной части. метод обращается к закрытым полям
};

class Figure // абстракный класс фигур
{
protected:
	float* coords;
public:
	Figure() {} // пустой конструктор
	virtual void Show() = 0; // абстрактный метод. он будет у потомков-фигур
	virtual float CalcArea() = 0; // абстрактный метод. он будет у потомков-фигур

};

class Recctangle : public Figure // дочерняя фигура, прямоугольник. наследует параметры
{
public:
	Recctangle() // конструктор по умолчанию
	{
		coords = new float[4];
		cout << "Введите координаты левого нижнего угла прямоугольника:";
		cout << "x=";
		cin >> coords[0];
		cout << "y=";
		cin >> coords[1];
		cout << "Введите координаты правого верхнего  угла прямоугольника:";
		cout << "x=";
		cin >> coords[2];
		cout << "y=";
		cin >> coords[3];
	}
	virtual ~Recctangle()
	{
		delete[] coords;
	}
	virtual void Show()
	{
		cout << "Координаты левого нижнего угла равны: " << coords[0] << " " << coords[1] << endl;
		cout << "Координаты правого верхнего угла равны: " << coords[2] << " " << coords[3] << endl;
	}
	virtual float CalcArea()
	{
		return abs((coords[3] - coords[1]) * (coords[2] - coords[0]));
	}
};

class Circle : public Figure
{
public:
	Circle()
	{
		coords = new float[3];
		cout << "Введите координаты центра круга:";
		cout << "x=";
		cin >> coords[0];
		cout << "y=";
		cin >> coords[1];
		cout << "Введите радиус круга:";
		cout << "r=";
		cin >> coords[2];
		if (coords[2] < 0) // ИСКЛЮЧЕНИЕ ДЛЯ РАДИУСА
		{
			MyEx Ex("Неверный радиус", coords[2]);
			throw Ex;
		}
	}
	virtual ~Circle()
	{
		delete[] coords;
	}
	virtual void Show()
	{
		cout << "Координаты центра круга равны: " << coords[0] << " " << coords[1] << endl;
		cout << "Радиус равен: " << coords[2] << endl;
	}
	virtual float CalcArea()
	{
		return pi * coords[2] * coords[2];
	}

};

class Triangle : public Figure
{
public:
	Triangle() :Figure()
	{
		coords = new float[6];
		cout << "Введите координаты первой вершины треугольника:";
		cout << "x=";
		cin >> coords[0];
		cout << "y=";
		cin >> coords[1];
		cout << "Введите координаты второй вершины треугольника:";
		cout << "x=";
		cin >> coords[2];
		cout << "y=";
		cin >> coords[3];
		cout << "Введите координаты третьей вершины треугольника:";
		cout << "x=";
		cin >> coords[4];
		cout << "y=";
		cin >> coords[5];
		if ((coords[0] == coords[4]) && (coords[0] == coords[2]))
		{
			MyEx Ex("Несуществующий треугольник", 0); // ИСКЛЮЧЕНИЯ ДЛЯ ТРЕУГОЛЬНИКА
			throw Ex;
		}
		if ((coords[1] == coords[5]) && (coords[1] == coords[3]))
		{
			MyEx Ex("Несуществующий треугольник", 0); //////
			throw Ex;
		}
		if ((coords[4] - coords[0]) / (coords[2] - coords[0]) == (coords[5] - coords[1]) / (coords[3] - coords[1]))
		{
			MyEx Ex("Несуществующий треугольник", 0); //////
			throw Ex;
		}
	}
	virtual ~Triangle()
	{
		delete[] coords;
	}
	virtual void Show()
	{
		cout << "Координаты первой вершины равны: " << coords[0] << " " << coords[1] << endl;
		cout << "Координаты второй вершины равны: " << coords[2] << " " << coords[3] << endl;
		cout << "Координаты третьей вершины равны: " << coords[4] << " " << coords[5] << endl;
	}
	virtual float CalcArea()
	{
		float p;
		float a, b, c;
		a = sqrt(pow(coords[0] - coords[2], 2) + pow(coords[3] - coords[1], 2));
		b = sqrt(pow(coords[0] - coords[4], 2) + pow(coords[3] - coords[5], 2));
		c = sqrt(pow(coords[4] - coords[2], 2) + pow(coords[5] - coords[1], 2));
		p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c)); // формула Герона
	}
};

class cylinder
{
	Figure* F; // указатель на будущую фигуру
	float h; // высота
public:
	/*cylinder(Figure* F1, float h1) // конструктор
	{
		F = F1;
		h = h1;
	}*/
	cylinder() // конструктор по умолчанию. 
	{
		int n;
		cout << "Введите 1, если хотите круг; 2 , если хотите прямоугольник; и 3, если хотите треугольник" << endl;
		cin >> n;
		if (n == 1)
			F = new Circle();
		else if (n == 2)
			F = new Recctangle();
		else if (n == 3)
			F = new Triangle();
		else // ИСКЛЮчЕНИЕ ЕСЛИ НЕКОРРЕКТНО ВЫБРАЛИ ФИГУРУ
		{
			MyEx Ex("Неправильная команда", n);
			throw Ex;
		}
		F->Show(); // показывает созданный цилиндр
		cout << "Введите высоту цилиндра" << endl;
		cin >> h;
		if (h <= 0) // ИСКЛЮЧЕНИЕ ДЛЯ ВЫСОТЫ ФИГУРЫ
		{
			MyEx Ex("Неправильная высота цилиндра", h);
			throw Ex;
		}
	}
	~cylinder()
	{
		delete F;
	}
	float CalcVolume()
	{
		return ((F->CalcArea()) * h);
	}
	void Show()
	{
		cout << "Информация об основании цилиндра" << endl;
		F->Show();
		cout << "Высота цилиндра равна" << h << endl;
	}


};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try // единожды создаёт. не авариЙно завершает программу
	{
		cylinder C;
		cout << "Объём цилиндра равен" << (C.CalcVolume()) << endl;
	}
	catch (MyEx Ex) // если не правильно что-то задано try обращается к catch. Выводим саму ошибку (причину и неверный параметр)
	{
		cout << Ex.GetMessage() << " " << Ex.GetValue() << endl; // обращаемся к закрытому полю
	}
	return 0;
}
