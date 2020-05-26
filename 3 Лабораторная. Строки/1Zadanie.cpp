#include <iostream>
#include <fstream>
using namespace std;

void f()
{
	setlocale(LC_ALL, "Russian");
	int k = 0;
	char c;
	cout << "Введите что-нибудь " << endl;
	c = getchar(); // считываем один символ и кладем его в c
	while (c != '\n') // если c не равен переносу строки, то работает счетчик
	{
		k++;
		c = getchar();
	}
	cout << k << endl;
}

int main()
{
	f();
	return 0;
}