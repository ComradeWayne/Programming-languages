#include <iostream>
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;

int pow2(int N)
{
	if (N == 1) return 1;
	if (N % 2 == 0) return pow2(N / 2);
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "Введите натуральное число ";
	cin >> a;
	int l = pow2(a);
	if (l == 1)
		cout << "YES";
	else cout << "NO";
	return 0;
}