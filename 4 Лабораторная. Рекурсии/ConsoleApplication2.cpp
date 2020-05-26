#include <iostream>
#include <fstream>
#include "stdio.h"
#include <time.h>
using namespace std;
const int N = 6;

int func1(int n)
{
	if (n == 1) return 3;
	return func1(n - 1) * (n - 1);
}
	

int main()
{
  setlocale(LC_ALL, "Russian");
  cout << func1(N) << endl;
  return 0;
}
