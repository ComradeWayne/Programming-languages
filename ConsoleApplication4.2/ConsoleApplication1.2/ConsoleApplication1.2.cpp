
#include <stdlib.h>
#include <fstream>
#include "stdio.h"
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	fstream file;
	file.open("file.txt");
	if (!file.is_open())
	{
		printf("error");
		return -1;
	}
	int n, m;
	file >> n;
	file >> m;
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
		a[i] = new int[m];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			file >> a[i][j];
	int** c = new int* [n];
	for (int i = 0; i < n; i++)
		c[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			file >> c[i][j];
	int* b = new int[m];
	for (int i = 0; i < m; i++)
		file >> b[i];
	int* d = new int[n];
	for (int i = 0; i < n; i++)
		file >> d[i];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			int d1;
			a[i][j] = 5 * a[i][j];
		}
	int** res = new int* [m];
	for (int i = 0; i < m; i++)
		res[i] = new int[m];
	int** res1 = new int* [m];
	for (int i = 0; i < m; i++)
		res1[i] = new int[n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res1[i][j] = b[i] * d[j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[i][j] = 0;
			for (int l = 0; l < n; l++)
				res[i][j] += res1[i][l] * c[l][j];
		}
	}
	cout << "Полученная матрица " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}