#include <iostream>
using namespace std;

char** strfunc()
{
	char** article = new char* [3]; // создали 3 указателя на чары
	for (int i = 0; i < 3; i++)
	{
		article[i] = new char[10]; // кусок памяти, в который влезает 10 символов
		char c; 
		int j = 0;
		c = getchar(); // получить один символ
		while (c != '\n') 
		{
			article[i][j] = c;
			j++;
			c = getchar();
		}
		for (int k = j; k < 10; k++) // оставшиеся пустые символы заполняем пробелами
			article[i][k] = ' ';
	}
	return article; 
}



int main()
{
	setlocale(LC_ALL, "");
	char** article, ** verbs, ** nouns, ** pretext; //создаем 4 списка слов. список как указатель
	cout << "Введите три артикля через enter" << endl;
	article = strfunc();
	cout << "Введите три глагола через enter" << endl;
	verbs = strfunc(); // функция возвращает адрес на глагол
	cout << "Введите три существительных enter" << endl;
	nouns = strfunc();
	cout << "Введите три предлога через enter" << endl;
	pretext = strfunc();
	char* str = new char[100]; // выбор слов. массив из чаров в 100 символов
	int r = round(rand() * 1.0f / RAND_MAX * 2); // сокращаем диапазон от 0 до 2. целые числа
	int j = 0; // для складывания в строчку с пробелом
	for (int i = 0; i < 10; i++)
	{
		str[j] = article[r][i]; 
		j++;
		if (article[r][i] == ' ') 
		{
			break;
		}
	}
	r = round(rand() * 1.0f / RAND_MAX * 2);
	for (int i = 0; i < 10; i++)
	{
		str[j] = nouns[r][i]; // копируем слово, которое случайно появилось
		j++; // по ячейкам двигаемся вперед 
		if (nouns[r][i] == ' ') // копируем только буквы которые есть. как встретили пробел не копируем
		{
			break;
		}
	}
	r = round(rand() * 1.0f / RAND_MAX * 2);
	for (int i = 0; i < 10; i++)
	{
		str[j] = verbs[r][i];
		j++;
		if (verbs[r][i] == ' ')
		{
			break;
		}
	}
	r = round(rand() * 1.0f / RAND_MAX * 2);
	for (int i = 0; i < 10; i++)
	{
		str[j] = pretext[r][i];
		j++;
		if (pretext[r][i] == ' ')
		{
			break;
		}
	}
	r = round(rand() * 1.0f / RAND_MAX * 2);
	for (int i = 0; i < 10; i++)
	{
		str[j] = article[r][i];
		j++;
		if (article[r][i] == ' ')
		{
			break;
		}
	}
	r = round(rand() * 1.0f / RAND_MAX * 2);
	for (int i = 0; i < 10; i++)
	{
		str[j] = nouns[r][i];
		j++;
		if (nouns[r][i] == ' ')
		{
			break;
		}
	}
	str[0] = toupper(str[0]); // делаем первую букву заглавной
	
	str[j-1] = '.'; // присваевам точку, возвращаясь назад на один эелемент
	for (int i = 0; i < j; i++)
		cout << str[i]; // выводим предложение
	
	return 0;
}