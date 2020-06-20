#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '
char matrix[3][3] =
{
	{SPACE, SPACE, SPACE}, // матрица самой игры
	{SPACE, SPACE, SPACE},
	{SPACE, SPACE, SPACE}
};
void computer_move(void), player_move(void);
void game_interface(void);
char check_win(void);

int main()
{
	setlocale(LC_ALL, "Russian");
	char done;
	done = SPACE;
	do {
		game_interface(); 
		player_move(); 
		done = check_win(); 
		if (done != SPACE) break; 
		computer_move(); 
		done = check_win();
	} while (done == SPACE);
	if (done == 'X') printf("Победа!\n");
	else printf("Вы проиграли.\n");
	game_interface();
	return 0;
}

void player_move(void) // ход игрока
{
	int x, z;
	printf("Введите координаты для вашего крестика.\n");
	printf("Ряд: ");
	scanf_s("%d", &x);
	printf("Колонка: ");
	scanf_s("%d", &z);
	x--;
	z--;
	if (x < 0 || z < 0 || x > 2 || z > 2 || matrix[x][z] != SPACE)
	{
		printf("Неверный ход, попробуйте еще раз.\n");
		player_move();
	}
	else matrix[x][z] = 'X';
}

void computer_move(void) // ход компьютера
{
	register int t;
	char* p;
	p = (char*)matrix;
	for (t = 0; *p != SPACE && t < 9; ++t) p++;
	if (t == 9)
	{
		printf("Ничья.\n");
		exit(0);
	}
	else *p = 'O';
}

void game_interface(void) // интерфейс игры
{
	int t;
	for (t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) printf("\n---|---|---\n");
	}
	printf("\n");
}

char check_win(void) // проверка на победу 
{
	int t;
	char* p;
	for (t = 0; t < 3; t++) { // проверка строк 
		p = &matrix[t][0];
		if (*p == *(p + 1) && *(p + 1) == *(p + 2)) return *p;
	}
	for (t = 0; t < 3; t++) { // проверка столбцов
		p = &matrix[0][t];
		if (*p == *(p + 3) && *(p + 3) == *(p + 6)) return *p;
	}

	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) // проверка диагоналей
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	return SPACE;
}