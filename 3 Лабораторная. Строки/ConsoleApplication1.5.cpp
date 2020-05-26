#include <iostream>
using namespace std;

void copyfunc(char* S1, char* S2, int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (S2[i] == '\0')
			t = 1;
		if (S1[i] == '\0')
		{
			if (t == 1)
				S2[i] = '\0';
			break;
		}
		S2[i] = S1[i];
	}
	if (t == 1)
		S2[n] = '\0';
	t = 1;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	char* S1;
	char* S2;
	int n;
	
	char c;
	int i = 0;
	S1 = new char[100];
	S2 = new char[100];
	cout << "Введите первую строку" << endl;
	while ((c = getchar()) != '\n')
	{
		S1[i] = c;
			i++;
	}
	S1[i] = '\0';
	cout << "Введите вторую строку" << endl;
	i = 0;
	while ((c = getchar()) != '\n')
	{
		S2[i] = c;
			i++;
	}
	S2[i] = '\0';
	cout << "Введите число" << endl;
	cin >> n;
	copyfunc(S1, S2, n);
	cout << "Результат работы" << endl;
	i = 0;
	while (S2[i] != '\0')
	{
		cout << S2[i];
		i++;
	}
	return 0;
}