#include <iostream>
#include <fstream>
#include "stdio.h"
using namespace std;
// функция определения
int f(int n, int m)
{
	if (m == 1) return 1;
	if (n % m == 0) return 0;
	return f(n, m - 1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "Введите натуральное число ";
	cin >> a;
	if (a == 1)
		cout << "число ни простое, ни составное" << endl;
	else
	{
		if (f(a, (int)(sqrt(a))) == 0)
			cout << "число составное" << endl;
		else cout << "число простое" << endl;
	}
	return 0;
}