#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

using namespace std;

class Complex
{ // приватная часть
	float Re; 
	float Im;
	float mod; // модуль. для сравнения по модулю
public:
	Complex(float a) // конструктор с одним числом
	{
		set(a, 0);
	}
	Complex(Complex& c) // конструктор копирования
	{
		float a, b;
		c.get(a, b);
		Re = a;
		Im = b;
	}
	Complex() { set(0, 0); }; // конструктор по умолчанию 
	Complex(float a, float b) { set(a, b); }; // конструктор с параметрами. и в нём вызываем метод set, который кладёт a, b в вещественную и мнимую части соответственно
	void set(float a, float b) // метод, помогающий класть данные числа в приватную часть. Принимаем два числа
	{
		Re = a; // вещественная часть ! тут присваиваем одни числа
		Im = b; // мнимая часть
		mod = sqrt(a * a + b * b);
	}
	void get(float& a, float& b) // метод, подающий числа
	{
	    a = Re; // другие числа подали 
	    b = Im;
	}
	Complex operator+ (Complex& c) // сумма чисел
	{
		float a, b;
		c.get(a, b);
		Complex c1(Re + a, Im + b);
		return c1;
	}
	Complex operator- (Complex& c) // разность чисел
	{
		float a, b;
		c.get(a, b);
		Complex c1(Re - a, Im - b);
		return c1;
	}
	Complex operator* (Complex& c) // умножаем числа
	{
		float a, b;
		c.get(a, b);
		Complex c1(Re * a - Im * b, Im * a + Re * b);
		return c1;
	}
	Complex operator/ (Complex& c) // делим числа
	{
		float a, b;
		c.get(a, b);
		Complex c1((Re * a + Im * b)/(a*a+b*b), (Im * a - Re * b)/ (a * a + b * b));
		return c1;
	}
	bool operator> (Complex& c) // логическая операция. булевская
	{
		if (mod > c.getmod()) 
			return true;
		else return false;
	}
	bool operator< (Complex& c) // логическая операция
	{
		if (mod < c.getmod())
			return true;
		else return false;
	}
	bool operator== (Complex& c) // логическая операция
	{
		if (mod == c.getmod())
			return true;
		else return false;
	}
	bool operator!= (Complex& c) // логическая операция
	{
		if (mod != c.getmod())
			return true;
		else return false;
	}
	float getmod()
	{
		return mod;
	}
	friend void input(Complex& c); // дружественная функция ввода
	friend void print(Complex& c); // дружественная функция вывода
};

void print(Complex& c)
{
	if (c.Im == 0)
		cout << c.Re << endl;
	else
	{
		if (c.Im > 0)
			cout << c.Re << "+" << c.Im << "i" << endl;
		else
			cout << c.Re << c.Im << "i" << endl;
	}
}

void input(Complex& c) 
{
	float a, b;
	cout << "Введите вещественную часть " << endl;
	cin >> a;
	cout << "Введите мнимую часть " << endl;
	cin >> b;
	c.set(a, b);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Complex R; //  вводим с клавиатуры
	Complex C; //  вводим с клавиатуры
	input(C); //  вводим с клавиатуры
	input(R); //  вводим с клавиатуры
	//cout << "Исходные числа " << endl;
	//Complex C(5, 2); // или задаём в программе
	//Complex R(2, 3); 
	cout << "Исходные числа " << endl; // вводим с клавиатуры
	print(C);
	print(R);
	Complex SUM;
	SUM = C + R;
	cout << "Сумма равна ";
	print(SUM);
	Complex MULT;
	MULT = C * R;
	cout << "Произведение равно ";
	print(MULT);
	Complex DIM;
	DIM = C - R;
	cout << "Разность равна ";
	print(DIM);
	Complex DIV;
	DIV = C / R;
	cout << "Частное равно ";
	print(DIV);
	
	if (C < R) cout << "Второе число больше";
	else if (C > R) cout << "Первое число больше";
	else cout << "Числа равны по модулю";

	return 0;
}