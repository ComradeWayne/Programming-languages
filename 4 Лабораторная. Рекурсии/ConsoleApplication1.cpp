#include <iostream>
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;

/*int recurse_factor(int n)
{
	int s;
	if (n == 1) return 1;
	else s = n * recurse_factor(n - 1);
	return s;
}*/

int factor(int n) // не рекурсивная
{
	int s = 1;
	for (int i = 1; i <= n; i++)
		s = s * i;
	return s;
}

int main()
{
	int a;
	setlocale(LC_ALL, "Russian");
	cout << "Введите натуральное число ";
	cin >> a;
	cout << "Факториал = " << factor(a) << endl;
	//cout << "Факториал = " << recurse_factor(a) << endl;
	return 0;
}