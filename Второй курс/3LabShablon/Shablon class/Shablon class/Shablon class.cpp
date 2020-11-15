#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

using namespace std;

class Complex // класс комплексных чисел
{
    double re, im; // целая и мнимая части

    // создаем конструкторы
public:

    Complex() { re = 0; im = 0; };

    Complex(double r) // конструктор по умолчанию
    {
        re = r;
        im = 0;
    }

    Complex(double r, double i) // конструктор по умолчанию
    {
        re = r;
        im = i;
    }

    Complex(Complex& c) // конструктор копирования
    {
        re = c.re;
        im = c.im;
    }

    ~Complex() {}

    float abs() // Модуль комплексного числа
    {
        return sqrt(re * re - im * im);
    }

    void set_(double r, double i)
    {
        re = r;
        im = i;
    }
    Complex& operator = (Complex& c) // перегрузка оператора присваивания
    {
        re = c.re;
        im = c.im;

        return (*this);
    }

    Complex& operator + (Complex& c) // перегрузка оператора сложения
    {


        re = re + c.re;
        im = im + c.re;

        return *this;
    }

    Complex& operator - (Complex& c) // перегрузка оператора вычитания
    {


        re = re - c.re;
        im = im - c.re;

        return *this;
    }

    Complex& operator * (Complex& c) // перегрузка оператора умножения
    {


        re = re * c.re;
        im = re * c.im;

        return *this;
    }

    Complex& operator / (Complex& c) // перегрузка оператора деления
    {


        double r = c.re * c.re + c.im * c.im;
        re = (re * c.re + im * c.im) / r;
        re = (im * c.re - re * c.im) / r;

        return *this;
    }

    friend ostream& operator<<(ostream&, const Complex&); // перегрузка оператора <<
    friend istream& operator>>(istream&, const Complex&); // перегрузка оператора >>

};

ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.re;
    if (c.im >= 0)
        out << "+";
    else
        out << "-";
    out << c.im << "i";

    return out;
}

istream& operator>>(istream& in, const Complex& c)
{
    in >> c.re >> c.im;

    return in;
}



//template <typename T> Можно и так
template <class T>
class Vector
{
private:
    int n;                 //размер вектора
    T* coords;            //указатель на массив с координатами вектора

public:
    Vector(int k = 3) { coords = new T[k]; n = k; };           //Конструктор и деструктор
    ~Vector() { cout << "destructor  " << endl; delete[] coords; coords = nullptr; };
    Vector(const Vector& b);// конструктор копирования
//const означает, что объект передается по ссылке, но изменять его нельзя
    Vector& operator = (const Vector& b);// оператор присваивания
    void Set_n(int k);             //Метод задания размера вектора
    void Set_coords(T value, int i); //Метод для задания жлемента вектора
    int Get_n(); // метод получения размера вектора

    T Get_coords(int i) const; // метод получения элемента вектора
// добавила спецификатор const , т. к. метод используется в операторе +
// а параметр, для которого эта функция используется определен как const
    double Get_size();

    Vector operator+(Vector&); //перегрузка оператора сложения без создания локальной копии объекта с передачей по ссылке
    T operator *(Vector&);
};

template <class T> Vector<T>::Vector(const Vector& b)
{
    n = b.n;
    coords = new T[n]; // выделяем необходимый объем памяти
    for (int i = 0; i < n; i++) coords[i] = b.coords[i]; // копируем поэлементно
}

template <class T> Vector<T>& Vector<T>::operator = (const Vector<T>& b)
{
    n = b.n;
    delete[] coords; // освобождаем память которая была выделена раньше
    coords = new T[n];// выделяем необходимый объем памяти
    for (int i = 0; i < n; i++)
        coords[i] = b.coords[i];   // копируем поэлементно
    return *this;
}

template <class T> T Vector<T>::operator *(Vector& b)
{
    int n = b.n;
    T s = 0;

    for (int i = 0; i < n; i++)
        s += coords[i] * b.coords[i];
    return s;
}


template <class T> double Vector<T>::Get_size()
{
    //Complex z;
    //z.set_(Get_n(), 0);
    //return z;
    return Get_n();
}

template<> double Vector<double>::Get_size()
{
    double s = 0;

    for (int i = 0; i < n; i++)
        s += coords[i] * coords[i];
    return sqrt(s);

};

template<> double Vector<int>::Get_size()
{
    double s = 0;

    for (int i = 0; i < n; i++)
        s += coords[i] * coords[i];
    return sqrt(s);

};

template <class T> Vector<T> Vector<T>:: operator+ (Vector<T>& b)
{
    int k = b.n;
    //int k=b.Get_n();


    Vector temp(k);
    //  Вам необходимо добавить проверку размерности массивов - они должны быть одинаковой длины

    for (int i = 0; i < k; i++)
        temp.coords[i] = coords[i] + b.coords[i];
    return temp;
}

template <class T> void Vector<T>::Set_n(int k)
{
    n = k;
}
template <class T> void Vector<T>::Set_coords(T value, int i)
{
    coords[i] = value;
}

template <class T> int Vector<T>::Get_n()
{
    return n;
}
template <class T> T Vector<T>::Get_coords(int i) const
{
    return coords[i];
}




int main()
{
    setlocale(LC_ALL, "Russian");
    double d;
    int n;
    int i;
    int m;
    
    cout << "Демонстрация работы с типом int" << endl;
    cout << "Введите размерность целочисленного вектора" << endl;
    cin >> n;
    cout << "Введите координаты вектора" << endl;

    Vector <int> u(n); // создал класс-вектор. С целочисленными координатами
    for (int i = 0; i < n; i++) // вводим n-чисел
    {
        cin >> m; // каждый раз вводим новое число
        u.Set_coords(m, i); // Функция устанавливает m на i-тую позицию
    }

    double b1 = u.Get_size(); // получает длину вектора. 
    cout << "Длина вектора = " << b1 << endl;
    //
    //
    //
    cout << "Демонстрация работы с типом double" << endl;
    cout << "Введите размерность вещественнозначного вектора" << endl; 
    cin >> n;
    cout << "Введите координаты вектора" << endl;

    Vector <double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        a.Set_coords(d, i);
    }

    double b = a.Get_size();
    cout << "Длина вектора = " << b << endl;
    //
    //
    //
    cout << "Демонстрация работы с типом complex" << endl;
    cout << "Введите размерность вектора" << endl;
    cin >> m;
    Vector <Complex> f(m); // создается вектор, у которого все координаты все комплексные числа
    cout << "Введите координаты вектора" << endl;
    Complex z;
    int r, t;

    for (int i = 0; i < m; i++)
    {
        cout << "Введите 2 целых числа для координаты " << i << endl;
        cin >> r >> t;

        z.set_(r, t); // сформировалось комплексное число 
        f.Set_coords(z,i); // сформированное комплексное число кладём в определённую позицию
    }

    double e = f.Get_size();
    cout << "Вывод комплекснозначного вектора" << endl;
    for (int i = 0; i < m; i++)
        cout << f.Get_coords(i) << " ";
    cout << "Длина вектора = " << e << endl;
    
    return 0;
}