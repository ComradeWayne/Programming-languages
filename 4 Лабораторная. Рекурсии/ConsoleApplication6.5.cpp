#include <iostream>
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;

void f_g(long int n,long int &f,long int &g)
{
	if (n == 1)
	{
		f = 5;
		g = -5;
		cout << "f(" << n << ")=" << f << endl;
		cout << "g(" << n << ")=" << g << endl;
		return;
	}
	long int a, b;
	f_g(n - 1, a, b);
	f = a - b;
	g = a * b;
	cout << "f(" << n << ")=" << f << endl;
	cout << "g(" << n << ")=" << g << endl;
}

int main()
{
	long int a, b;
	setlocale(LC_ALL, "Russian");
	f_g(10, a, b);
	return 0;
}